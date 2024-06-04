import collections
import heapq
import math
from typing import List


class Solution:
    def search(self, a: List[int], t: int) -> bool:
        n = len(a)
        while n > 1 and a[0] == a[n - 1]:
            n -= 1

        l, r = -1, n
        while r - l > 1:
            mid = l + (r - l) // 2
            if (a[0] <= t and a[0] <= a[mid] <= t) or not (a[0] <= t or a[0] > a[mid] > t):
                l = mid
            else:
                r = mid

        if l in [n, -1] or a[l] != t:
            return False

        return True


if __name__ == '__main__':
    sol = Solution()
    print(sol.search([2], 2))
