#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        int sum = 0;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            sum += abs(num);
        }

        cout << sum << "\n";
    }

    return 0;
}