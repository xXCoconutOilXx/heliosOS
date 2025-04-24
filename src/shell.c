#include "shell.h"
#include "video.h"

void shell(void) {
    print_string("Welcome to Helios Shell!\n", 0, 0);
    print_string("> ", 0, 2);

    char input[100];
    int i = 0;

    while (1) {
        char c = get_char_from_user();
        if (c == '\n') {
            input[i] = '\0';
            print_string(input, 0, 4);
            i = 0; // Reset input buffer
        } else {
            input[i++] = c;
            print_char(c, 2 + i, 2);
        }
    }
}

char get_char_from_user(void) {
    // This is a placeholder function. You can implement actual keyboard reading logic here
    return 'A';  // Just returning a dummy character for testing
}
