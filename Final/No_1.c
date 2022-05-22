/* =========================================================================*/
/*
������Ʈ�� : Project #1 :: Selection Sort using Array.
�ۼ��� : IT��������_2116313_�ռ���
�ۼ��� : 2022-05-19~2022-05-19
����� : C���
�˰��� ���� :
����Ʈ ���� ����
    �Է��� 12���� �̷���� �������� �ֱ� ���ؼ� ���̰� 12�� �迭�� ����Ͽ����ϴ�.
�Լ� ����
    -   void swap(int arr[], int length, int idx1, int idx2) : �迭 arr���� �ε����� idx1�� ���ҿ� �ε����� idx2�� ���Ҹ� �ٲپ� �ݴϴ�.
    -   void SelectionSort(int arr[], int length) : ���� ������ ���� �Լ��Դϴ�. ���� for���� �����鼭 �ٱ� for�������� �ε����� �񱳸� ���� �������̶�� ���� ��, ���� for���� �ٱ� for�� �ε��� + 1���� ������ �񱳸� �ϸ鼭 �ּҰ��� ���մϴ�. �� ��, �������� �ּҰ��� ��ġ�� �ٲپ��ִ� ���� ���� �˰����� ����� �Լ��Դϴ�.
��ü���� �Լ� ���� ����
    -   1). 12���� ���� �Է��� ������ SelectionSort()�� �Ѿ�� �迭�� ���� ������ �����մϴ�. ��ȯ�� �߻����� ������ �迭�� ����϶�� ������ �־����Ƿ� ���ǿ� �´� swap()�� ��������ϴ�.

������ �˰��� : ���� ����� - ���� ���� pdf
������ �� ���� : ����
*/
/* =========================================================================*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
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
        // �ּ� ���ϱ�
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
    printf("I am Sohn Soo Kyoung\n");
    printf("This Project is No_1 :: Selection Sort using Array.\n");
    printf("Please Cheer Up ! Until 2022.05.23\n\n");

    int ArrL[12];
    int inputSize = 0; // �Է¹��� ��ŭ�� ���Ҹ� ����ϱ� ���� ����
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &ArrL[i]);
        inputSize++;
        printf("\n%d�ܰ�: \n", inputSize);
        for (int j = 0; j < inputSize; j++)
        {
            printf("ArrL[%d] = %d\n", j, ArrL[j]);
        }
    }

    SelectionSort(ArrL, LENGTH);

    int sum = 0;
    double avg;
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
