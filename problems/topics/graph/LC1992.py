import math
from typing import List


class DSU:
    def __init__(self):
        self.anc = {}

    def make_set(self, a):
        self.anc[a] = a

    def find_set(self, a):
        if self.anc[a] == a:
            return a
        return self.find_set(self.anc[a])

    def merge(self, a, b):
        sa = self.find_set(a)
        sb = self.find_set(b)
        if sa != sb:
            self.anc[sb] = sa


class Solution:
    def findFarmland(self, g: List[List[int]]) -> List[List[int]]:
        dsu = DSU()
        n, m = len(g), len(g[0])

        for i in range(0, n):
            for j in range(0, m):
                if g[i][j] == 1:
                    dsu.make_set((i, j))

        dirs = [(0, -1), (-1, 0), (0, 1), (1, 0)]
        for i in range(0, n):
            for j in range(0, m):
                if g[i][j] != 1:
                    continue

                for x, y in dirs:
                    X, Y = i + x, j + y
                    if 0 <= X < n and 0 <= Y < m and g[X][Y] == 1:
                        dsu.merge((i, j), (X, Y))

        f = {}
        for i in range(0, n):
            for j in range(0, m):
                if g[i][j] != 1:
                    continue

                sn = dsu.find_set((i, j))
                if sn in f:
                    x, y = sn
                    if i > x or j > y:
                        f[sn] = (i, j)
                else:
                    f[sn] = sn

        ans = []
        for k, v in f.items():
            ans.append([k[0], k[1], v[0], v[1]])

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.findFarmland([[1, 0, 0], [0, 1, 1], [0, 1, 1]]))
