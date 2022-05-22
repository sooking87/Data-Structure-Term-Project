/* =========================================================================*/
/*
프로젝트명 : Project #1 :: Selection Sort using Array.
작성자 : IT공학전공_2116313_손수경
작성일 : 2022-05-19~2022-05-19
사용언어 : C언어
알고리즘 설명 :
리스트 구성 과정
    입력이 12개로 이루어진 정수형을 넣기 위해서 길이가 12인 배열을 사용하였습니다.
함수 설명
    -   void swap(int arr[], int length, int idx1, int idx2) : 배열 arr에서 인덱스가 idx1인 원소와 인덱스가 idx2인 원소를 바꾸어 줍니다.
    -   void SelectionSort(int arr[], int length) : 선택 정렬을 위한 함수입니다. 이중 for문을 돌리면서 바깥 for문에서의 인덱스를 비교를 위한 기준점이라고 했을 때, 안쪽 for문을 바깥 for문 인덱스 + 1부터 끝까지 비교를 하면서 최소값을 구합니다. 그 후, 기준점과 최소값의 위치를 바꾸어주는 선택 정렬 알고리즘이 적용된 함수입니다.
전체적인 함수 진행 구조
    -   1). 12개의 수를 입력을 받으면 SelectionSort()로 넘어가서 배열의 선택 정렬을 진행합니다. 교환이 발생했을 때마다 배열을 출력하라는 조건이 있었으므로 조건에 맞는 swap()을 만들었습니다.

참고한 알고리즘 : 과제 참고용 - 선택 정렬 pdf
도움을 준 동료 : 없음
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

    printf("\n교환 발생\n");
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
        // 최소 구하기
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
    int inputSize = 0; // 입력받은 만큼의 원소를 출력하기 위한 변수
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &ArrL[i]);
        inputSize++;
        printf("\n%d단계: \n", inputSize);
        for (int j = 0; j < inputSize; j++)
        {
            printf("ArrL[%d] = %d\n", j, ArrL[j]);
        }
    }

    SelectionSort(ArrL, LENGTH);

    int sum = 0;
    double avg;
    printf("최종 내림차순 정렬\n");
    for (int i = LENGTH - 1; i >= 0; i--)
    {
        printf("ArrL[%d] = %d\n", i, ArrL[i]);
        sum += ArrL[i];
    }
    avg = sum / (double)LENGTH;
    printf("배열 내 %d개의 원소 값의 합: %d\n", LENGTH, sum);
    printf("배열 내 %d개의 원소 값의 평균: %f\n", LENGTH, avg);
}
