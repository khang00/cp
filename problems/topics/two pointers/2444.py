import math
from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        n = len(nums)
        cnt, tempc = 0, 0
        minI, maxI, outI = -1, -1, -1
        for i in range(0, n):
            if nums[i] > maxK or nums[i] < minK:
                outI = i

            if nums[i] == minK:
                minI = i

            if nums[i] == maxK:
                maxI = i
            cnt += max(0, min(minI, maxI) - outI)

        return cnt


if __name__ == '__main__':
    s = Solution()
    print(s.countSubarrays(
        [4, 4, 3, 5, 6, 9], 3, 9))
