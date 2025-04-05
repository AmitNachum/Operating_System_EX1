CC = gcc
CFLAGS =-g -fprofile-arcs -ftest-coverage
SRC = Dijkstra.c SPT.c
OBJ = $(SRC:.c=.o)
TARGET = Dijkstra

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

coverage: $(TARGET)
	./$(TARGET)
	gcov $(SRC)

show: coverage
	@echo "Generated coverage reports for:"
	@ls *.gcov


.PHONY:clean

clean:
	rm -f $(TARGET) $(OBJ) *.gcda *.gcno *.gcov

