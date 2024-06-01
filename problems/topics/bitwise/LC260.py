import collections
import heapq
import math
from typing import List


class Solution:
    def singleNumber(self, a: List[int]) -> List[int]:
        n = len(a)
        x = 0
        for i in range(0, n):
            x ^= a[i]

        pos = 0
        while (x >> pos) & 1 == 0:
            pos += 1

        x, y = 0, 0
        for i in range(0, n):
            if (a[i] >> pos) & 1 == 0:
                x ^= a[i]
            else:
                y ^= a[i]

        return [x, y]


if __name__ == '__main__':
    sol = Solution()
    print(sol.singleNumber([1, 2, 1, 3, 2, 5]))
