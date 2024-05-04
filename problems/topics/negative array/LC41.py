import math
from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        mark = -math.inf
        unsued = math.inf
        for i in range(0, len(nums)):
            if nums[i] <= 0 or nums[i] > len(nums):
                nums[i] = unsued

        for i in range(0, len(nums)):
            if nums[i] == mark or nums[i] == unsued:
                continue

            if nums[abs(nums[i]) - 1] == unsued:
                nums[abs(nums[i]) - 1] = mark
            else:
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1])

        for i in range(0, len(nums)):
            if nums[i] == unsued or nums[i] > 0:
                return i + 1

        return len(nums) + 1


if __name__ == '__main__':
    s = Solution()
    print(s.firstMissingPositive([0, 1, 2]))
