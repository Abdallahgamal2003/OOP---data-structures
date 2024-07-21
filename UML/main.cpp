#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Sorter {
public:
    virtual void Sort(int arr[], int size) {
    }

    virtual ~Sorter() = default;
};

class Testbed {
private:
    int *arr = nullptr;
public:
    Testbed() = default;

    explicit Testbed(int s) {
        arr = new int[s];
    }

    int *generateRandomList(int min, int max, int size) {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
            arr[i] = rand() % (max - min + 1) + min;
        return arr;
    }

    int *generateReverseOrderedList(int min, int max, int size) {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
            arr[i] = rand() % (max - min + 1) + min;
        sort(arr, arr + size, greater<int>());
        return arr;
    }

    void runOnce(Sorter *sorter, int min, int max, int size) {
        auto start = high_resolution_clock::now();
        sorter->Sort(generateRandomList(min, max, size), size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nIt took: " << duration.count() << " Microseconds\n";
    }

    void runAndAverage(Sorter *sorter, const string &type, int min, int max, int size, int sets_num) {
        auto start = high_resolution_clock::now();
        if (type == "random") {
            for (int i = 0; i < sets_num; i++)
                sorter->Sort(generateRandomList(min, max, size), size);
        } else if (type == "reverse") {
            for (int i = 0; i < sets_num; i++)
                sorter->Sort(generateReverseOrderedList(min, max, size), size);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Average = " << (duration.count() / sets_num) << " Microseconds";
    }

    void runExperient(Sorter *sorter, const string &type, int min, int max, int min_val, int max_val, int sets_num,
                      int step) {
        for (int currentSize = min_val; currentSize <= max_val; currentSize += step) {
            runAndAverage(sorter, type, min, max, currentSize, sets_num);
            cout << "\t\tsize= " << currentSize << "\n";
        }
    }
};

class SelectionSorter : public Sorter {
public:
    static void Swap(int *first, int *second) {
        int temp = *first;
        *first = *second;
        *second = temp;
    }

    void Sort(int arr[], int size) override {
        int minimum;
        for (int i = 0; i < size - 1; i++) {
            minimum = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minimum])
                    minimum = j;
            }
            Swap(&arr[minimum], &arr[i]);
        }
    }
};

class QuickSorter : public Sorter {
public:
    static void Swap(int *first, int *second) {
        int temp = *first;
        *first = *second;
        *second = temp;
    }

    void Sort(int arr[], int size) override {
        quickSort(arr, 0, size - 1);
    }

    static int div(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                Swap(&arr[i], &arr[j]);
            }
        }
        Swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int divINDEX = div(arr, low, high);
            quickSort(arr, low, divINDEX - 1);
            quickSort(arr, divINDEX + 1, high);
        }
    }
};

int main() {
    int min = 1, max = 100000, sets_num = 4, min_val = 0, max_val = 24000, step = 3000; //size = 200000
    Sorter *a = new QuickSorter();
    Sorter *b = new SelectionSorter();
    Testbed obj(max_val);
    cout << "Random array sorted with Quick sort" << endl;
    obj.runExperient(a, "random", min, max, min_val, max_val, sets_num, step);
    cout << "Random array sorted with Selection Sort" << endl;
    obj.runExperient(b, "random", min, max, min_val, max_val, sets_num, step);
    cout << "Reverse array sorted with Quick Sort" << endl;
    obj.runExperient(a, "reverse", min, max, min_val, max_val, sets_num, step);
    cout << "Reverse array sorted with Selection Sort" << endl;
    obj.runExperient(b, "reverse", min, max, min_val, max_val, sets_num, step);
    return 0;
}
