from collections import deque, defaultdict, Counter
from dataclasses import dataclass, field
from functools import cache, lru_cache
from heapq import heappop, heappush, heapify, merge
from math import log10, floor, sqrt, floor, ceil, lcm, trunc
from typing import List, Deque, Tuple, Dict


class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, cost: List[int]) -> int:
        n = len(edges) + 1

        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        bob_dep = [None] * n

        def dfs(par, node, time, cum):
            nonlocal bob_dep, cost
            if node == 0:
                return True

            for nxt in adj[node]:
                if nxt == par:
                    continue

                if dfs(node, nxt, time + 1, cum + cost[nxt]):
                    bob_dep[nxt] = time + 1
                    return True

        bob_dep[bob] = 0
        dfs(-1, bob, 0, cost[bob])

        vis = [False] * n
        vis[0] = True

        queue = deque()
        queue.append((0, 0, cost[0]))
        max_ = None
        while queue:
            node, dep, weight = queue.popleft()

            has_children = False
            for nxt in adj[node]:
                if vis[nxt]:
                    continue
                has_children = True
                nxt_dep = dep + 1
                nxt_weight = weight + cost[nxt]
                if bob_dep[nxt] is not None:
                    if bob_dep[nxt] < nxt_dep:
                        nxt_weight -= cost[nxt]
                    elif bob_dep[nxt] == nxt_dep:
                        nxt_weight -= (cost[nxt] // 2)

                vis[nxt] = True
                queue.append((nxt, nxt_dep, nxt_weight))
            if not has_children:
                if max_:
                    max_ = max(max_, weight)
                else:
                    max_ = weight

        return max_


if __name__ == '__main__':
    sol = Solution()
    print(sol.mostProfitablePath([[0, 1], [1, 2], [2, 3]], 3, [-5644, -6018, 1188, -8502]))
