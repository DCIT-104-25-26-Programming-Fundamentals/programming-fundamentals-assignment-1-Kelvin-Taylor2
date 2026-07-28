// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// =============================================================================

#include <iostream>
using namespace std;

// Function prototypes
int computeSum(int arr[], int n);
double computeAverage(int arr[], int n);
int findMaximum(int arr[], int n);
int findMinimum(int arr[], int n);

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    int numbers[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int sum = computeSum(numbers, n);
    double average = computeAverage(numbers, n);
    int max = findMaximum(numbers, n);
    int min = findMinimum(numbers, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;

    return 0;
}

int computeSum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

double computeAverage(int arr[], int n) {
    int total = computeSum(arr, n);
    return (double)total / n;
}

int findMaximum(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMinimum(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

