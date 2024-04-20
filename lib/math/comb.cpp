#include <bits/stdc++.h>
using namespace std;

long long comb(long long n, long long k) {
    long double res = 1;
    for (long long i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;

    return (long long) (res + 0.01);
}