#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void swapRecords(Record *a, Record *b) 
{
    Record temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void merge(Record *arr, int left, int middle, int right, long *steps)
{
    int i = 0, j = 0, k = left;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Record L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;

    while (i < n1 && j < n2) 
    {
        (*steps)++; // comparison in merging
        if (L[i].idNumber <= R[j].idNumber) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*steps)++; // copying leftover
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*steps)++; // copying leftover
    }
}

void insertionSort(Record *arr, int n, long *steps)
{
    int i, j;
    Record nKey;

    for (i = 1 ; i < n ; i++)
    {
        (*steps)++; // for loop iteration
        nKey = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].idNumber > nKey.idNumber)
        {
            (*steps)++; // comparison and shift
            arr[j + 1] = arr[j]; // shift
            j--;
        }

        arr[j + 1] = nKey;
    }
}

void selectionSort(Record *arr, int n, long *steps)
{
    int idxCurrent;
    int idxLowest;
    int i, j;

    for(i = 0; i < n; i++) {
        (*steps)++; // outer loop iteration
        idxLowest = i;

        for(j = i+1; j < n; j++) {
            (*steps)++; // comparison in inner loop
            idxCurrent = j;
            if (arr[idxLowest].idNumber > arr[idxCurrent].idNumber) {
                idxLowest = idxCurrent;
            }
        }

        if (idxLowest != i) {
            swapRecords(&arr[i], &arr[idxLowest]);
            (*steps)++; // swap
        } 
    }
}

void mergeSort(Record *arr, int l, int r, long *steps)
{
    int m;

    if (l < r) {
        (*steps)++; // recursive call step
        m = l + (r - l) / 2;
        mergeSort(arr, l, m, steps);
        mergeSort(arr, m + 1, r, steps);
        merge(arr, l, m, r, steps);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/
void bubbleSort(Record *arr, int nSize, long *steps)
{
    int i, j;

    for (i = 0 ; i < nSize ; i++)
    {
        (*steps)++; // outer loop
        for (j = nSize - 1 ; j >= i + 1 ; j--)
        {
            (*steps)++; // comparison
            if (arr[j].idNumber < arr[j - 1].idNumber)
            {
                swapRecords(&arr[j], &arr[j - 1]);
                (*steps)++; // swap
            }
        }
    }
}


#endif