#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void printArray(int[], int);

int main()
{
    FILE *arquivo;
    int i=0, temp;
    int arr[50000];
    double time_taken;
    clock_t begin, end;

    arquivo = fopen("ap.txt", "r");

    if (arquivo == NULL){
        printf("Could not open file %s", arquivo);
        return 1;
    }

    while (fscanf(arquivo, "%d", &temp) > 0)
    {
        arr[i] = temp;
        i++;
    }

    begin = clock();
    mergeSort(arr, 0, 50000 - 1);
    end = clock();

    time_taken = (double)(end-begin)/CLOCKS_PER_SEC; // in seconds
    printf("mergeSort took %f seconds to execute \n", time_taken);

    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}



