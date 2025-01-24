#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        sum += num; // Corrected: Sum the numbers directly, not their absolute values
    }

    cout << abs(sum) << endl; // Take the absolute value of the sum

    return 0;
}