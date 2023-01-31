// Mehmet Feyyaz Küçük 22003550

#include <iostream>
#include <ctime>
using namespace std;

// Helper function
int binarySearch(int *arr, int left, int right, int val) {
    if (right >= left) {
        int mid = (left + right) / 2;

        if (arr[mid] == val) {
            return 1;
        }

        if (arr[mid] > val) {
            return binarySearch(arr, left, mid - 1, val);
        }

        return binarySearch(arr, mid + 1, right, val);
    }

    return 0;
}

int algorithm1(int *arr1, int n, int *arr2, int m) {
    bool isFound;
    for (int i = 0; i < m; i++) {
        isFound = false;

        for (int j = 0; j < n; j++) {
            if (arr1[j] == arr2[i]) {
                isFound = true;
            }
        }

        if (!isFound) {
            return 0;
        }
    }

    return 1;
}   

int algorithm2(int *arr1, int n, int *arr2, int m) {
    bool isFound;
    for (int i = 0; i < m; i++) {
        isFound = binarySearch(arr1, arr1[0], arr1[n - 1], arr2[i]);

        if (!isFound) {
            return 0;
        }
    }

    return 1;
}

int algorithm3(int *arr1, int n, int *arr2, int m) {
    int max = 0;

    // Construct the frequency array.
    for (int i = 0; i < n; i++) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }

    int *frequencyArr = new int[max];

    for (int i = 0; i < n; i++) {
        frequencyArr[arr1[i] - 1] = 0;
        frequencyArr[arr1[i] - 1]++;
    }

    for (int i = 0; i < m; i++) {
        if (frequencyArr[arr2[i] - 1] > 0) {
            frequencyArr[arr2[i] - 1]--;
        }
        else {
            return 0;
        }
    }

    delete [] frequencyArr;

    return 1;
}

int main() {

    // Create the arrays
    int n = 20000000;
    int m = 100000;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    for (int i = 0; i < n; i++) {
        arr1[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        arr2[i] = i + 2;
    }

    // Compute the time complexities
    double duration;
    clock_t startTime = clock();

    for (int k = 0; k < 100; k++)
        algorithm2(arr1, n, arr2, m);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    // Delete arrays
    delete [] arr1;
    delete [] arr2;

    return 0;
}