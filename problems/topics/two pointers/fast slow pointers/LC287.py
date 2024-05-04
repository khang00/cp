import math
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        fast = 0
        slow = 0

        while fast != slow or (fast == 0 and slow == 0):
            slow = nums[slow]
            fast = nums[fast]
            fast = nums[fast]

        slow = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return slow


if __name__ == '__main__':
    s = Solution()
