CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGETS = add2PB findPhone

all: $(TARGETS)

add2PB: add2PB.c
	$(CC) $(CFLAGS) -o $@ $<

findPhone: findPhone.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
