#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Description: This is the Make file for automaiong the build process in the 
# 2nd assignment of the course Introduction to Embedded Systems Software and 
# Development Environments from coursera.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.o --> compiles source files and generates the respective object file
#      <file>.asm --> generates the assembly file from the respective C file
#      <file>.i --> intermediate file is generated from the respective C file
#      compile-all --> compiles all the source files and gives objects files
#      build --> links the object files into one executable file
#      clean --> removes all the generated files.
#
# Platform Overrides:
#      HOST - Default platform
#      MSP342 - Target cross-compiled platform
#
# Author : Aluguri Akshith
# Date: 17-04-2022
#------------------------------------------------------------------------------

include sources.mk

# Common flags for both platforms.
CO_FLAGS =  -Wall -Werror -g -O0 -std=c99

BASENAME = c1m2
 
# Architectures Specific Flags
ifeq ($(PLATFORM), HOST)
	CPU = x86_64
	ARCH:=$(shell arch)

else
	LINKER_FILE = -T ../msp432p401r.lds 
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
endif 

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(BASENAME).map
	CFLAGS = $(CO_FLAGS)
	CPPFLAGs = -M -MF test2.d
	DEFINEFLAG = -DHOST
	SIZE = size
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(BASENAME).map $(LINKER_FILE) 
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb $(CO_FLAGS)
	CPPFLAGs = -M -MF test.d
	DEFINEFLAG = -DMSP432
	SIZE = arm-none-eabi-size 

endif

# More Declared Variables
OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)


%.i : %.c
	$(CC) $(CPPFLAGs) $(DEFINEFLAG) $<
	$(CC) $(DEFINEFLAG) -E -o $@ $<

%.asm : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -S $<
	objdump $(OBJS) -D

	
%.o : %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $<

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) -c $(SOURCES)

.PHONY: build
build: $(OUTS)

$(OUTS): $(SOURCES)
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o c1m2.out $^ 
	$(SIZE) c1m2.out


.PHONY: clean
clean:
	rm -f *.i *.d *.map *.s *.out *.o *.asm

