#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t bit_count = 0;
volatile sig_atomic_t number = 0;

void handle_signal(int sig) {
    number <<= 1;
    if (sig == SIGUSR2) {
        number |= 1;
    }
    bit_count++;
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handle_signal; 
    sigemptyset(&sa.sa_mask);     
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2); 
    sa.sa_flags = SA_RESTART;     

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("My PID is %d\n", getpid());

    while (bit_count < 8) {
        pause(); 
    }

    printf("Received %d\n", number);
    return 0;
}
