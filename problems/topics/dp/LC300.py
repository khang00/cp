import collections
import heapq
import math
from typing import List


class Solution:
    def lengthOfLIS(self, a: List[int]) -> int:
        # f(i) longest increasing subsequence end at position i
        # f(i) = max( j from 0 -> i: f(j) + a[i]) for every a[j] < a[i]
        n = len(a)
        dp = [(0, 0)] * n
        dp[0] = (a[0], 1)
        for i in range(1, n):
            max_ = 1
            for j in range(0, i):
                if dp[j][0] < a[i]:
                    max_ = max(max_, dp[j][1] + 1)
            dp[i] = (a[i], max_)

        max_ = 0
        for i in range(0, n):
            max_ = max(max_, dp[i][1])
        return max_


if __name__ == '__main__':
    sol = Solution()
    print(sol.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
