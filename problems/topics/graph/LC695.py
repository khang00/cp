import collections
import heapq
import math
from typing import List


class Solution:
    def maxAreaOfIsland(self, g: List[List[int]]) -> int:
        n,  m = len(g), len(g[0])
        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        vis = [[False] * m for _ in range(0, n)]

        def bfs(curr):
            cnt = 0
            queue = collections.deque()
            queue.append(curr)
            vis[curr[0]][curr[1]] = True
            while queue:
                (i, j) = queue.popleft()
                cnt += 1

                for (xx, yy) in dirs:
                    x, y = i + xx, j + yy
                    if 0 <= x < n and 0 <= y < m and not vis[x][y] and g[x][y] == 1:
                        vis[x][y] = True
                        queue.append((x, y))

            return cnt

        max_ = 0
        for i in range(0, n):
            for j in range(0, m):
                if g[i][j] == 1 and not vis[i][j]:
                    max_ = max(max_, bfs((i, j)))

        return max_


if __name__ == '__main__':
    s = Solution()
    print(s.maxAreaOfIsland(
        [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
         [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
         [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]))
