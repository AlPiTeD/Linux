// https://hackmd.io/@sysprog/linux2023-summer-quiz0
// https://hackmd.io/@sysprog/c-bitwise
// https://hackmd.io/@sysprog/c-memory

#include <stdint.h>

// 對齊記憶體對應的位址，使其大於等於給定的 alignment
static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;  // 計算 alignment 的掩碼，即二進位中最低的 alignment 位為 1，其餘位為 0
    if ((alignment & mask) == 0) {   // 檢查 alignment 是否為 2 的冪次方，如果是，可以使用位元運算進行對齊
        return (sz + alignment - 1) & ~(mask);  // 使用位元運算，將 sz 加上 alignment - 1，然後將掩碼的位取反，再進行按位與運算，實現對齊
    }
    // 如果 alignment 不是 2 的冪次方，則使用算術運算進行對齊
    return (((sz + mask) / alignment) * alignment);  // 將 sz 加上 mask，然後除以 alignment，再乘以 alignment，實現對齊
}