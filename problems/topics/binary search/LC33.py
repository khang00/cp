import collections
import heapq
import math
from typing import List


class Solution:
    def search(self, a: List[int], t: int) -> int:
        n = len(a)
        l, r = -1, n
        while r - l > 1:
            mid = l + (r - l) // 2
            if (a[0] <= t and a[0] <= a[mid] <= t) or (a[0] > t and not (a[0] > a[mid] > t)):
                l = mid
            else:
                r = mid

        if l in [n, -1] or a[l] != t:
            return -1

        return l


if __name__ == '__main__':
    sol = Solution()
    print(sol.search([4, 5, 6, 7, 0, 1, 2], 6))