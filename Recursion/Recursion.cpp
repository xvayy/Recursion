#include <iostream>
using namespace std;

// Linear recursion to calculate the sum of digits of a number(Task 3)
int sumOfDigits(int num) {
    if (num == 0)
        return 0;
    else
        return num % 10 + sumOfDigits(num / 10);
}


int sumOfProg(unsigned long long int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Tail recursion to calculate the sum of array elements (GEOMETRIC)
int tailRecursion(int a1, int r, int i) {
    if (i == 0)
        return a1;
    else
        return r * tailRecursion(a1, r, i - 1);
}

// Linear recursion to calculate the sum of array elements (ARITHMETIC)
int linearRecursion(int a1, int d, int i) {
    if (i == 0)
        return a1;
    else
        return d + linearRecursion(a1, d, i - 1);
}

int main() {
    setlocale(LC_ALL, "English");
    int firstTerm, difference, denominator, N, result1, result2;
    cout << "ARITHMETIC PROGRESSION\n";
    cout << "Enter the first element of the progression: ";
    cin >> firstTerm;

    cout << "Enter the difference: ";
    cin >> difference;

    cout << "Enter the size of the progression (100 < N < 1000): ";
    cin >> N;

    // Checking the correctness of the entered data
    if (N <= 100 || N >= 1000) {
        cout << "Incorrect progression size!" << endl;
        cin >> N;
    }

    unsigned long long int* myarr;
    myarr = new unsigned long long int[N];

    // Fill the array with members of the arithmetic progression()
    for (int i = 0; i < N; ++i) {
        myarr[i] = linearRecursion(firstTerm, difference, i);
    }
    cout << "\nArithmetic progression(Linear recursion)\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    result1 = sumOfProg(myarr, N);
    cout << "\nSum of arithmetic progression: " << result1;

    cout << "\n\nGEOMETRIC PROGRESSION\n";
    cout << "Enter the first element of the progression: ";
    cin >> firstTerm;
    if (firstTerm == 0) {
        while (firstTerm == 0) {
            cout << "First element can not be 0" << endl;
            cin >> firstTerm;
        }
    }

    cout << "Enter the denominator: ";
    cin >> denominator;

    if (denominator == 0) {
        while (denominator == 0) {
            cout << "Denominator can not be 0" << endl;
            cin >> denominator;
        }
    }

    cout << "Enter the size of the progression (2 < N < 32): ";
    cin >> N;

    if (N <= 2 || N >= 32) {
        cout << "Incorrect progression size!" << endl;
        cin >> N;
    }

    unsigned long long int* myarr2;
    myarr2 = new unsigned long long int[N];

    // Fill the array with members of the geometric progression()
    for (int i = 0; i < N; ++i) {
        myarr2[i] = tailRecursion(firstTerm, denominator, i);
    }
    cout << "\nGeometric progression (Tail recursion)\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr2[i] << " ";
    }

    result2 = sumOfProg(myarr2, N);
    cout << "\nSum of geometric progression: " << result2;

    cout << "\n\nTask 3. Find the sum of the digits of a given natural number\n";
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = sumOfDigits(num);

    cout << "\nSum of the digits of the number: " << sum << std::endl;
}
