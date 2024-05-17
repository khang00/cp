import collections
import heapq
import math
from typing import List


class Solution:
    def minimumEffortPath(self, g: List[List[int]]) -> int:
        n, m = len(g), len(g[0])
        dirs = [(0, -1), (-1, 0), (1, 0), (0, 1)]

        def check(k):
            vis = [[False] * m for _ in range(n)]
            vis[0][0] = True

            queue = collections.deque()
            queue.append((0, 0))
            while queue:
                i, j = queue.pop()
                if (i, j) == (n - 1, m - 1):
                    return True

                for (xx, yy) in dirs:
                    x, y = i + xx, j + yy
                    if 0 <= x < n and 0 <= y < m and not vis[x][y] and abs(g[x][y] - g[i][j]) <= k:
                        vis[x][y] = True
                        queue.append((x, y))

            return False

        l, r = -1, 10 ** 6 + 1
        while r - l > 1:
            mid = l + (r - l) // 2
            if not check(mid):
                l = mid
            else:
                r = mid

        return r


if __name__ == '__main__':
    s = Solution()
    print(s.minimumEffortPath(
        [[1, 2, 2], [3, 8, 2], [5, 3, 5]]))
