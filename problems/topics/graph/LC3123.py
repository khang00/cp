import collections
import heapq
import math
from typing import List


class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        g = [[] for _ in range(0, n)]
        for i in range(0, len(edges)):
            (s, e, w) = edges[i]
            g[s].append((w, e, i))
            g[e].append((w, s, i))

        d = self.dij(n, (0, n - 1), g)
        min_d = d[0]
        min_edge = set()
        ans = [False] * len(edges)

        def dfs(v, w):
            for (wi, i, ai) in g[v]:
                if not ans[ai]:
                    if w + wi + d[i] == min_d:
                        min_edge.add((v, i))
                        ans[ai] = True
                        dfs(i, w + wi)

        dfs(0, 0)

        return ans

    def dij(self, n, s, g):
        d = [int(1e9 + 7)] * n
        d[s[1]] = 0
        queue = [s]
        while queue:
            w, v = heapq.heappop(queue)
            for edge in g[v]:
                (wi, i, _) = edge
                if w + wi < d[i]:
                    d[i] = w + wi
                    heapq.heappush(queue, (d[i], i))

        return d


if __name__ == '__main__':
    sol = Solution()
    print(sol.findAnswer(4,
                         [[2, 0, 1], [0, 1, 1], [0, 3, 4], [3, 2, 2]]))
