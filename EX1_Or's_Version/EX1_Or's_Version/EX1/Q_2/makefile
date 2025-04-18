CC = gcc
CFLAGS = -Werror -g 
LINKMATH = -lm
SRC = imaginary_mandlebrot.c
OBJ = $(SRC:.c=.o)
TARGET = mendleSet

TARGET: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(TARGET) $(LINKMATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	rm $(TARGET) $(OBJ)
	
