#pragma once

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int Partition(T A[], int begin, int end)
{
    int Rbegin = begin;
    for (int Ubegin = begin; Ubegin <= end - 1; ++Ubegin)
    {
        if (A[Ubegin] <= A[end])
        {
            swap(A[Ubegin], A[Rbegin]);
            ++Rbegin;
        }
    }

    swap(A[Rbegin], A[end]);
    return Rbegin;
}

template <typename T>
int PartitionReadable(T A[], int begin, int end)
{
    int pivot = end;

    // The beginning index of R group is immediately next to the index of "Lend".
    // Since the "Lend" equals to begin - 1 technically, "Rbegin" has to equal
    // to begin. The statement is not technically true. It is necessary for the
    // first update to correct this fault. As a result of this fault, the first
    // if-clause may swap element with itself.
    int Rbegin = begin;

    int Ubegin = begin;
    int Uend   = pivot - 1;
    for (; Ubegin <= Uend; ++Ubegin)
    {
        // After if-clause the begin index of U group would increment
        if (A[Ubegin] <= A[pivot])
        {
            swap(A[Ubegin], A[Rbegin]);

            // Move begin index of R group to the left because the size of L
            // group increase, pushing R group to the right. The swapped
            // A[Ubegin] value fails into R group. As a result index of "Uend"
            // would increment but we don't need that variable.
            ++Rbegin;
        }

        // Otherwise the A[Ubegin] should be in R group and since it always at
        // the edge between R group and U group, we can only increment the
        // index of "Rend". As we don't the "Rend" variable here, we don't have
        // to do anything.
    }

    swap(A[Rbegin], A[pivot]);

    // The pivot position is now at index "Rbegin"
    pivot = Rbegin;

    return pivot;
}

template <typename T>
void QuickSort(T A[], int begin, int end)
{
    // At most 1 element in [begin, end], so there is nothing to sort
    if (begin >= end)
    {
        return;
    }

    int pivot = Partition(A, begin, end);
    QuickSort(A, begin, pivot - 1);
    QuickSort(A, pivot + 1, end);
}