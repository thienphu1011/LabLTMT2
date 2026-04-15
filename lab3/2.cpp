#include <iostream> 
#include <vector> 
#include <algorithm>  

using namespace std; 
 

int main() { 

    int N; 
    cout << "Enter the number of elements (N): "; 
    cin >> N; 

 

    vector<int> v(N); 

    cout << "Enter " << N << " integers:" << endl; 
    for (int i = 0; i < N; i++) { 
        cin >> v[i]; 

    } 

 

    int orderChoice; 
    cout << "Sort in (1) Ascending or (2) Descending order? Enter 1 or 2: "; 
    cin >> orderChoice; 


    if (orderChoice == 1) {   
        sort(v.begin(), v.end()); 

    } else { 

        sort(v.begin(), v.end(), greater<int>()); 

    } 

 
    cout << "Sorted vector:" << endl; 
    for (int i = 0; i < N; i++) { 
        cout << v[i] << " "; 

    } 
    cout << endl; 

    return 0; 

} 