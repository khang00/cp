import collections
import heapq
import math
from typing import List


class Solution:
    def findTargetSumWays(self, a: List[int], t: int) -> int:
        n, m = len(a), 1000
        dp = [[0] * ((m * 2) + 1) for _ in range(0, n)]
        dp[0][a[0] + m] = 1
        dp[0][-a[0] + m] += 1

        for i in range(1, n):
            for j in range(-m, m + 1):
                if j + a[i] <= m:
                    dp[i][j + m] += dp[i - 1][j + a[i] + m]

                if j - a[i] >= -m:
                    dp[i][j + m] += dp[i - 1][j - a[i] + m]

        for line in dp:
            print(line)

        return dp[n - 1][t + m]


if __name__ == '__main__':
    sol = Solution()
    print(sol.findTargetSumWays([1], 2))
