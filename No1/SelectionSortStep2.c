#include <stdio.h>
#define LENGTH 12

void swap(int arr[], int length, int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;

    printf("\n��ȯ �߻�\n");
    for (int j = 0; j < length; j++)
    {
        printf("ArrL[%d] = %d\n", j, arr[j]);
    }
}

void SelectionSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr, LENGTH, i, minIdx);
    }
}

int main()
{
    int ArrL[12];
    int inputSize = 0;
    int sum = 0;
    double avg;
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &ArrL[i]);
        inputSize++;
        for (int j = 0; j < inputSize; j++)
        {
            printf("ArrL[%d] = %d\n", j, ArrL[j]);
        }
    }

    SelectionSort(ArrL, LENGTH);

    printf("���� �������� ����\n");
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        printf("ArrL[%d] = %d\n", i, ArrL[i]);
        sum += ArrL[i];
    }
    avg = sum / (double)LENGTH;
    printf("�迭 �� %d���� ���� ���� ��: %d\n", LENGTH, sum);
    printf("�迭 �� %d���� ���� ���� ���: %f\n", LENGTH, avg);
}