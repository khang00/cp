import collections
import heapq
import math
from typing import List


class Solution:
    def findMin(self, a: List[int]) -> int:
        n = len(a)
        l, r = -1, n
        while r - l > 1:
            mid = l + (r - l) // 2
            if a[0] <= a[mid]:
                l = mid
            else:
                r = mid

        return a[r] if r != n else a[0]


if __name__ == '__main__':
    sol = Solution()
    print(sol.findMin([3, 4, 5, 1, 2]))
