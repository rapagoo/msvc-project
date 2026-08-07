#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool is_little_endian();
uint32_t swap_endian(uint32_t val);

int main(int argc, char const *argv[])
{
    uint32_t network_data = 0x12345678;
    printf("=== Day 2: Endianness Conversion ===\r\n");
    printf("Received Data (Hex): %x\r\n", network_data);

    if (is_little_endian())
    {
        printf("[System Check] This system is Little Endian.\r\n");
        printf("-> Need to swap bytes to match Host Order.\r\n");
        uint32_t host_data = swap_endian(network_data);

        printf("Original (Network): %x\r\n", network_data);
        printf("Converted (Host)  : %x\r\n", host_data);

        uint8_t *ptr = (uint8_t *)&host_data;
        printf("Memory Dump : [%02x] [%02x] [%02x] [%02x] (Low Addr->High Addr)\r\n",
               ptr[0], ptr[1], ptr[2], ptr[3]);
    }

    return 0;
}

bool is_little_endian()
{
    uint16_t value = 1;
    uint8_t *ptr = (uint8_t *)&value;
    return ptr[0] == 1;
}

uint32_t swap_endian(uint32_t val)
{
    return ((val & 0x000000FF) << 24) |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0xFF000000) >> 24);
}