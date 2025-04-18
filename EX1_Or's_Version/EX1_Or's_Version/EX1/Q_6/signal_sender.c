#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void send_bit(pid_t pid, int bit) {
    
    int sig = bit ? SIGUSR2 : SIGUSR1;
    if (kill(pid, sig) == -1) {
        perror("Error sending signal");
        exit(1);
    }
    usleep(100000);
}

int main() {
    pid_t receiver_pid;
    int number;

    printf("Enter receiver PID: ");
    scanf("%d", &receiver_pid);

    printf("Enter message: ");
    scanf("%d", &number);

    if (number < 0 || number > 255) {
        printf("Invalid number.\n");
        return 1;
    }

    for (int i = 7; i >= 0; i--) {
        int bit = (number >> i) & 1;
        send_bit(receiver_pid, bit);
    }

    return 0;
}
