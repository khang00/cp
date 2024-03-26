from typing import List, NamedTuple


class Solution:
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        n = len(p)
        inf = 10 ** 10
        adj = [[inf] * n for _ in range(n)]
        for i in range(0, n):
            for j in range(i + 1, n):
                if i == j:
                    continue
                d = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1])
                adj[i][j] = d
                adj[j][i] = d

        class Edge(NamedTuple):
            to: int
            w: int

        min_c = 0
        min_e = [Edge(-1, inf)] * n
        sel = {0}
        for j in range(0, n):
            if adj[0][j] < min_e[j].w:
                min_e[j] = Edge(j, adj[j][0])

        for i in range(0, n - 1):
            v = -1
            for j in range(0, n):
                if j not in sel and (v == -1 or min_e[j].w < min_e[v].w):
                    v = j

            min_c += min_e[v].w
            sel.add(v)

            for j in range(0, n):
                if adj[v][j] < min_e[j].w:
                    min_e[j] = Edge(j, adj[j][v])

        return min_c


if __name__ == '__main__':
    s = Solution()
    print(s.minCostConnectPoints([[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]))
