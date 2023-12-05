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

void get_first_digit(char File_Line[], int *first_digit, int *i, int *j)
{

    int k;
    char String_int[10];

    while (*i < strlen(File_Line) && File_Line[*i] != '\n')
    {

        *j = *i;
        k = 0;
        while (*j < *i + 5)
        {

            if (isdigit(File_Line[*j]) == false)
            {

                String_int[k] = File_Line[*j];

                printf("%s\n", String_int);

                if (string_to_int(String_int) != -1)
                {

                    *first_digit = string_to_int(String_int);
                    return;
                }
                *j++;
                k++;
            }
            else
            {
                *first_digit = File_Line[*j] - '0';
                return;
            }
        }
        *i++;
    }
}

int get_last_digit(FILE *fp, char File_Line[])
{
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("CalibrationDOC_2.txt", "r+");

    char File_Line[30];
    int first_digit, last_digit, i = 0, j = 0;
    fgets(File_Line, 40, fp);
    get_first_digit(File_Line, &first_digit, &i, &j);
    printf("the number is %d\n", first_digit);

    return 0;
}
