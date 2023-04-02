#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char message[100];
    int key;

    printf("Enter the message to encrypt:");
    fgets(message, 100, stdin);

    printf("Enter key:");
    scanf("%d", &key);

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

    printf("Encrypted message: %s", message);
    return 0;
}