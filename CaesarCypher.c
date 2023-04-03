#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LEN 256
#define MAX_SYMBOLS_MESSAGE 10000

int main()
{
    char input_filename[MAX_FILENAME_LEN];
    char output_filename[MAX_FILENAME_LEN];
    char message[MAX_SYMBOLS_MESSAGE];
    int key;

    printf("Enter the input file: ");
    fgets(input_filename, MAX_FILENAME_LEN, stdin);
    input_filename[strcspn(input_filename, "\n")] = '\0';

    printf("Enter the output file: ");
    fgets(output_filename, MAX_FILENAME_LEN, stdin);
    output_filename[strcspn(output_filename, "\n")] = '\0';

    printf("Enter key:");
    scanf("%d", &key);

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        printf("Can't read this file! ERROR %s", input_filename);
        return 1;
    };

    FILE *output_file = fopen(output_filename, "wt");
    if (output_file == NULL)
    {
        printf("Can't write this file! ERROR %s", output_filename);
        fclose(input_file);
        return 1;

        if (fgets(message, MAX_SYMBOLS_MESSAGE, input_file) == NULL)
        {
            printf("Failed to read input file!\n");
            fclose(input_file);
            fclose(output_file);

            return 1;
        };
    };

    while (fgets(message, MAX_SYMBOLS_MESSAGE, input_file) != NULL)
    {
        for (size_t i = 0; i < strlen(message); i++)
        {
            if (!isalpha(message[i]))
            {
                continue;
            };
            int letter_number = toupper(message[i]) - 'A';
            int encrypted_letter_number = (letter_number + key) % 26;
            char encrypted_letter = encrypted_letter_number + 'A';
            message[i] = islower(message[i]) ? tolower(encrypted_letter) : encrypted_letter;
        };

        if (fprintf(output_file, "%s", message) < 0)
        {
            printf("Failed to write output file\n");
            fclose(input_file);
            fclose(output_file);

            return 1;
        }
    };

    fclose(input_file);
    fclose(output_file);

    printf("Encrypted message: %s\n", output_filename);
    return 0;
}