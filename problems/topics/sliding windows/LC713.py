import math
from typing import List


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        p = [1] * n
        p[0] = nums[0]
        for i in range(1, n):
            p[i] = p[i - 1] * nums[i]

        ans = 0
        l, r = 0, 0
        while n > r >= l:
            while l <= r and (p[r] // p[l]) * nums[l] >= k:
                l += 1
            ans += r - l + 1
            r += 1

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.numSubarrayProductLessThanK(
        [1, 2, 3],
        0
    ))
