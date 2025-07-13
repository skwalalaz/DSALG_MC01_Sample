#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void swapRecords(Record *a, Record *b, unsigned long *steps) 
{
    Record temp;
    temp = *a;
    (*steps)++;
    *a = *b;
    (*steps)++;
    *b = temp;
    (*steps)++;
}

void merge(Record *arr, int left, int middle, int right, unsigned long *steps)
{
    int i = 0;
    (*steps)++;
    int j = 0;
    (*steps)++;
    int k = left;
    (*steps)++;
    int n1 = middle - left + 1;
    (*steps)++;
    int n2 = right - middle;
    (*steps)++;

    Record L[n1], R[n2];
    (*steps)++;

    for (i = 0; i < n1; i++) {
        (*steps)++;
        L[i] = arr[left + i];
        (*steps)++;
    }

    for (j = 0; j < n2; j++) {
        (*steps)++;
        R[j] = arr[middle + 1 + j];
        (*steps)++;
    }

    i = 0;
    (*steps)++;
    j = 0;
    (*steps)++;

    while (i < n1 && j < n2) 
    {
        (*steps)++;
        if (L[i].idNumber <= R[j].idNumber) {
            arr[k] = L[i];
            (*steps)++;
            i++;
            (*steps)++;
        } else {
            arr[k] = R[j];
            (*steps)++;
            j++;
            (*steps)++;
        }
        k++;
        (*steps)++;
    }

    while (i < n1) {
        (*steps)++;
        arr[k] = L[i];
        (*steps)++;
        i++;
        (*steps)++;
        k++;
        (*steps)++;
    }

    while (j < n2) {
        (*steps)++;
        arr[k] = R[j];
        (*steps)++;
        j++;
        (*steps)++;
        k++;
        (*steps)++;
    }
}

void insertionSort(Record *arr, int n, unsigned long *steps)
{
    int i, j;
    Record nKey;

    for (i = 1 ; i < n ; i++)
    {
        (*steps)++;
        nKey = arr[i];
        (*steps)++;
        j = i - 1;
        (*steps)++;

        while (j >= 0 && arr[j].idNumber > nKey.idNumber)
        {
            (*steps)++;
            arr[j + 1] = arr[j];
            (*steps)++;
            j = j - 1;
            (*steps)++;
        }

        arr[j + 1] = nKey;
        (*steps)++;
    }
}

void selectionSort(Record *arr, int n, unsigned long *steps)
{
    int idxCurrent;
    int idxLowest;
    int i, j;

    for(i = 0; i < n; i++) {
        (*steps)++;
        idxLowest = i;
        (*steps)++;

        for(j = i+1; j < n; j++) {
            (*steps)++;
            idxCurrent = j;
            (*steps)++;
            if (arr[idxLowest].idNumber > arr[idxCurrent].idNumber) {
                (*steps)++;
                idxLowest = idxCurrent;
                (*steps)++;
            }
        }

        if (idxLowest != i) {
            (*steps)++;
            swapRecords(&arr[i], &arr[idxLowest], steps);
            (*steps)++;
        } 
    }
}

void mergeSort(Record *arr, int l, int r, unsigned long *steps)
{
    int m;

    if (l < r) {
        (*steps)++;
        m = l + (r - l) / 2;
        (*steps)++;
        mergeSort(arr, l, m, steps);
        (*steps)++;
        mergeSort(arr, m + 1, r, steps);
        (*steps)++;
        merge(arr, l, m, r, steps);
        (*steps)++;
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/
void bubbleSort(Record *arr, int nSize, unsigned long *steps)
{
    int i, j;

    for (i = 0 ; i < nSize ; i++)
    {
        (*steps)++;
        for (j = nSize - 1 ; j >= i + 1 ; j--)
        {
            (*steps)++;
            if (arr[j].idNumber < arr[j - 1].idNumber)
            {
                (*steps)++;
                swapRecords(&arr[j], &arr[j - 1], steps);
                (*steps)++;
            }
        }
    }
}


#endif
