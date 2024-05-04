import math
from typing import List


class DSU:
    def __init__(self):
        self.anc = {}
        self.size = {}

    def make_set(self, a):
        self.anc[a] = a
        self.size[a] = 1

    def find_set(self, a):
        if self.anc[a] == a:
            return a
        b = self.find_set(self.anc[a])
        self.anc[a] = b
        return b

    def merge_set(self, a, b):
        sa = self.find_set(a)
        sb = self.find_set(b)
        if sa != sb:
            if self.size[sa] < self.size[sb]:
                sa, sb = sb, sa
            self.anc[sb] = sa
            self.size[sa] += self.size[sb]


class Solution:
    def longestIncreasingPath(self, g: List[List[int]]) -> int:
        n, m = len(g), len(g[0])

        dirs = [(0, -1), (-1, 0), (0, 1), (1, 0)]
        cache = {}

        def dfs(v):
            if v in cache:
                return cache[v]

            nodes = []
            a, b = v
            for xx, yy in dirs:
                x, y = a + xx, b + yy
                if 0 <= x < n and 0 <= y < m and g[x][y] > g[a][b]:
                    nodes.append((x, y))

            max_l = 0
            for x, y in nodes:
                path = dfs((x, y))
                max_l = max(max_l, path)

            cache[v] = max_l + 1
            return max_l + 1

        max_ = 0
        for i in range(0, n):
            for j in range(0, m):
                max_ = max(max_, dfs((i, j)))

        return max_


if __name__ == '__main__':
    s = Solution()
    print(s.longestIncreasingPath([[3, 4, 5], [3, 2, 6], [2, 2, 1]]))
