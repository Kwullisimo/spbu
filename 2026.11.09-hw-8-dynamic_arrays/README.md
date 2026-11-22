![Homework](https://github.com/user-attachments/assets/34e5c3bc-196a-4936-b733-c88c7209d3f5)

## ℹ️ Info

Two C programs that use dynamically allocated arrays. One sums the elements, and the other rotates the array by `k` positions.

## 📚 Tasks

| No. |               Task                | Status |                                                               Source                                                               |
| :-: | :-------------------------------: | :----: | :--------------------------------------------------------------------------------------------------------------------------------: |
|  1  |      Sum the array elements       |   ✅   |               [🔗](https://github.com/Kwullisimo/spbu/tree/main/2026.11.09-hw-8-dynamic_arrays/dynamic-array/main.c)               |
|  2  | Rotate the array by `k` positions |   ✅   | [🔗](<[./dynamic-shift/main.c](https://github.com/Kwullisimo/spbu/tree/main/2026.11.09-hw-8-dynamic_arrays/dynamic-shift/main.c)>) |

✅ Completed · ⏳ In progress · ❌ Not started

## ❗ Remarks

- **Sum.** The accumulator uses `long long` because the total can exceed the range of `int`. If only the sum is needed, values can be added as they are read without allocating an array.
- **Rotation.** Three reversals rotate the array in place. In `((k + n) % n + n) % n`, `k + n` can overflow `int`. The program uses `k %= n` first and adds `n` only if the remainder is negative.
- **Allocation.** `SIZE_MAX / sizeof(int)` gives the largest element count whose total size in bytes fits in `size_t`.

---

![Meme](https://i.pinimg.com/736x/db/28/99/db2899e842a265acaa720087e9d5fd0e.jpg)
