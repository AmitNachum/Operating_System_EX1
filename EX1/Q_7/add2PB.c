#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // Check if the user provided arguments
        fprintf(stderr, "Usage: %s name,phone-number\n", argv[0]);
        return 1;
    }

    // Calculate total length of all arguments combined
    size_t total_len = 0;
    for (int i = 1; i < argc; i++) {
        total_len += strlen(argv[i]) + 1; // +1 for space or null terminator
    }

    // Allocate memory for the combined string
    char *entry = malloc(total_len);
    if (!entry) {
        perror("malloc");
        return 1;
    }

    entry[0] = '\0'; // Initialize the string

    // Concatenate all arguments into a single string
    for (int i = 1; i < argc; i++) {
        strcat(entry, argv[i]);
        // Add space between arguments unless it's the last one or ends with a comma
        if (i < argc - 1 && argv[i][strlen(argv[i]) - 1] != ',') {
            strcat(entry, " ");
        }
    }

    // Look for a comma to separate name from phone number
    char *comma = strchr(entry, ',');
    if (!comma) {
        fprintf(stderr, "Invalid format. Expected: \"Full Name,Phone-Number\"\n");
        free(entry);
        return 1;
    }

    // Open the file for appending
    FILE *file = fopen("phonebook.txt", "a");
    if (!file) {
        perror("fopen");
        free(entry);
        return 1;
    }

    // Write the entry to the file
    fprintf(file, "%s\n", entry);
    fclose(file);
    free(entry); // Free allocated memory

    return 0;
}
