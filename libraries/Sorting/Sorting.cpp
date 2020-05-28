#include "Sorting.h"

void sorting_functions::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sorting_functions::swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sorting_functions::quicksort(int array[], int left, int right)
{
    // Base case: No need to sort arrays of length <= 1
    if (left >= right)
    {
        return;
    }

    // Choose pivot to be the last element in the subarray
    int pivot = array[right];

    // Index indicating the "split" between elements smaller than pivot and
    // elements greater than pivot
    int split_idx = left;

    // Traverse through array from left to right
    for (int ii = left; ii <= right; ii++)
    {
        // If an element less than or equal to the pivot is found...
        if (array[ii] <= pivot)
        {
            // Then swap array[split_idx] and array[ii] so that the smaller element array[ii]
            // is to the left of all elements greater than pivot
            swap(&array[split_idx], &array[ii]);

            // Make sure to increment split_idx so we can keep track of what to swap
            // array[ii] with
            split_idx++;
        }
    }

    // NOTE: split_idx is currently at one plus the pivot's index
    // (Hence, the split_idx-2 when recursively sorting the left side of pivot)
    quicksort(array, left, split_idx - 2); // Recursively sort the left side of pivot
    quicksort(array, split_idx, right);    // Recursively sort the right side of pivot
}
void sorting_functions::quicksort(float array[], int left, int right)
{
    // Base case: No need to sort arrays of length <= 1
    if (left >= right)
    {
        return;
    }

    // Choose pivot to be the last element in the subarray
    float pivot = array[right];

    // Index indicating the "split" between elements smaller than pivot and
    // elements greater than pivot
    int split_idx = left;

    // Traverse through array from left to right
    for (int ii = left; ii <= right; ii++)
    {
        // If an element less than or equal to the pivot is found...
        if (array[ii] <= pivot)
        {
            // Then swap array[split_idx] and array[ii] so that the smaller element array[ii]
            // is to the left of all elements greater than pivot
            swap(&array[split_idx], &array[ii]);

            // Make sure to increment split_idx so we can keep track of what to swap
            // array[ii] with
            split_idx++;
        }
    }

    // NOTE: split_idx is currently at one plus the pivot's index
    // (Hence, the split_idx-2 when recursively sorting the left side of pivot)
    quicksort(array, left, split_idx - 2); // Recursively sort the left side of pivot
    quicksort(array, split_idx, right);    // Recursively sort the right side of pivots
}