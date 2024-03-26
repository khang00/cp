import math
from typing import List


class Solution:
    def minimumBoxes(self, a: List[int], c: List[int]) -> int:
        cnt = 0
        sum_ = sum(a)
        c.sort(reverse=True)
        while sum_ > 0:
            sum_ -= c[cnt]
            cnt += 1

        return cnt


if __name__ == '__main__':
    s = Solution()
    print(s.minimumBoxes([5, 5, 5], [2, 4, 2, 7]))
