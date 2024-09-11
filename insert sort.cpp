#include <iostream>
#include <chrono>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

/* Function to generate an array in reverse order (worst case) */
void generateWorstCase(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i;
    }
}

int main()
{
    int n = 10000; // You can adjust this value for larger arrays
    int* arr = new int[n];

    generateWorstCase(arr, n);

    // Measure time taken by insertionSort
    auto start = chrono::high_resolution_clock::now();
    
    insertionSort(arr, n);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    
    cout << "Time taken by Insertion Sort for worst case (array size " << n << "): " 
         << elapsed.count() << " seconds" << endl;
    
    // Uncomment the line below to print the sorted array
    // printArray(arr, n);

    delete[] arr;
    return 0;
}