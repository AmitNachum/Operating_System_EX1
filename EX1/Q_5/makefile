CC = gcc
CFLAGS = -g -Wall -pg
SRC = MA.c
OBJ = $(SRC:.c=.o)
TARGET = MaxSum

all: gprof


$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(TARGET)



gprof: $(TARGET)
	./$(TARGET) 42 10000
	gprof $(TARGET) gmon.out > report.txt
	cat report.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ) gmon.out report.txt	