import collections
import heapq
import math
from typing import List


class Solution:
    def minimumDistance(self, ps: List[List[int]]) -> int:
        n = len(ps)
        min_arr = [0] * n
        max_arr = [0] * n

        for i in range(0, n):
            p = ps[i]
            min_arr[i] = p[0] + p[1]
            max_arr[i] = p[0] + p[1]

        min_arr.sort()
        max_arr.sort()

        return min(
            max(min_arr[-2] - min_arr[0], max_arr[-2] - max_arr[0]),
            max(min_arr[-1] - min_arr[1], max_arr[-1] - max_arr[1]),
        )


if __name__ == '__main__':
    sol = Solution()
    print(sol.minimumDistance([[3, 10], [5, 15], [10, 2], [4, 4]]))
