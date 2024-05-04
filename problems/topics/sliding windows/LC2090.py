import math
from typing import List


class Solution:
    def getAverages(self, a: List[int], ra: int) -> List[int]:
        n = len(a)
        k = ra * 2 + 1
        if n < k:
            return [-1] * n

        r = 0
        sum_ = 0
        while r + 1 < k:
            sum_ += a[r]
            r += 1

        ans = [-1] * n
        while r < n:
            sum_ += a[r]
            ans[r - ra] = sum_ // k
            sum_ -= a[r - k + 1]
            r += 1

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.getAverages([7, 4, 3, 9, 1, 8, 5, 2, 6], 3))
