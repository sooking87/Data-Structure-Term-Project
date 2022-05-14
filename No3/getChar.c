#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "abcdefu";
    int len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        printf("%c\n", string[i]);
    }
}