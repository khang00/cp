import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def findMaximizedCapital(self, k: int, cnt: int, p: List[int], c: List[int]) -> int:
        n = len(p)
        a = []

        for i in range(0, n):
            a.append((c[i], p[i], i))
        a.sort()

        queue = []
        if a[0][0] <= cnt:
            heapq.heappush(queue, (-a[i][1], a[i][0], a[i][2]))

        i = 1
        while queue and k > 0:
            curr = heapq.heappop(queue)
            cnt += -curr[0]

            while i < n:
                if a[i][0] > cnt:
                    break
                heapq.heappush(queue, (-a[i][1], a[i][0], a[i][2]))
                i += 1

            k -= 1

        return cnt


if __name__ == '__main__':
    sol = Solution()
    print(sol.findMaximizedCapital(2, 0,
                                   [1, 2, 3],
                                   [0, 1, 1]))
