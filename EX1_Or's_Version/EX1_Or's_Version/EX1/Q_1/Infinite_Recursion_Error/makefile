CC = gcc
CFLAGS = -g 
SRC = recursion_Exception.c
OBJ = $(SRC:.c=.o)
TARGET = crash

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	rm $(TARGET) $(OBJ)
	
