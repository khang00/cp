#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int stop = n - 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[j + 1] == '1' && b[j] == '0') {
                stop = j;
                break;
            }
        }

        int cnt = 0;
        for (int j = stop; j > 0; j--) {
            if (b[j - 1] != a[j])
                break;

            cnt += 1;
        }

        string path = a.substr(0, stop + 1) + b.substr(stop);
        cout << path << "\n" << cnt + 1 << "\n";
    }

    return 0;
}