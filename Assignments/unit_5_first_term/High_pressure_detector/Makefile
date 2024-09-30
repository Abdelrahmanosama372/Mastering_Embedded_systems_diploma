#@copywrite : Abdelrahman

CC=arm-none-eabi-
CFLAGS=-g -gdwarf-2 -mcpu=cortex-m3 -mthumb
INSC=-I driver/ -I include/
LIBS= 
SRC=$(wildcard *.c driver/*.c src/*.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECT_NAME=Pressure_Controller

all : $(PROJECT_NAME).bin
	@echo "==============build end successfully=============="

%.o : %.c
	$(CC)gcc $(CFLAGS) $(INSC) -c $< -o $@

%.o : %.s
	$(CC)as  $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf : $(ASOBJ) $(OBJ)
	$(CC)ld   -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=map_file.map 
	cp $(PROJECT_NAME).elf  $(PROJECT_NAME).axf


$(PROJECT_NAME).bin : $(PROJECT_NAME).elf
	$(CC)objcopy -O binary $< $@ 

clean_all : 
	rm *.o *.elf *.bin */*.o */*.elf */*.bin
	@echo "==============cleaned successfully=============="

clean : 
	rm *.elf *.bin */*.elf */*.bin      #in case there is a change in linker script
	@echo "==============cleaned successfully=============="

help:
	@echo "Makefile Help"
	@echo ""
	@echo "Available targets:"
	@echo "  all          - Build the project and create a binary."
	@echo "  clean        - Clean up generated files (elf and bin)."
	@echo "  clean_all    - Remove all object, elf, and bin files."
	@echo "  help         - Show this help message."
	@echo ""
	@echo "Usage: make [target]"
	@echo "Replace [target] with one of the available targets."
