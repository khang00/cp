import collections
import math
from typing import List


class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def f(t: int):
            if t == 0:
                return 0

            c = collections.Counter()
            at_most_t = 0
            l, r = 0, 0
            while n > r >= l:
                c[nums[r]] += 1
                while l < r and len(c) > t:
                    c[nums[l]] -= 1
                    if c[nums[l]] == 0:
                        del c[nums[l]]

                    l += 1

                at_most_t += r - l + 1
                r += 1
            return at_most_t

        return f(k) - f(k - 1)


if __name__ == '__main__':
    s = Solution()
    print(s.subarraysWithKDistinct([1, 2], 1))
