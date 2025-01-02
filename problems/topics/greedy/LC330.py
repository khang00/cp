import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def minPatches(self, a: List[int], n: int) -> int:
        cnt = 0
        sum_ = 0
        i = 0
        while sum_ < n:
            if i < len(a):
                if sum_ + 1 < a[i]:
                    while sum_ < n and sum_ + 1 < a[i]:
                        sum_ += sum_ + 1
                        cnt += 1
                sum_ += a[i]
            else:
                sum_ += sum_ + 1
                cnt += 1
            i += 1

        return cnt


if __name__ == '__main__':
    sol = Solution()
    print(sol.minPatches([1, 3], 6))
