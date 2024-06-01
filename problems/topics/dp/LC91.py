import collections
import heapq
import math
from typing import List


class Solution:
    def numDecodings(self, s: str) -> int:
        # f(i) total number of way to encode s[0:i], x = int(s[i - 1:i + 1])
        # f(i) = f(i - 1)               if x in [1:9]
        # f(i) = f(i - 2)               if x is {10, 20}
        # f(i) = f(i - 1) + f(i - 2)    if x in [10:26] but not is {10, 20}
        n = len(s)
        if s[0] == '0':
            return 0
        if n == 1:
            return 1

        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            one = int(s[i - 1])
            two = int(s[i - 2:i])

            if 1 <= one <= 10:
                dp[i] = dp[i - 1]
            if two in [10, 20]:
                dp[i] = dp[i - 2]
            if 11 <= two <= 26 and two != 20:
                dp[i] = dp[i - 1] + dp[i - 2]

        print(dp)
        return dp[n]


if __name__ == '__main__':
    sol = Solution()
    print(sol.numDecodings("12"))
