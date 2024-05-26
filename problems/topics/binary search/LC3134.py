import collections
import heapq
import math
from typing import List


class Solution:
    def medianOfUniquenessArray(self, a: List[int]) -> int:
        n = len(a)
        N = (n * (n + 1)) / 2

        def check(k):
            cnt = 0
            f = collections.Counter()
            l, r = 0, 0
            while n > r >= l:
                f[a[r]] += 1
                while len(f.keys()) > k:
                    f[a[l]] -= 1
                    if f[a[l]] == 0:
                        del f[a[l]]
                    l += 1

                cnt += r - l + 1
                r += 1

            return cnt >= N / 2

        l, r = 0, n
        while r - l > 1:
            mid = l + (r - l) // 2
            if not check(mid):
                l = mid
            else:
                r = mid

        return r


if __name__ == '__main__':
    s = Solution()
    print(s.medianOfUniquenessArray(
        [3, 4, 3, 4, 5]
    ))
