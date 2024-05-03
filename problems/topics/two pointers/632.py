import collections
import math
from typing import List


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        arr = []
        for i in range(0, n):
            for j in range(0, len(nums[i])):
                arr.append((nums[i][j], i))
        arr.sort()

        min_range = [0, 1e9]
        f = collections.defaultdict(int)
        l, r = 0, 0
        while len(arr) > r:
            f[arr[r][1]] += 1
            while len(f.keys()) == n:
                if min_range[1] - min_range[0] > arr[r][0] - arr[l][0]:
                    min_range = [arr[l][0], arr[r][0]]

                f[arr[l][1]] -= 1
                if f[arr[l][1]] == 0:
                    del f[arr[l][1]]

                l += 1
            r += 1

        return min_range


if __name__ == '__main__':
    s = Solution()
    print(s.smallestRange([[1, 2, 3], [1, 2, 3], [1, 2, 3]]))
