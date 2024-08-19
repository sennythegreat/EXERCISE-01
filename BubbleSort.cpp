#include <iostream>
#include <iomanip>  // For setw
#include <chrono>   // For measuring time

using namespace std;
using namespace std::chrono;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    // Sort the array
    bubbleSort(arr, n);

    // Capture the end time
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the sorted array with setw for formatting
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(7) << arr[i] << " ";  // setw(5) for width of 5 characters per number
    }
    cout << endl;

    // Print the time taken to sort the array
    cout << "Time taken by bubble sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
