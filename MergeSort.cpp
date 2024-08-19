#include <iostream>
#include <iomanip>  // For setw
#include <chrono>   // For measuring time

using namespace std;
using namespace std::chrono;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    const int MAX_SIZE = 10000; // Define the maximum size
    int arr[MAX_SIZE];
    int n;

    cout << "Enter the number of elements (up to " << MAX_SIZE << "): ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "The number of elements exceeds the maximum allowed size of " << MAX_SIZE << "." << endl;
        return 1;
    }

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Capture the start time
    auto start = high_resolution_clock::now();

    // Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    // Capture the end time
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the sorted array with setw for formatting
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arr[i] << " ";  // setw(5) for width of 5 characters per number
    }
    cout << endl;

    // Print the time taken to sort the array
    cout << "Time taken by merge sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
