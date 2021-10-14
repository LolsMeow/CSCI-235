/****************************************************************************************************************************
Title          :   Sorter.cpp
Auhor          :   Nigel Ferrer
Modified By    :   ** Jiaming Zheng **
Description    :   implementation file of an integer array container class that 
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.cpp
****************************************************************************************************************************/

#include "Sorter.hpp"
using namespace std;

Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr)
{
}

/***************************s* Selection Sort ****************************/
template <typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp)
{
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (comp(arr[i], arr[min_or_max]))
        {
            min_or_max = i;
        }
    }
    return min_or_max;
}

template <typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp)
{
    for (int i = 0; i < size; i++)
    {
        // Find the position of the minimum
        int min_pos = getPosOfMinOrMax(arr, i, static_cast<int>(size - 1),comp);
        if(comp(arr[min_pos], arr[i]))
        {
            selectionCount_ ++; //Increment count by one when swap is possible
        }
        // Swap the next element and the minimum
        std::swap(arr[min_pos], arr[i]);
    }


    return selectionCount_;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}
/************************************************************************/

/**************************** Insertion Sort ****************************/
template <typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp)
{
    for (int i = 1; i < size; i++)
    {
        int next = arr[i];
        // Move all larger elements up
        int j = i;
        while (j > 0 && comp(next, arr[j - 1]))
        {
            arr[j] = arr[j - 1];
            j--;
            insertionCount_++; //Increment count by one when swap is possible
        }
        // Insert the element
        arr[j] = next;
    }

    return insertionCount_;
}
/************************************************************************/

// /****************************** Merge Sort ******************************/
template <typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp)
{
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to)
    {
        if (comp(arr[i1], arr[i2]))
        {
            temp_array[j] = arr[i1];
            i1++;
        }
        else
        {
            temp_array[j] = arr[i2];
            i2++;
        }
        mergeCount_++; //Increment count by one when swap is possible
        j++;
    }


    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid)
    {
        temp_array[j] = arr[i1];
        mergeCount_++;
        i1++;
        j++;
    }
    // Copy any remaining entries of the second half
    while (i2 <= to)
    {
        temp_array[j] = arr[i2];
        mergeCount_++;
        i2++;
        j++;
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++)
    {
        arr[from + j] = temp_array[j];
    }

    delete[] temp_array;
}

template <typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp)
{
    if (from == to) { return 0; }
    int mid = (from + to) / 2;
    // Recursively sort the first and the second half
    mergeSort(arr, from, mid,comp);
    mergeSort(arr, mid + 1, to,comp);
    merge(arr, from, mid, to,comp);


    return mergeCount_;
}
// /************************************************************************/

void Sorter::runSorts(sort_order order)
{

    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];

    if (type_ == RANDOM)
    {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
        }
    }

    else
    {
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING)
    {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    }
    else
    {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING)
    {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    }
    else
    {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

    // Merge Sort Display
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING)
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    }
    else
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";


}

void Sorter::displayArr(const int array[]) const
{
    for (size_t i = 0; i < SIZE_; i++)
    {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}