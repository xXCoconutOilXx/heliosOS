#include "video.h"

#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Define the video memory address
volatile char* const video_memory = (volatile char*)VIDEO_MEMORY;

void print_char(char c, int x, int y) {
    if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) return;

    // Calculate position in video memory
    int pos = (y * SCREEN_WIDTH + x) * 2;
    video_memory[pos] = c;            // Character
    video_memory[pos + 1] = 0x07;     // Color (light grey on black)
}

void print_string(const char* str, int x, int y) {
    while (*str) {
        print_char(*str++, x++, y);
        if (x >= SCREEN_WIDTH) {
            x = 0;
            y++;
        }
    }
}
