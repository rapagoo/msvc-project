#include "uart_win.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

static HANDLE hStdout = INVALID_HANDLE_VALUE;
static HANDLE hStdin = INVALID_HANDLE_VALUE;

bool uartInit(void)
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    if (hStdout != INVALID_HANDLE_VALUE)
    {
        DWORD mode = 0;
        GetConsoleMode(hStdout, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT;
        SetConsoleMode(hStdout, mode);
    }

    return true;
}

int uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
    DWORD written = 0;
    if (hStdout != INVALID_HANDLE_VALUE)
    {
        WriteConsoleA(hStdout, p_data, (DWORD)length, &written, NULL);
    }
    else
    {
        fwrite(p_data, 1, length, stdout);
        fflush(stdout);
        written = (DWORD)length;
    }

    return (int)written;
}

bool uartReadBlock(uint8_t ch, uint8_t *p_data, uint32_t timeout)
{
    if (rx_pop(p_data))
    {
        return true;
    }
    int c = _getch();
    if (c == 0x00 || c == 0xE0)
    {
        int key = _getch();
        rx_push('\x1B');
        rx_push('[');
        switch (key)
        {
        case 72:
            rx_push('A');
            break; // up
        case 80:
            rx_push('B');
            break; // down
        case 77:
            rx_push('C');
            break; // right
        case 75:
            rx_push('D');
            break; // left
        default:
            break;
        }
        return rx_pop(p_data);
    }
    else
    {
        *p_data = (uint8_t)c;
        return true;
    }

    return false;
}
