#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s name,phone-number\n", argv[0]);
        return 1;
    }

    // create 1 string from all the arguments
    size_t total_len = 0;
    for (int i = 1; i < argc; i++) {
        total_len += strlen(argv[i]) + 1;
    }

    char *entry = malloc(total_len);
    if (!entry) {
        perror("malloc");
        return 1;
    }

    entry[0] = '\0';
    for (int i = 1; i < argc; i++) {
        strcat(entry, argv[i]);
        if (i < argc - 1)
            strcat(entry, " ");
    }

    // find the ","
    char *comma = strchr(entry, ',');
    if (!comma) {
        fprintf(stderr, "Invalid format. Expected: \"Full Name,Phone-Number\"\n");
        free(entry);
        return 1;
    }

    FILE *file = fopen("phonebook.txt", "a");
    if (!file) {
        perror("fopen");
        free(entry);
        return 1;
    }

    fprintf(file, "%s\n", entry);
    fclose(file);
    free(entry);

    return 0;
}
