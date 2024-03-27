#include <iostream>
using namespace std;

// Tail recursion to calculate the sum of array elements
int tailRecursiveSumOfProg(int arr[], int size, int index = 0, int currentSum = 0) {
    if (index >= size) return currentSum;
    return tailRecursiveSumOfProg(arr, size, index + 1, currentSum + arr[index]);
}

// Linear recursion to calculate the sum of array elements
int linearRecursiveSumOfProg(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + linearRecursiveSumOfProg(arr, size - 1);
}


void merge(int arr[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int k = start;

    // Dynamically allocate memory for a temporary array
    int* temp = new int[end - start + 1];

    // Merge two subarrays into a temporary array
    while (i <= middle && j <= end) {
        if (arr[i] >= arr[j]) {
            temp[k - start] = arr[i];
            i++;
        }
        else {
            temp[k - start] = arr[j];
            j++;
        }
        k++;
    }

    // Add remaining elements of the first subarray, if any
    while (i <= middle) {
        temp[k - start] = arr[i];
        i++;
        k++;
    }

    // Add remaining elements of the second subarray, if any
    while (j <= end) {
        temp[k - start] = arr[j];
        j++;
        k++;
    }

    // Copy the contents of the temporary array back into the main array
    for (int p = start; p <= end; p++) {
        arr[p] = temp[p - start];
    }

    // Free the memory allocated for the temporary array
    delete[] temp;
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

int main() {
    setlocale(LC_ALL, "English");
    cout << "Merge Sort\n";
    int firstTerm, difference, N;

    cout << "Enter the first element of the array: ";
    cin >> firstTerm;

    cout << "Enter the difference: ";
    cin >> difference;

    cout << "Enter the size of the array (100 < N < 1000): ";
    cin >> N;

    // Checking the correctness of the entered data
    if (N <= 100 || N >= 1000) {
        cout << "Incorrect array size!" << endl;
        cin >> N;
    }

    int* myarr;
    myarr = new int[N];

    // Fill the array with members of the arithmetic progression
    for (int i = 0; i < N; ++i) {
        myarr[i] = firstTerm + i * difference;
    }
    cout << "\nInitial array\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    int summ = tailRecursiveSumOfProg(myarr, N);
    int summ2 = linearRecursiveSumOfProg(myarr, N);

    mergeSort(myarr, 0, N - 1);

    cout << "\nSorted array in reverse order\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << "\nSum of the arithmetic progression (Tail recursion)\n";
    cout << summ;
    cout << "\nSum of the arithmetic progression (Linear recursion)\n";
    cout << summ2;


    cout << "\n\nTask 3. Find the sum of the digits of a given natural number\n";
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    std::cout << "\nSum of the digits of the number: " << sum << std::endl;
}
