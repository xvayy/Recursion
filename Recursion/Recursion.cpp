#include <iostream>
using namespace std;

// Хвостова рекурсія для обчислення суми елементів масиву
int tailRecursiveSumOfProg(int arr[], int size, int index = 0, int currentSum = 0) {
    if (index >= size) return currentSum;
    return tailRecursiveSumOfProg(arr, size, index + 1, currentSum + arr[index]);
}

// Лінійна рекурсія для обчислення суми елементів масиву
int linearRecursiveSumOfProg(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + linearRecursiveSumOfProg(arr, size - 1);
}


void merge(int arr[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int k = start;

    // Динамічно виділяємо пам'ять для тимчасового масиву
    int* temp = new int[end - start + 1];

    // Об'єднуємо два підмасиви в тимчасовий масив
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

    // Додаємо залишкові елементи першого підмасиву, якщо такі є
    while (i <= middle) {
        temp[k - start] = arr[i];
        i++;
        k++;
    }

    // Додаємо залишкові елементи другого підмасиву, якщо такі є
    while (j <= end) {
        temp[k - start] = arr[j];
        j++;
        k++;
    }

    // Копіюємо вміст тимчасового масиву назад у головний масив
    for (int p = start; p <= end; p++) {
        arr[p] = temp[p - start];
    }

    // Звільняємо пам'ять, виділену для тимчасового масиву
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
    setlocale(LC_ALL, "Ukrainian");
    cout << "Сортування злиттям\n";
    int firstTerm, difference, N;

    cout << "Введіть перший елемент масиву: ";
    cin >> firstTerm;

    cout << "Введіть різницю: ";
    cin >> difference;

    cout << "Введіть розмір масиву (100 < N < 1000): ";
    cin >> N;

    // Перевірка правильності введених даних
    if (N <= 100 || N >= 1000) {
        cout << "Неправильний розмір масиву!" << endl;
        cin >> N;
    }

    int* myarr;
    myarr = new int[N];

    // Заповнюємо масив членами арифметичної прогресії
    for (int i = 0; i < N; ++i) {
        myarr[i] = firstTerm + i * difference;
    }
    cout << "\nПочатковий масив\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    int summ = tailRecursiveSumOfProg(myarr, N);
    int summ2 = linearRecursiveSumOfProg(myarr, N);

    mergeSort(myarr, 0, N - 1);

    cout << "\nВідсортований масив у зворотньому порядку\n";
    for (int i = 0; i < N; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << "\nСума арифметичної прогресії (Хвостова рекурсія)\n";
    cout << summ;
    cout << "\nСума арифметичної прогресії (Лінійна рекурсія)\n";
    cout << summ2;


    cout << "\n\nЗавдання 3. Знайти суму цифр заданого натурального числа\n";
    int num;
    std::cout << "Введіть число: ";
    std::cin >> num;
 
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    std::cout << "\nСума цифр числа: " << sum << std::endl;
}
