#include "video.h"
#include "idt.h"
#include "keyboard.h"
#include "shell.h"

void kernel_main(void) {
    // Initialize screen
    print_string("Helios OS Booted!\n", 0, 0);

    // Initialize interrupt handling
    idt_init();

    // Start the shell
    shell();
}
