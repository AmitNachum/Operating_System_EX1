#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// This function runs a command through execvp in a child process.
// It sets up redirection using dup2 for input and output file descriptors.
void run_pipe(char *cmd[], int input_fd, int output_fd) {
    pid_t pid = fork();  // Create a new process
    if (pid == 0) {
        // Child process

        // Redirect stdin if needed
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }

        // Redirect stdout if needed
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        // Execute the command
        execvp(cmd[0], cmd);

        // If execvp fails
        perror("exec failed");
        exit(1);
    }
    // Parent process returns
}

int main(int argc, char *argv[]) {
    // Make sure user passed at least one name component
    if (argc < 2) {
        fprintf(stderr, "Usage: %s Name [Surname...]\n", argv[0]);
        exit(1);
    }

    // Calculate the total length needed for the full name string
    int total_len = 0;
    for (int i = 1; i < argc; i++) {
        total_len += strlen(argv[i]) + 1;  // Add space for space characters
    }

    // Allocate memory for the full name string
    char *fullname = malloc(total_len);
    if (!fullname) {
        perror("malloc");
        exit(1);
    }

    // Concatenate all name components into one string
    fullname[0] = '\0';
    for (int i = 1; i < argc; i++) {
        strcat(fullname, argv[i]);
        if (i < argc - 1)
            strcat(fullname, " ");
    }

    // Create 3 pipes for chaining the commands
    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    // First command: grep "fullname" phonebook.txt
    char *cmd1[] = {"grep", fullname, "phonebook.txt", NULL};
    run_pipe(cmd1, STDIN_FILENO, pipe1[1]);  // Output to pipe1
    close(pipe1[1]);  // Close write-end in parent

    // Second command: sed 's/ /#/g'
    char *cmd2[] = {"sed", "s/ /#/g", NULL};
    run_pipe(cmd2, pipe1[0], pipe2[1]);  // Input from pipe1, output to pipe2
    close(pipe1[0]);
    close(pipe2[1]);

    // Third command: sed 's/,/ /'
    char *cmd3[] = {"sed", "s/,/ /", NULL};
    run_pipe(cmd3, pipe2[0], pipe3[1]);  // Input from pipe2, output to pipe3
    close(pipe2[0]);
    close(pipe3[1]);

    // Fourth command: awk '{print $2}'
    char *cmd4[] = {"awk", "{print $2}", NULL};
    run_pipe(cmd4, pipe3[0], STDOUT_FILENO);  // Final output to stdout
    close(pipe3[0]);

    // Wait for all child processes to complete
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    // Free allocated memory
    free(fullname);

    return 0;
}
