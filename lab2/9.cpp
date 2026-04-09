#include <iostream>

using namespace std;

class IntArray {
private:
    int *aptr;
    int arraySize;

public:
    class SubscriptError {};

    IntArray(int s) {
        arraySize = s;
        aptr = new int[s];
        for (int count = 0; count < arraySize; count++) {
            *(aptr + count) = 0;
        }
    }

    IntArray(const IntArray &obj) {
        arraySize = obj.arraySize;
        aptr = new int[arraySize];
        for (int count = 0; count < arraySize; count++) {
            *(aptr + count) = *(obj.aptr + count);
        }
    }

    ~IntArray() {
        if (arraySize > 0) {
            delete[] aptr;
        }
    }

    int size() const { 
        return arraySize; 
    }

    int &operator[](const int &sub) {
        if (sub < 0 || sub >= arraySize) {
            throw SubscriptError();
        }
        return aptr[sub];
    }
};

int main() {
    IntArray table(10);

    try {
        for (int i = 0; i < 10; i++) {
            table[i] = i * 2;
        }

        cout << table[5] << "\n";
        
        cout << table[15] << "\n";
    }
    catch (IntArray::SubscriptError) {
        cout << "Error: Subscript out of range.\n";
    }

    return 0;
}