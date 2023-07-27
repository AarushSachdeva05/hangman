#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 100

int main() {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int tries = 0;
    int word_length;
    int i, j, found;
    char guess;

    printf("Enter the word to be guessed (in lowercase): ");
    scanf("%s", word);

    word_length = strlen(word);
    for (i = 0; i < word_length; i++) {
        guessed[i] = '_';
    }
    guessed[i] = '\0';

    while (tries < MAX_TRIES && strcmp(word, guessed) != 0) {
        printf("\nWord: %s\n", guessed);
        printf("Tries left: %d\n", MAX_TRIES - tries);
        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        found = 0;
        for (j = 0; j < word_length; j++) {
            if (word[j] == guess) {
                guessed[j] = guess;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Incorrect guess!\n");
        }
    }

    if (strcmp(word, guessed) == 0) {
        printf("\nCongratulations! You guessed the word: %s\n", word);
    } else {
        printf("\nSorry, you ran out of tries. The word was: %s\n", word);
    }

    return 0;
}
