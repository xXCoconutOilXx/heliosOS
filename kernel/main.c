#include <stdint.h>

#define MULTIBOOT_MAGIC 0xE85250D2
#define MULTIBOOT_FLAGS 0x00000000
#define MULTIBOOT_CHECKSUM -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

// Declare the Multiboot header section
__attribute__((section(".multiboot")))
uint32_t multiboot_header[] = {
    MULTIBOOT_MAGIC,
    MULTIBOOT_FLAGS,
    MULTIBOOT_CHECKSUM
};

#define VIDEO_MEMORY 0xB8000

// Struct for each character's properties
struct terminal {
    unsigned char character;
    unsigned char attribute;
};

// Terminal screen buffer
volatile struct terminal* terminal = (volatile struct terminal*)VIDEO_MEMORY;

void clear_screen() {
    for (int i = 0; i < 80 * 25; i++) {
        terminal[i].character = ' ';
        terminal[i].attribute = 0x07; // White text on black background
    }
}

void put_char(char c) {
    static int cursor_position = 0;
    terminal[cursor_position].character = c;
    terminal[cursor_position].attribute = 0x07;
    cursor_position++;

    // Simple wrapping logic (scrolling down)
    if (cursor_position >= 80 * 25) {
        cursor_position = 0;
    }
}

// Kernel entry point
void kernel_main() {
    // Set up a basic stack (very important!) - Inline assembly
    asm volatile ("mov $0x90000, %esp");

    // Initialize the screen, print a message, etc.
    clear_screen();  // Call the clear screen function from earlier
    put_char('H');
    put_char('e');
    put_char('l');
    put_char('l');
    put_char('o');
    put_char(' ');
    put_char('H');
    put_char('e');
    put_char('l');
    put_char('i');
    put_char('o');
    put_char('s');
    while (1);  // Keep the kernel running forever
}
