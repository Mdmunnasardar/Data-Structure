#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (N == 2) {
        cout << 1 << endl;
        return 0;
    }

    long long prev1 = 0, prev2 = 1, current;
    for (int i = 3; i <= N; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    cout << current << endl;
    return 0;
}
