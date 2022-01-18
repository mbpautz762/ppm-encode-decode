# Matthew Pautz
# CPSC 2311 001
# mpautz@clemson.edu
# makefile for programming assignment 1

CC=gcc
CFLAGS= -Wall -g
TARGET=pa1
INPUTFILE=testimage.ppm
OUTPUTFILE=output.ppm
LINKER= -lm

C_SRCS :=driver.c ppm.c EncodeDecode.c util.c 
HDRS :=EncodeDecode.h ppm.h utils.h
OBJS :=driver.o ppm.o EncodeDecode.o util.o 

add: build
	@echo "Done."

build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# special build rule
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET) $(INPUTFILE) $(OUTPUTFILE)

leakcheck: 
	valgrind --leak-check=yes --track-origins=yes ./$(TARGET) $(INPUTFILE) $(OUTPUTFILE)

clean:
	rm $(TARGET) $(OBJS) $(OUTPUTFILE)