import collections
import heapq
import math
from typing import List

import collections
import heapq
import math
from typing import List


class Solution:
    def maxProfit(self, a: List[int]) -> int:
        n = len(a)
        if n < 2:
            return 0

        dp = [[0] * 2 for _ in range(0, n)]
        dp[0][0] = -a[0]
        dp[1][0] = max(-a[0], -a[1])
        dp[1][1] = max(dp[0][1], dp[0][0] + a[1])

        for i in range(2, n):
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - a[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i])

        return max(dp[n - 1])


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxProfit([6, 1, 3, 2, 4, 7]))
