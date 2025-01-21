from collections import deque, defaultdict, Counter
from dataclasses import dataclass, field
from functools import cache, lru_cache
from heapq import heappop, heappush, heapify
from itertools import count
from math import log10, floor, sqrt, floor, ceil, lcm
from typing import List, Deque, Tuple, Dict

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        directions = [(0, 0), (0, 1), (0, -1), (1, 0), (-1, 0)]

        dis = [[10 ** 9] * m for _ in range(n)]
        dis[0][0] = 0

        queue = deque()
        queue.append((0, 0, 0))
        while queue:
            (uw, i, j) = queue.popleft()
            if (i, j) == (n - 1, m - 1):
                return uw

            for dx, dy in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                x, y = i + dx, j + dy
                if not (0 <= x < n and 0 <= y < m):
                    continue

                vw = uw
                if directions[grid[i][j]] != (dx, dy):
                    vw += 1

                if dis[x][y] > vw:
                    dis[x][y] = vw
                    if vw == uw:
                        queue.appendleft((vw, x, y))
                    else:
                        queue.append((vw, x, y))

        return dis[n - 1][m - 1]


if __name__ == '__main__':
    sol = Solution()

    print(sol.minCost(
        [[3, 4, 3], [2, 2, 2], [2, 1, 1], [4, 3, 2], [2, 1, 4], [2, 4, 1], [3, 3, 3], [1, 4, 2], [2, 2, 1], [2, 1, 1],
         [3, 3, 1], [4, 1, 4], [2, 1, 4], [3, 2, 2], [3, 3, 1], [4, 4, 1], [1, 2, 2], [1, 1, 1], [1, 3, 4], [1, 2, 1],
         [2, 2, 4], [2, 1, 3], [1, 2, 1], [4, 3, 2], [3, 3, 4], [2, 2, 1], [3, 4, 3], [4, 2, 3], [4, 4, 4]],
    ))
