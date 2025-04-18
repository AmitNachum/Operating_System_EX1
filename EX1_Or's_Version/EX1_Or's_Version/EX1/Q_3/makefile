export LD_LIBRARY_PATH="/home/amit/Desktop/C-file Amit/Operating_Systems_Uni_EX/EX1/Q_3/ MendleBrotSet2.h:$LD_LIBRARY_PATH"
export LD_LIBRARY_PATH="/home/amit/Desktop/C-file Amit/Operating_Systems_Uni_EX/EX1/Q_3/ MendleBrotSet2.c:$LD_LIBRARY_PATH"



CC = gcc
CFLAGS = -Werror -g -I./ -fPIC 
SRC = sourceFile.c 
MAIN = mendleBrotSet2.c
LIBMANDLE = libmandlebrot.so
OBJ = $(SRC:.c=.o)
TARGET = Q_3_test

$(TARGET): $(OBJ) $(LIBMANDLE) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBMANDLE) -o $(TARGET) -L. -lmandlebrot -lm

$(LIBMANDLE): $(SRC)
	$(CC) $(CFLAGS) -shared $(SRC) -o $(LIBMANDLE) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	rm $(TARGET) $(OBJ) $(LIBMANDLE)
	

