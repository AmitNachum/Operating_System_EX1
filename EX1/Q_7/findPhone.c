#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Run a command using execvp in a child process with redirection
void run_pipe(char *cmd[], int input_fd, int output_fd) {
    pid_t pid = fork();
    if (pid == 0) {
        // Redirect input if needed
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        // Redirect output if needed
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }
        // Execute the command
        execvp(cmd[0], cmd);
        perror("exec failed");
        exit(1);
    }
    // Parent does nothing here
}

int main(int argc, char *argv[]) {
    // Make sure name is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s Name\n", argv[0]);
        exit(1);
    }

    // Use only argv[1] as the name to search
    char *name = argv[1];

    // Set up pipes
    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    // grep "name" phonebook.txt
    char *cmd1[] = {"grep", name, "phonebook.txt", NULL};
    run_pipe(cmd1, STDIN_FILENO, pipe1[1]);
    close(pipe1[1]);

    // sed 's/ /#/g' → replace spaces with #
    char *cmd2[] = {"sed", "s/ /#/g", NULL};
    run_pipe(cmd2, pipe1[0], pipe2[1]);
    close(pipe1[0]);
    close(pipe2[1]);

    // sed 's/,/ /' → replace comma with space
    char *cmd3[] = {"sed", "s/,/ /", NULL};
    run_pipe(cmd3, pipe2[0], pipe3[1]);
    close(pipe2[0]);
    close(pipe3[1]);

    // awk '{print $2}' → print the second field (the phone number)
    char *cmd4[] = {"awk", "{print $2}", NULL};
    run_pipe(cmd4, pipe3[0], STDOUT_FILENO);
    close(pipe3[0]);

    // Wait for all child processes to finish
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}
