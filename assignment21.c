#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    // Open source file in read mode
    source = fopen("source.txt", "r");

    // Check if source file exists
    if (source == NULL) {
        printf("Error: Source file not found!\n");
        return 1;
    }

    // Open destination file in write mode
    destination = fopen("destination.txt", "w");

    // Check if destination file opened successfully
    if (destination == NULL) {
        printf("Error: Cannot create destination file!\n");
        fclose(source);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(source);
    fclose(destination);

    return 0;
}
