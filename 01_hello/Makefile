# Setup Toolchain
CROSS_COMPILE := arm-none-eabi-

CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy

# Source files
SRC := ../wiznet/source/system_W7500x.c \
       ../wiznet/source/W7500x_it.c \
       main.c 

ASRC := ../wiznet/source/startup_W7500.S 
OBJ := $(SRC:.c=.o) $(ASRC:.S=.o) 

INC := -I ../wiznet/include \
       -I ../wiznet/include/CMSIS 

CFLAGS := -g -O3 -mthumb -mcpu=cortex-m0 $(INC)
LDFLAGS := -T ../wiznet/linker/gcc_W7500.ld -nostdlib 

NAME := hello

all: $(NAME).bin

$(NAME).bin: $(NAME).elf
	$(OBJCOPY) -O binary $< $@

$(NAME).elf: $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.S
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(NAME).bin $(NAME).elf $(OBJ)
