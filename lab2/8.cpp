#include <iostream>

using namespace std;

template <class T>
class SimpleVector {
private:
    T *aptr;
    int arraySize;

public:
    SimpleVector(int s) {
        arraySize = s;
        aptr = new T[s];
        for (int i = 0; i < arraySize; i++) {
            aptr[i] = T();
        }
    }

    ~SimpleVector() {
        if (arraySize > 0) {
            delete[] aptr;
        }
    }

    int size() const {
        return arraySize;
    }

    T &operator[](const int &sub) {
        return aptr[sub];
    }
};

template <class T>
class SortableVector : public SimpleVector<T> {
public:
    SortableVector(int s) : SimpleVector<T>(s) {}

    void sort() {
        int n = this->size();
        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; i++) {
                if (this->operator[](i) > this->operator[](i + 1)) {
                    T temp = this->operator[](i);
                    this->operator[](i) = this->operator[](i + 1);
                    this->operator[](i + 1) = temp;
                    swapped = true;
                }
            }
        } while (swapped);
    }
};

int main() {
    SortableVector<int> intTable(5);
    intTable[0] = 54;
    intTable[1] = 12;
    intTable[2] = 89;
    intTable[3] = 32;
    intTable[4] = 7;

    intTable.sort();

    for (int i = 0; i < intTable.size(); i++) {
        cout << intTable[i] << " ";
    }
    cout << "\n";

    return 0;
}