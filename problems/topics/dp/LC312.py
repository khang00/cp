import collections
import heapq
import math
from typing import List


class Solution:
    def maxCoins(self, a: List[int]) -> int:
        a = [1] + a + [1]
        n = len(a)
        cache = [[-1] * n for i in range(0, n)]

        def solve(i, j):
            if cache[i][j] != -1:
                return cache[i][j]

            if i == j:
                return a[i - 1] * a[i] * a[j + 1]

            max_ = 0
            for k in range(i, j + 1):
                max_ = max(max_, solve(i, k - 1) + solve(k + 1, j) + a[i - 1] * a[k] * a[j + 1])

            cache[i][j] = max_
            return max_

        return solve(1, n - 2)


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxCoins([3, 1, 5, 8]))
