#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("CalibrationDOC.txt", "r+");

    char line[100];
    char Char;
    int Total = 0, num = 0, Multiple10 = 1, firstDigit, lastDigit = -1;

    Char = fgetc(fp);

    while (feof(fp) == 0)
    {
        // get the first char
        while (isdigit(Char) != true && feof(fp) == 0)
        {
            Char = fgetc(fp);
        }
        firstDigit = Char - '0';

        // get the last digit
        Char = fgetc(fp);
        while (Char != '\n' && feof(fp) == 0)
        {
            if (isdigit(Char) == true)
            {
                lastDigit = Char - '0';
            }
            Char = fgetc(fp);
        }

        if (lastDigit == -1)
        {
            num = firstDigit + 10 * firstDigit;
        }
        else
        {
            num = lastDigit + 10 * firstDigit;
        }
        printf("the num is %d\n ", num);
        Total = Total + num;
        printf("the total is %d\n", Total);
        // reseting all the infrmations
        num = 0;
        lastDigit = -1;
        firstDigit = 0;
        Char = fgetc(fp);
    }

    printf("\nthe total is %d", Total);
    return 0;
}
