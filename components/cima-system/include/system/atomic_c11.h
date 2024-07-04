#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* GCC documentation refers to the types as I1, I2, I4, I8, I16 */
typedef uint8_t  I1;
typedef uint16_t I2;
typedef uint32_t I4;
typedef uint64_t I8;

I4 __atomic_fetch_add_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_fetch_sub_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_fetch_and_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_fetch_or_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_fetch_xor_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_fetch_nand_4(I4 *ptr, I4 val, int memmodel);

I4 __atomic_add_fetch_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_sub_fetch_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_and_fetch_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_or_fetch_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_xor_fetch_4(I4 *ptr, I4 val, int memmodel);
I4 __atomic_nand_fetch_4(I4 *ptr, I4 val, int memmodel);
