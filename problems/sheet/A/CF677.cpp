#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int n, h;
    cin >> n >> h;

    int w = 0;
    for (int i = 0; i < n; ++i) {
        int hi;
        cin >> hi;

        if (hi > h) {
            w += 2;
        } else {
            w += 1;
        }
    }

    cout << w;

    return 0;
}