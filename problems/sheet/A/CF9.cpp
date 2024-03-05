#include <bits/stdc++.h>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int y, w;
    cin >> y >> w;

    int m = 6 - max(y, w) + 1;

    switch (m) {
        case 1: cout << '1' << '/' << '6';
            break;
        case 2: cout << '1' << '/' << '3';
            break;
        case 3: cout << '1' << '/' << '2';
            break;
        case 4: cout << '2' << '/' << '3';
            break;
        case 5: cout << '5' << '/' << '6';
            break;
        case 6: cout << '1' << '/' << '1';
    }

    return 0;
}