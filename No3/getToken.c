#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "apple, banana, carrot";
    char del[] = ",";
    char *result;
    char parsing[3][16];
    int i = 0;

    result = strtok(str, del);

    while (result != NULL)
    {
        strcpy(parsing[i++], result);
        result = strtok(NULL, del);
    }

    for (i = 0; i < 3; i++)
    {
        printf("%d : %s\n", i, parsing[i]);
    }

    char funtion[] = " (4+3)*((2+5)/(9-7))*2-3";
    char d[] = "()*/+-";
    char *r;
    char p[10][10];
    int j = 0;

    r = strtok(funtion, d);

    while (r != NULL)
    {
        strcpy(p[j++], r);
        r = strtok(NULL, d); //이전 구분자 뒤에서부터 다시 구분자를 찾는다.
    }

    for (j = 0; j < 5; j++)
    {
        if (p[j] == "")
        {
            continue;
        }
        printf("%d: %s\n", j, p[j]);
    }
}