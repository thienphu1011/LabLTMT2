#include <iostream>
#include <vector>

using namespace std;

void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void partitionVector(vector<int>& arr, int low, int high, int& pivotIndex) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            mySwap(arr[i], arr[j]);
        }
    }
    mySwap(arr[i + 1], arr[high]);
    pivotIndex = i + 1;
}


void quickSortVector(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi;
        partitionVector(arr, low, high, pi);
        quickSortVector(arr, low, pi - 1);
        quickSortVector(arr, pi + 1, high);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    quickSortVector(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}