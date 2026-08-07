#include <stdio.h>
#include <stdint.h>

#define BIT_SET(var, pos) ((var) |= (1UL << (pos))) // var = var | 1ul
#define BIT_CLEAR(var, pos) ((var) &= ~(1UL << (pos)))
#define BIT_TOGGLE(var, pos) ((var) ^= (1UL << (pos)))

int main(int argc, char const *argv[])
{
    uint32_t data = 0x12345678;
    // BIT_SET(data, 0);

    ((data) |= (1UL << (0)));

    return 0;
}
