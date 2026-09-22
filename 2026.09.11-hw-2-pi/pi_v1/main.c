#include <assert.h>
#include <stdio.h>

// ================================
// SOLUTION FROM CODEX ASTRA 6 ULRA
// ================================

/*
 * Pi from two converging means: the Gauss-Legendre (Brent-Salamin) algorithm.
 * No floating point, external libraries, or hard-coded digits of pi.
 * Reference: https://maths-people.anu.edu.au/~brent/pub/pub028.html
 *
 * All real values are represented as integers scaled by 10^PRECISION.
 * Full products need twice as many digits; GUARD digits protect rounding.
 */
enum {
    DECIMALS = 100,
    GUARD = 20,
    PRECISION = DECIMALS + GUARD,
    CAPACITY = 2 * PRECISION + 16,
    ITERATIONS = 8
};

typedef struct {
    unsigned char digit[CAPACITY]; /* Decimal digits, least significant first. */
    int length;
} Big;

static Big big_uint(unsigned value)
{
    Big result = {{0}, 0};
    do {
        result.digit[result.length++] = (unsigned char)(value % 10);
        value /= 10;
    } while (value != 0);
    return result;
}

static void normalize(Big *value)
{
    while (value->length > 1 && value->digit[value->length - 1] == 0)
        --value->length;
}

static int big_compare(Big a, Big b)
{
    if (a.length != b.length)
        return a.length > b.length ? 1 : -1;
    for (int i = a.length - 1; i >= 0; --i) {
        if (a.digit[i] != b.digit[i])
            return a.digit[i] > b.digit[i] ? 1 : -1;
    }
    return 0;
}

static Big big_add(Big a, Big b)
{
    Big result = {{0}, 1};
    unsigned carry = 0;
    result.length = a.length > b.length ? a.length : b.length;
    for (int i = 0; i < result.length; ++i) {
        unsigned sum = a.digit[i] + b.digit[i] + carry;
        result.digit[i] = (unsigned char)(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0) {
        assert(result.length < CAPACITY);
        result.digit[result.length++] = (unsigned char)carry;
    }
    return result;
}

static Big big_subtract(Big a, Big b)
{
    assert(big_compare(a, b) >= 0);
    int borrow = 0;
    for (int i = 0; i < a.length; ++i) {
        int difference = a.digit[i] - b.digit[i] - borrow;
        borrow = difference < 0;
        a.digit[i] = (unsigned char)(difference + 10 * borrow);
    }
    normalize(&a);
    return a;
}

static Big big_multiply(Big a, Big b)
{
    Big result = {{0}, 1};
    assert(a.length + b.length <= CAPACITY);
    result.length = a.length + b.length;
    for (int i = 0; i < a.length; ++i) {
        unsigned carry = 0;
        for (int j = 0; j < b.length; ++j) {
            unsigned product = result.digit[i + j]
                + (unsigned)a.digit[i] * b.digit[j] + carry;
            result.digit[i + j] = (unsigned char)(product % 10);
            carry = product / 10;
        }
        result.digit[i + b.length] = (unsigned char)carry;
    }
    normalize(&result);
    return result;
}

static Big big_times(Big value, unsigned factor)
{
    return big_multiply(value, big_uint(factor));
}

static Big big_divide_small(Big value, unsigned divisor)
{
    assert(divisor != 0);
    unsigned remainder = 0;
    for (int i = value.length - 1; i >= 0; --i) {
        unsigned current = 10 * remainder + value.digit[i];
        value.digit[i] = (unsigned char)(current / divisor);
        remainder = current % divisor;
    }
    normalize(&value);
    return value;
}

/* Integer division by 10^places: discard the least significant digits. */
static Big big_drop(Big value, int places)
{
    Big result = {{0}, 1};
    assert(places >= 0);
    if (places >= value.length)
        return result;
    result.length = value.length - places;
    for (int i = 0; i < result.length; ++i)
        result.digit[i] = value.digit[i + places];
    return result;
}

/* Long division; at most nine subtractions for each quotient digit. */
static Big big_divide(Big dividend, Big divisor)
{
    Big quotient = {{0}, 1};
    Big remainder = big_uint(0);
    assert(big_compare(divisor, big_uint(0)) > 0);
    quotient.length = dividend.length;
    for (int i = dividend.length - 1; i >= 0; --i) {
        remainder = big_add(big_times(remainder, 10),
                            big_uint(dividend.digit[i]));
        while (big_compare(remainder, divisor) >= 0) {
            remainder = big_subtract(remainder, divisor);
            ++quotient.digit[i];
        }
    }
    normalize(&quotient);
    return quotient;
}

/*
 * Integer square root by the pencil-and-paper method, two digits at a time.
 * Appending digit x to root r adds (20*r + x)*x to 100*r*r.
 */
static Big big_sqrt(Big value)
{
    Big root = big_uint(0);
    Big remainder = big_uint(0);
    for (int pair = (value.length - 1) / 2; pair >= 0; --pair) {
        unsigned next = value.digit[2 * pair];
        if (2 * pair + 1 < value.length)
            next += 10u * value.digit[2 * pair + 1];
        remainder = big_add(big_times(remainder, 100), big_uint(next));

        Big twenty_root = big_times(root, 20);
        Big trial;
        unsigned digit = 9;
        for (;;) {
            trial = big_times(big_add(twenty_root, big_uint(digit)), digit);
            if (big_compare(trial, remainder) <= 0)
                break;
            --digit;
        }
        remainder = big_subtract(remainder, trial);
        root = big_add(big_times(root, 10), big_uint(digit));
    }
    return root;
}

int main(void)
{
    Big scale = {{0}, PRECISION + 1};
    scale.digit[PRECISION] = 1;

    Big a = scale; /* a = 1 */
    Big b = big_sqrt(big_divide_small(big_multiply(scale, scale), 2));
    Big t = big_divide_small(scale, 4); /* t = 1/4 */
    unsigned p = 1;

    for (int step = 0; step < ITERATIONS; ++step) {
        Big next_a = big_divide_small(big_add(a, b), 2);
        Big next_b = big_sqrt(big_multiply(a, b));
        Big delta = big_subtract(a, next_a);

        /* t -= p * (a - next_a)^2; restore the scale after squaring. */
        Big correction = big_drop(big_times(big_multiply(delta, delta), p),
                                  PRECISION);
        t = big_subtract(t, correction);
        a = next_a;
        b = next_b;
        p *= 2;
    }

    /* pi = (a + b)^2 / (4*t); the quotient already has scale 10^PRECISION. */
    Big sum = big_add(a, b);
    Big pi = big_divide(big_multiply(sum, sum), big_times(t, 4));

    /* Round to exactly 100 fractional digits, preserving the trailing zero. */
    Big rounded = big_drop(pi, GUARD);
    if (pi.digit[GUARD - 1] >= 5)
        rounded = big_add(rounded, big_uint(1));

    for (int i = rounded.length - 1; i >= 0; --i) {
        putchar('0' + rounded.digit[i]);
        if (i == DECIMALS)
            putchar('.');
    }
    putchar('\n');
    return 0;
}
