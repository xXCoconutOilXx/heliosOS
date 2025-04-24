#include "keyboard.h"
#include "video.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

void keyboard_handler(void) {
    unsigned char scancode = inb(KEYBOARD_DATA_PORT); // Read the scancode

    if (scancode == 0x1E) { // 'A' key pressed (just an example)
        print_string("A", 0, 1);
    }
}

unsigned char inb(unsigned short port) {
    unsigned char result;
    asm volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}
