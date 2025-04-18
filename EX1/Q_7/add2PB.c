#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // Check if the user provided arguments
        fprintf(stderr, "Usage: %s name,phone-number\n", argv[0]);
        return 1;
    }

    // Calculate total length of all arguments combined
    size_t total_len = 0;
    for (int i = 1; i < argc; i++)
    {
        char *iter = argv[i];
        size_t ith_size = 0;
        while (*iter != '\0')
        {
            ith_size++;
            iter++;
        }
        total_len += ith_size;
    }
    

    // Allocate memory for the combined string
    char *entry = malloc(total_len + 1);
    if (!entry) {
        perror("malloc");
        return 1;
    }

    
    char *iter = entry;

    // Concatenate all arguments into a single string
     for(int i = 1 ; i < argc ; i++){
        char *ith_iter = argv[i];

        while(*ith_iter != '\0'){
            *iter = *ith_iter;
             iter++;
             ith_iter++;
        }
        
     }
     entry[total_len] = '\0';

    // Look for a comma to separate name from phone number
    char *comma = entry;
    int indicator = 0;

    while(*comma != '\0'){
        if (*comma ==','){
            indicator = 1;
            break;
        }
        comma++;
    }

    if (indicator == 0){
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
