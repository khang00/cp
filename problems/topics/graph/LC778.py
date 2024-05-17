import collections
import heapq
import math
from typing import List


class Solution:
    def swimInWater(self, g: List[List[int]]) -> int:
        n = len(g)
        dirs = [(0, -1), (-1, 0), (1, 0), (0, 1)]

        def check(k):
            if k < g[0][0]:
                return False

            vis = [[False] * n for _ in range(n)]
            vis[0][0] = True

            queue = collections.deque()
            queue.append((0, 0))
            while queue:
                (i, j) = queue.pop()
                if (i, j) == (n - 1, n - 1):
                    return True

                for (xx, yy) in dirs:
                    x, y = i + xx, j + yy
                    if 0 <= x < n and 0 <= y < n and not vis[x][y] and g[x][y] <= k:
                        vis[x][y] = True
                        queue.append((x, y))

            return False

        l, r = -1, n ** 2 + 1
        while r - l > 1:
            mid = l + (r - l) // 2
            if not check(mid):
                l = mid
            else:
                r = mid

        return r


if __name__ == '__main__':
    s = Solution()
    print(s.swimInWater(
        [[0, 1, 2, 3, 4],
         [24, 23, 22, 21, 5],
         [12, 13, 14, 15, 16],
         [11, 17, 18, 19, 20],
         [10, 9, 8, 7, 6]]))