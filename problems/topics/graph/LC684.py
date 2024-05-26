import collections
import heapq
import math
from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        g = {}
        vis = {}
        for edge in edges:
            (a, b) = edge
            vis[a], vis[b] = False, False
            if a in g:
                g[a].append(b)
            else:
                g[a] = [b]

            if b in g:
                g[b].append(a)
            else:
                g[b] = [a]

        anc = {}

        def dfs(curr, par):
            anc[curr] = par
            vis[curr] = True
            if curr not in g:
                return -1, -1

            for node in g[curr]:
                if node == par:
                    continue

                if not vis[node]:
                    child = dfs(node, curr)
                    if child != (-1, -1):
                        return child
                else:
                    return node, curr

            return -1, -1

        temp = dfs(edges[0][0], edges[0][0])
        if temp != (-1, -1):
            edges.reverse()
            cycle_anc = {}

            s, e = temp
            while e != s:
                cycle_anc[e] = anc[e]
                e = anc[e]
            cycle_anc[s] = e

            for edge in edges:
                a, b = edge[0], edge[1]
                if a in cycle_anc and b in cycle_anc:
                    return [a, b]

        return []


if __name__ == '__main__':
    s = Solution()
    print(s.findRedundantConnection(
        [[9, 10], [5, 8], [2, 6], [1, 5], [3, 8], [4, 9], [8, 10], [4, 10], [6, 8], [7, 9]]
    ))
