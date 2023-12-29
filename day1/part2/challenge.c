#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// the idea is to read 5 characters at a time and stop if you find a number
int string_to_int(char StringNumber[])
{

    int i = 0;
    bool isNumber = false;
    char one_nine_string[10] = "one";

    printf("%c", one_nine_string);

    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 1;
    }

    i = 0;
    strcpy(one_nine_string, "two");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 2;
    }

    i = 0;
    strcpy(one_nine_string, "three");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 3;
    }

    i = 0;
    strcpy(one_nine_string, "four ");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 4;
    }
    i = 0;
    strcpy(one_nine_string, "five");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 5;
    }
    i = 0;
    strcpy(one_nine_string, "six");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 6;
    }
    i = 0;
    strcpy(one_nine_string, "seven");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 7;
    }
    i = 0;
    strcpy(one_nine_string, "eight");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 8;
    }
    i = 0;
    strcpy(one_nine_string, "nine");
    while (i < strlen(one_nine_string) && one_nine_string[i] == StringNumber[i])
    {
        i++;
    }
    if (i == strlen(one_nine_string))
    {
        isNumber = true;
        return 9;
    }
    return -1;
}

void get_first_digit(char File_Line[], int *fin, int *j)
{

    int i = 0, k, firstDigit;
    char String_int[10];

    while (i < strlen(File_Line) && File_Line[i] != '\n')
    {

        j = i;
        k = 0;
        while (j < i + 5)
        {

            if (isdigit(File_Line[*j]) == false)
            {

                String_int[k] = File_Line[j];

                printf("%s\n", String_int);

                if (string_to_int(String_int) != -1)
                {

                    firstDigit = string_to_int(String_int);
                    *fin = i;
                }
                j++;
                k++;
            }
            else
            {
                return File_Line[j] - '0';
                *fin = i;
            }
        }
        i++;
    }
    *fin = i;
}

int get_last_digit(char File_Line[], int start_search)
{

    int last_digit;
    int i = start_search, j, k;
    char String_int[20];

    while (i < strlen(File_Line) && File_Line[i] != '\n')
    {
        printf("im coucle 1");
        j = i;
        k = 0;
        while (j < i + 5)
        {
            printf("im boucle 2");

            if (isdigit(File_Line[j]) == false)
            {

                String_int[k] = File_Line[j];

                printf("%s\n", String_int);

                if (string_to_int(String_int) != -1)
                {

                    last_digit = string_to_int(String_int);
                }
            }
            else
            {
                // he finds a numerical value
                last_digit = File_Line[j] - '0';
            }
            j++;
            k++;
        }
        i++;
    }
    return last_digit;
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("CalibrationDOC_2.txt", "r+");

    char File_Line[30];
    int fin;
    fgets(File_Line, 40, fp);
    printf("the last digit is %d", get_last_digit(File_Line, 1));

    return 0;
}
