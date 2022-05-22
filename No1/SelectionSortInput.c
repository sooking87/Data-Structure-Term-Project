#include <stdio.h>
#define LENGTH 12

int main()
{
    int ArrL[12];
    int inputSize = 0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &ArrL[i]);
        inputSize++;
        for (int j = 0; j < inputSize; j++)
        {
            printf("ArrL[%d] = %d\n", j, ArrL[j]);
        }
    }
}