import collections
import heapq
import math
from typing import List


class Solution:
    def solve(self, g: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n, m = len(g), len(g[0])
        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        vis = [[False] * m for _ in range(0, n)]

        def bfs(curr):
            queue = collections.deque()
            queue.append(curr)

            while queue:
                i, j = queue.popleft()
                g[i][j] = '*'

                for dx, dy in dirs:
                    x, y = i + dx, j + dy
                    if 0 <= x < n and 0 <= y < m and not vis[x][y] and g[x][y] == 'O':
                        vis[x][y] = True
                        queue.append((x, y))

            return

        for i in [0, n - 1]:
            for j in range(0, m):
                if g[i][j] == 'O' and not vis[i][j]:
                    vis[i][j] = True
                    bfs((i, j))

        for i in range(1, n - 1):
            for j in [0, m - 1]:
                if g[i][j] == 'O' and not vis[i][j]:
                    vis[i][j] = True
                    bfs((i, j))

        for i in range(0, n):
            for j in range(0, m):
                if g[i][j] == 'O':
                    g[i][j] = 'X'

                if g[i][j] == '*':
                    g[i][j] = 'O'

        return


if __name__ == '__main__':
    board = [["O", "O", "O", "O", "X", "X"],
             ["O", "O", "O", "O", "O", "O"],
             ["O", "X", "O", "X", "O", "O"],
             ["O", "X", "O", "O", "X", "O"],
             ["O", "X", "O", "X", "O", "O"],
             ["O", "X", "O", "O", "O", "O"]]
    s = Solution()
    s.solve(board)
    print(board)
