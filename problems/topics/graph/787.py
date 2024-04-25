import collections
import heapq
import math
from typing import List


class Solution:
    def findCheapestPrice_dp(self, n: int, f: List[List[int]], s: int, e: int, k: int) -> int:
        inf = 10 ** 9
        g = {}
        p = {}
        for x, y, w in f:
            if x in g:
                g[x].append((y, w))
            else:
                g[x] = [(y, w)]

            if y in p:
                p[y].append((x, w))
            else:
                p[y] = [(x, w)]

        k += 2
        vis = [False] * n
        dp = [[inf] * (k + 1) for _ in range(0, n)]
        dp[s] = [0] * (k + 1)

        q = collections.deque()
        q.append(s)
        while q:
            c = q.popleft()
            if c in p:
                for (pc, pw) in p[c]:
                    for i in range(1, k):
                        dp[c][i + 1] = min(dp[c][i + 1], dp[pc][i] + pw)

            if vis[c]:
                continue
            vis[c] = True

            if c not in g:
                continue

            for (v, _) in g[c]:
                q.append(v)

        return dp[e][k] if dp[e][k] != inf else -1

    def findCheapestPrice(self, n: int, f: List[List[int]], src: int, dst: int, k: int) -> int:
        g = {}
        for i in range(n):
            g[i] = []

        for fi in f:
            fr, t, p = fi[0], fi[1], fi[2]
            g[fr].append((t, p))

        h = [(0, 0, src)]
        dp = [[math.inf] * (k + 2) for _ in range(n)]
        while len(h) > 0:
            p, hp, c = heapq.heappop(h)
            if c == dst:
                return p

            if hp > k:
                continue

            for (t, tp) in g[c]:
                np = tp + p
                if dp[t][hp + 1] > np:
                    dp[t][hp + 1] = np
                    heapq.heappush(h, (np, hp + 1, t))

        return -1


if __name__ == '__main__':
    sol = Solution()
    print(sol.findCheapestPrice(
        4,
        [[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]],
        0, 3, 1
    ))
