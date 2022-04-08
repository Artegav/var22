#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 20

char* getS(int* len);
void printS(char arr[]);

int main()
{
    char* str;
    static char vowels[10];
    static char consonants[10];
    static char punctuation[10];
    static char digits[10];
    str = (char*)malloc(sizeof(char));

    int vow, con, pun, dig, i, len;
    vow = con = dig = pun = 0;

    do
    {
        printf("Enter a string no more than 20 symbols :\n\n");
        str = getS(&len);
        if (len > N) printf("Error, length of the string is more than 20\n\n");
        else if (len < 1) printf("Error, write at least 1 symbol\n\n");
    } while (len > N || len < 1);

    if ((str = (char*)realloc(str, sizeof(char) * len + 1)) == NULL)
    {
        printf("Memory allocation error. Program abort.\n");
        free(str);
        str = NULL;
        return 1;
    }
    
    fflush(stdin);

    for (i = 0; i < len; i++)
    {
        char ch = str[i];
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vowels[vow++] = ch;
            }
            else
            {
                consonants[con++] = ch;
            }
        }

        else if (isdigit(ch))
        {
            digits[dig++] = ch;
        }
        else if (ispunct(ch))
        {
            punctuation[pun++] = ch;
        }
    }

    printf("\nVowels: %d \n", vow);
    printS(vowels);
    printf(".\nConsonants: %d \n", con);
    printS(consonants);
    printf(".\nDigits: %d \n", dig);
    printS(digits);
    printf(".\nPunctuation: %d\n", pun);
    printS(punctuation);

    free(str);
    str = NULL;

    return 0;
}

void printS(char arr[])
{
    int i = 0;
    for (i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i]);
        if (arr[i + 1] != '\0') printf(", ");
    }
}

char* getS(int* len)
{
    *len = 0;                               // pôvodne reťazec je prázdny
    int capacity = 1;                       // kapacita kontajnera dynamického reťazca (1, pretože to bude určite '\ 0')
    char* s = (char*)malloc(sizeof(char)); // pridelenie pamäte pre dynamický prázdny reťazec

    char c = getchar(); // premenna pre čítanie

    // čítame znaky, kým nedostaneme nového riadku (\n)
    while (c != '\n')
    {
        s[(*len)++] = c; // do reťazca vložime nový znak

        // ak je skutočná veľkosť väčšia ako veľkosť kontajnera, zvýšime jeho veľkosť
        if (*len >= capacity)
        {
            capacity *= 2;                                   // zvýšenie kapacity reťazca dvakrát
            s = (char*)realloc(s, capacity * sizeof(char)); // vytvorenie nového reťazca so zvýšenou kapacitou
        }

        c = getchar(); // čítame dalši znak
    }

    s[*len] = '\0'; // ukončíme reťazec znakom konca riadku

    return s; // vrátenie ukazovateľa na načítaný reťazec
}
