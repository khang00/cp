import collections
import heapq
import math
from typing import List


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        cache = [[-1] * m for _ in range(0, n)]

        def solve(i, j):
            if i == 0 and j == 0:
                return 1

            if i == 0:
                return 0

            if j == 0:
                return 1

            if cache[i - 1][j - 1] != -1:
                return cache[i - 1][j - 1]

            sum_ = solve(i - 1, j)
            if s[i - 1] == t[j - 1]:
                sum_ += solve(i - 1, j - 1)

            cache[i - 1][j - 1] = sum_
            return sum_

        return solve(n, m)


if __name__ == '__main__':
    sol = Solution()
    print(sol.numDistinct("babgbag", "bag"))
