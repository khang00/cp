#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define ll long long
#define INF 1e18

string solve(vector<int> nums, int n) {
    std::sort(nums.begin(), nums.end());
    if (nums[0] != nums[1]) {
        return "YES";
    }

    if (nums[0] == nums[1]) {
        for (int i = 1; i < n; i++) {
            if (nums[i] % nums[0] != 0) {
                return "YES";
            }
        }
    }

    return "NO";
}

int main() {
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        vector<int> nums;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        cout << solve(nums, n) << '\n';
    }

    return 0;
}
