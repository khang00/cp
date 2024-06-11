import collections
import heapq
import math
from typing import List


class Solution:
    def longestCommonSubsequence(self, a: str, b: str) -> int:
        n, m = len(a), len(b)
        dp = [[0] * m for _ in range(0, n)]

        dp[0][0] = int(a[0] == b[0])
        for i in range(1, n):
            dp[i][0] = max(dp[i - 1][0], int(a[i] == b[0]))
        for j in range(1, m):
            dp[0][j] = max(dp[0][j - 1], int(a[0] == b[j]))

        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + int(a[i] == b[j]))

        for line in dp:
            print(line)

        return dp[n - 1][m - 1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.longestCommonSubsequence("bssb",
                                       "jmjb"))
