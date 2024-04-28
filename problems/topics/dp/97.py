import functools
import math
from typing import List


class Solution:
    def isInterleave(self, a: str, b: str, c: str) -> bool:
        n, m, o = len(a), len(b), len(c)
        if n + m != o:
            return False

        def backtrack(i, j):
            if i == 0 and j == 0:
                return True
            if i == 0:
                return backtrack(i, j - 1) and c[j - 1] == b[j - 1]
            if j == 0:
                return backtrack(i - 1, j) and c[i - 1] == a[i - 1]

            lhs = backtrack(i - 1, j) and c[i + j - 1] == a[i - 1]
            rhs = backtrack(i, j - 1) and c[i + j - 1] == b[j - 1]

            return lhs or rhs

        return backtrack(n, m)

    def isInterleave_dp(self, a: str, b: str, c: str):
        n, m, o = len(a), len(b), len(c)
        if n + m != o:
            return False

        dp = [False] * (m + 1)
        for i in range(0, n + 1):
            for j in range(0, m + 1):
                if i == 0 and j == 0:
                    dp[0] = True
                elif j == 0:
                    dp[0] = c[i - 1] == a[i - 1]
                elif i == 0:
                    dp[j] = dp[j - 1] and c[j - 1] == b[j - 1]
                else:
                    dp[j] = (dp[j] and c[i + j - 1] == a[i - 1]) or (
                            dp[j - 1] and c[i + j - 1] == b[j - 1])

        return dp[m]


if __name__ == '__main__':
    s = Solution()
    print(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"))
