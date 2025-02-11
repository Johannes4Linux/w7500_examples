# Setup Toolchain
CROSS_COMPILE := arm-none-eabi-

CC := $(CROSS_COMPILE)gcc
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy

# Source files
SRC := ../wiznet/source/system_w7500x.c \
       ../wiznet/source/w7500x_it.c \
       ../wiznet/source/w7500x_crg.c \
       ../wiznet/source/w7500x_gpio.c \
       main.c 

ASRC := ../wiznet/source/startup_w7500x.s 
OBJ := $(SRC:.c=.o) $(ASRC:.S=.o) 

INC := -I ../wiznet/include \
       -I ../wiznet/include/CMSIS 

CFLAGS := -g -O3 -mthumb -mcpu=cortex-m0 $(INC)
LDFLAGS := -T ../wiznet/linker/gcc_w7500x.ld -nostdlib 

NAME := blinky

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
