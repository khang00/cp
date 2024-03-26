import math
from typing import List


class Solution:
    def maximumHappinessSum(self, h: List[int], k: int) -> int:
        h.sort(reverse=True)
        ans = 0

        for i in range(0, k):
            if h[i] - i > 0:
                ans += h[i] - i

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.maximumHappinessSum([12, 1, 42], 3))
