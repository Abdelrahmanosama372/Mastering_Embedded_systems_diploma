#@copywrite : Abdelrahman

CC=arm-none-eabi-
CFLAGS=-g -gdwarf-2 -mcpu=cortex-m3 -mthumb
INSC=-I .
LIBS= 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECT_NAME=led_toggling

all : $(PROJECT_NAME).bin
	@echo "==============build end successfully=============="

%.o : %.c
	$(CC)gcc.exe     $(CFLAGS) $(INSC) -c $< -o $@

%.o : %.s
	$(CC)as.exe      $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf : $(ASOBJ) $(OBJ)
	$(CC)ld.exe      -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=map_file.map


$(PROJECT_NAME).bin : $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@ 

clean_all : 
	rm *.o *.elf *.bin
	@echo "==============cleaned successfully=============="

clean : 
	rm *.elf *.bin       #in case there is a change in linker script
	@echo "==============cleaned successfully=============="


# two none convention rules added by me

#to collect all .c files in one file calles SRC
SRC_FILES :              
	mkdir "SRC"
	mv *.c SRC  
	@echo "==============moving of source files ends successfully=============="

#to collect all .o files in one file calles OBJ
OBJ_FILES :
	mkdir "OBJ"
	mv *.o OBJ
	@echo "==============moving of object files ends successfully=============="
