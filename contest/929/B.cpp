#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    vector<int> anss;
    for (int i = 0; i < t; i++) {
        cin >> n;

        int sum = 0;
        vector<int> nums;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            nums.push_back(num);
            sum += num;
        }

        if (sum % 3 == 0) {
            anss.push_back(0);
            continue;
        }

        int ans = -1;
        for (int j = 0; j < n; j++) {
            if ((sum - nums[j]) % 3 == 0) {
                ans = 1;
                break;
            }
        }

        if (ans == -1) {
            anss.push_back(3 - (sum % 3));
        } else {
            anss.push_back(ans);
        }
    }

    for (int i = 0; i < t; i++) {
        cout << anss[i] << '\n';
    }

    return 0;
}