# Makefile for Helios OS

CC = i686-elf-gcc
AS = i686-elf-as
LD = i686-elf-ld
CFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-pic  # Add -fno-pic to prevent position-independent code
LDFLAGS = -T linker.ld

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
KERNEL = $(BUILD_DIR)/kernel.o
BOOT = $(BUILD_DIR)/boot.o
OUTPUT = helios.iso

# List of all C source files
SRC = $(SRC_DIR)/kernel.c $(SRC_DIR)/video.c $(SRC_DIR)/keyboard.c $(SRC_DIR)/idt.c $(SRC_DIR)/shell.c

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJ) $(BUILD_DIR)/boot.o
	$(LD) $(LDFLAGS) $(OBJ) $(BUILD_DIR)/boot.o -o $(BUILD_DIR)/kernel.bin
	$(GRUB2) $(BUILD_DIR)/kernel.bin $(OUTPUT)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/boot.o: $(SRC_DIR)/boot.s
	$(AS) --32 $(SRC_DIR)/boot.s -o $(BUILD_DIR)/boot.o

clean:
	rm -rf $(BUILD_DIR)/* $(OUTPUT)

run: $(OUTPUT)
	qemu-system-i386 -cdrom $(OUTPUT)
