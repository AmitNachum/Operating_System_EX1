CC = gcc
CFLAGS = -Wall -Wextra
TARGETS = signal_sender signal_receiver

all: $(TARGETS)

signal_sender: signal_sender.c
	$(CC) $(CFLAGS) -o $@ $<

signal_receiver: signal_receiver.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)


