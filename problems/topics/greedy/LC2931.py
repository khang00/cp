import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def maxSpending(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        queue = []
        for i in range(0, n):
            heapq.heappush(queue, (a[i][m - 1], (i, m - 1)))

        max_ = 0
        d = 1
        while queue:
            val, idx = heapq.heappop(queue)
            max_ += d * val

            i, j = idx
            if j > 0:
                heapq.heappush(queue, (a[i][j - 1], (i, j - 1)))

            d += 1

        return max_


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxSpending([[8, 5, 2],
                           [6, 4, 1],
                           [9, 7, 3]]))
