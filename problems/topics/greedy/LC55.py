import math
from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        max_ = 0
        for i in range(0, n):
            if i == max_ and nums[max_] == 0:
                break
            max_ = min(max(max_, i + nums[i]), n - 1)

        return max_ == n - 1


if __name__ == '__main__':
    s = Solution()
    print(s.canJump([2, 5, 0, 0]))
