#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000]; 
    
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

 
    int min_index = 0, max_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }

    int temp = arr[min_index];
    arr[min_index] = arr[max_index];
    arr[max_index] = temp;

  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
