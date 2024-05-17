import collections
import heapq
import math
from typing import List


class Solution:

    def inverse(self, n, a):
        return n * 2 - a

    def maximumSafenessFactor(self, g: List[List[int]]) -> int:
        n = len(g)
        if g[0][0] == 1 or g[n - 1][n - 1] == 1:
            return 0

        queue = collections.deque()
        for i in range(0, n):
            for j in range(0, n):
                if g[i][j] == 1:
                    queue.append((i, j))
        dirs = [(0, -1), (-1, 0), (1, 0), (0, 1)]

        curr_w = 0
        vis = [[False] * n for _ in range(n)]
        for (i, j) in queue:
            vis[i][j] = True

        while len(queue) > 0:
            for (i, j) in queue:
                g[i][j] = self.inverse(n, curr_w)

            temp = collections.deque()
            while len(queue) > 0:
                (i, j) = queue.pop()
                for (xx, yy) in dirs:
                    x, y = i + xx, j + yy
                    if 0 <= x < n and 0 <= y < n and not vis[x][y]:
                        vis[x][y] = True
                        temp.append((x, y))
            queue = temp
            curr_w += 1

        inf = 399 * 399 + 2
        dis = [[inf] * n for _ in range(n)]
        pre = {}

        dis[0][0] = g[0][0]
        hqueue = [(g[0][0], 0, 0)]
        while hqueue:
            (w, i, j) = heapq.heappop(hqueue)
            if (i, j) == (n - 1, n - 1):
                return self.inverse(n, w)

            for xx, yy in dirs:
                x, y = i + xx, j + yy
                if 0 <= x < n and 0 <= y < n:
                    # We are working on the inverse version of the problem
                    # So we want to maximize the node in the path instead
                    d = max(dis[i][j], g[x][y])
                    if d < dis[x][y]:
                        dis[x][y] = d
                        heapq.heappush(hqueue, (dis[x][y], x, y))
                        pre[(x, y)] = (i, j)

        return 0


if __name__ == '__main__':
    s = Solution()
    print(s.maximumSafenessFactor(
        [[0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]))
