import math
from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for i in range(0, len(nums)):
            if nums[abs(nums[i]) - 1] < 0:
                ans.append(abs(nums[i]))
            else:
                nums[abs(nums[i]) - 1] *= -1

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.findDuplicates([4, 3, 2, 7, 8, 2, 3, 1]))
