#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

// Swap = 3 assignments + function call
void swapRecords(Record *a, Record *b, unsigned long *steps) 
{
    Record temp = *a;
    *steps += 1; // temp = *a
    *a = *b;
    *steps += 1; // *a = *b
    *b = temp;
    *steps += 1; // *b = temp
    *steps += 1; // function call overhead
}

void merge(Record *arr, int left, int middle, int right, unsigned long *steps)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    *steps += 5; // assignments for i, j, k, n1, n2

    Record L[n1], R[n2];
    *steps += 2; // declaring temp arrays

    for (i = 0; i < n1; i++) {
        *steps += 1; // loop condition
        L[i] = arr[left + i];
        *steps += 1; // assignment
    }

    for (j = 0; j < n2; j++) {
        *steps += 1; // loop condition
        R[j] = arr[middle + 1 + j];
        *steps += 1; // assignment
    }

    i = 0; j = 0; k = left;
    *steps += 3; // assignments

    while (i < n1 && j < n2) {
        *steps += 1; // while condition
        *steps += 1; // if condition
        if (L[i].idNumber <= R[j].idNumber) {
            arr[k] = L[i];
            *steps += 1;
            i++;
            *steps += 1;
        } else {
            arr[k] = R[j];
            *steps += 1;
            j++;
            *steps += 1;
        }
        k++;
        *steps += 1;
    }

    while (i < n1) {
        *steps += 1; // while condition
        arr[k] = L[i];
        *steps += 1;
        i++;
        *steps += 1;
        k++;
        *steps += 1;
    }

    while (j < n2) {
        *steps += 1; // while condition
        arr[k] = R[j];
        *steps += 1;
        j++;
        *steps += 1;
        k++;
        *steps += 1;
    }
}

void insertionSort(Record *arr, int n, unsigned long *steps)
{
    int i, j;
    Record nKey;
    *steps += 1; // declaration of nKey (initialized later)

    for (i = 1; i < n; i++) {
        *steps += 1; // loop condition
        nKey = arr[i];
        *steps += 1; // assignment
        j = i - 1;
        *steps += 1; // assignment

        while (j >= 0 && arr[j].idNumber > nKey.idNumber) {
            *steps += 1; // while condition
            arr[j + 1] = arr[j];
            *steps += 1; // shift
            j--;
            *steps += 1;
        }

        arr[j + 1] = nKey;
        *steps += 1;
    }
}

void selectionSort(Record *arr, int n, unsigned long *steps)
{
    int i, j, idxLowest;
    *steps += 1; // declaration count 

    for (i = 0; i < n - 1; i++) {
        *steps += 1; // outer loop condition
        idxLowest = i;
        *steps += 1; // assignment

        for (j = i + 1; j < n; j++) {
            *steps += 1; // inner loop condition
            *steps += 1; // comparison
            if (arr[j].idNumber < arr[idxLowest].idNumber) {
                idxLowest = j;
                *steps += 1; // assignment
            }
        }

        *steps += 1; // if condition
        if (idxLowest != i) {
            swapRecords(&arr[i], &arr[idxLowest], steps); // already +4 inside
        }
    }
}

void mergeSort(Record *arr, int l, int r, unsigned long *steps)
{
    *steps += 1; // if condition check
    if (l < r) {
        int m = l + (r - l) / 2;
        *steps += 1; // assignment
        mergeSort(arr, l, m, steps);
        *steps += 1; // recursive call
        mergeSort(arr, m + 1, r, steps);
        *steps += 1; // recursive call
        merge(arr, l, m, r, steps);
        *steps += 1; // merge call
    }
}

void bubbleSort(Record *arr, int nSize, unsigned long *steps)
{
    int i, j;
    *steps += 2; // declarations

    for (i = 0; i < nSize; i++) {
        *steps += 1; // outer loop condition

        for (j = nSize - 1; j >= i + 1; j--) {
            *steps += 1; // inner loop condition
            *steps += 1; // if condition
            if (arr[j].idNumber < arr[j - 1].idNumber) {
                swapRecords(&arr[j], &arr[j - 1], steps); // already +4
            }
        }
    }
}

#endif
