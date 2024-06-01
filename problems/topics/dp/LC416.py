import collections
import heapq
import math
from typing import List


class Solution:
    def canPartition(self, a: List[int]) -> bool:
        sum_ = sum(a)
        if sum_ % 2 == 1:
            return False

        # f(t) = S: set of elements sum up to t
        # f(i) = a[j]                       if a[j] == i
        # f(i) = f(i - a[j]) union a[j]     if f(i - a[j]) has solution

        n = len(a)
        if n <= 1:
            return False

        half = sum_ // 2
        dp = [set() for _ in range(0, half + 1)]
        for i in range(0, half + 1):
            for j in range(0, n):
                if i == a[j]:
                    dp[i] = {j}
                    break

                if i - a[j] >= 0 and len(dp[i - a[j]]) > 0 and j not in dp[i - a[j]]:
                    dp[i] = dp[i - a[j]] | {j}
                    break
        print(dp)
        return len(dp[half]) > 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.canPartition([1, 5, 11, 5]))
