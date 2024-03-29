import math
from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        max_ = max(nums)
        p = []
        for i in range(0, n):
            if nums[i] == max_:
                p.append(i)

        if len(p) < k:
            return 0

        cnt = 0
        l, r = 0, k - 1
        while r < len(p):
            if r < len(p) - 1:
                cnt += (p[l] + 1) * (p[r + 1] - p[r])
            else:
                cnt += (p[l] + 1) * (n - p[r])

            l += 1
            r += 1

        return cnt


if __name__ == '__main__':
    s = Solution()
    print(s.countSubarrays(
        [4, 6, 1, 6, 2, 5], 2))
