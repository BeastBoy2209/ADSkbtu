#include <iostream>
#include <vector>

using namespace std;

// Функция для восстановления кучи (heapify) поддерева с корневым узлом i
// n - размер кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;   // Левый дочерний элемент
    int right = 2 * i + 2;  // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше наибольшего элемента
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Заменяем элементы
        heapify(arr, n, largest);    // Рекурсивно heapify для затронутого поддерева
    }
}

// Основная функция для выполнения сортировки кучей
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построить макс-кучу (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец массива
        swap(arr[0], arr[i]);

        // Восстанавливаем кучу на уменьшенной части массива
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива на экран
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}