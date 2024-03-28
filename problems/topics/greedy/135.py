import math
from typing import List


class Solution:
    def candy(self, a: List[int]) -> int:
        n = len(a)
        l = [1] * n
        for i in range(1, n):
            if a[i] > a[i - 1]:
                l[i] += l[i - 1]

        r = [1] * n
        for i in range(n - 2, -1, -1):
            if a[i] > a[i + 1]:
                r[i] += r[i + 1]

        c = 0
        for i in range(0, n):
            c += max(l[i], r[i])

        return c


if __name__ == '__main__':
    s = Solution()
    print(s.candy([3, 2, 1, 2, 3, 2, 1]))
