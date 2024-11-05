#include <iostream>
#include <ctime>

class Array {
private:
    int* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}

    Array(int size) : size(size) {
        data = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }


    void InitRandomValues(int newSize) {
        delete[] data;
        size = newSize;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 21;
        }
    }

 
    void FillRandomValues() {
        for (int i = 0; i < size; i++) {
            data[i] = rand() % 21;
        }
    }


    void FillWithCustomRandom(int (*randomFunc)()) {
        for (int i = 0; i < size; i++) {
            data[i] = randomFunc() % 21;
        }
    }


    ~Array() {
        delete[] data;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }
};


int customRandom() {
    return rand();
}

int main() {
    srand(time(0));

    Array arr1;

    Array arr2(5);
    arr2.FillRandomValues();
    arr2.print();

    Array arr3 = arr2;
    arr3.print();

    arr3.InitRandomValues(10);
    arr3.print();

    arr3.FillWithCustomRandom(customRandom);
    arr3.print();

    return 0;
}
