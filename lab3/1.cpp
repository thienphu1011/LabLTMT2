#include <iostream> 
using namespace std; 


int partition(int arr[], int low, int high, bool ascending) { 

    int pivot = arr[low]; 
    int i = low - 1, j = high + 1; 

    while (true) { 
        if (ascending) { 
            do { i++; } while (arr[i] < pivot); 
            do { j--; } while (arr[j] > pivot); 

        } else { 
            do { i++; } while (arr[i] > pivot); 
            do { j--; } while (arr[j] < pivot); 

        } 
        if (i >= j) return j; 
        swap(arr[i], arr[j]); 

    } 

} 

 

void qs(int arr[], int low, int high, bool ascending) { 
    if (low < high) { 
      int p = partition(arr, low, high, ascending); 
        qs(arr, low, p, ascending); 
        qs(arr, p + 1, high, ascending); 

    } 

} 

 

int main() { 
    int N; 
    cout << "Enter the number of elements (N): "; 
    cin >> N; 

    int* arr = new int[N]; 

    cout << "Enter " << N << " integers:" << endl; 
    for (int i = 0; i < N; i++) { 
        cin >> arr[i]; 
    } 

 

    int orderChoice; 
    cout << "Sort in (1) Ascending or (2) Descending order? Enter 1 or 2: "; 
    cin >> orderChoice; 
    bool ascending = (orderChoice == 1); 
    qs(arr, 0, N - 1, ascending); 
 
    cout << "Sorted array:" << endl; 
    for (int i = 0; i < N; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
    delete[] arr;  

    return 0; 

} 