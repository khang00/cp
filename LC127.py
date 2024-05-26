import collections
import heapq
import math
from typing import List


class Solution:

    def distance(self, a: str, b: str):
        n = len(a)
        cnt = 0
        for i in range(0, n):
            if a[i] != b[i]:
                cnt += 1

        return cnt

    def ladderLength(self, s: str, e: str, words: List[str]) -> int:
        n = len(words)
        src, dest = -1, -1
        for i in range(0, n):
            if words[i] == s:
                src = i

            if words[i] == e:
                dest = i
        if dest == -1:
            return 0

        if src == -1:
            words.append(s)
            n = len(words)
            src = n - 1

        g = [[] for _ in range(0, n)]
        for i in range(0, n):
            for j in range(i + 1, n):
                if self.distance(words[i], words[j]) == 1:
                    g[i].append(j)
                    g[j].append(i)

            if words[i] == s:
                src = i

            if words[i] == e:
                dest = i

        vis = [False] * n
        vis[src] = True
        anc = {}
        anc[src] = src
        queue = collections.deque()
        queue.append(src)
        while queue:
            curr = queue.popleft()
            if curr == dest:
                nodes = set()
                nodes.add(dest)
                while dest != src:
                    nodes.add(anc[dest])
                    dest = anc[dest]

                return len(nodes)

            for node in g[curr]:
                if not vis[node]:
                    anc[node] = curr
                    vis[node] = True
                    queue.append(node)

        return 0


if __name__ == '__main__':
    s = Solution()
    print(s.ladderLength(
        "hit",
        "cog",
        ["hot", "dot", "dog", "lot", "log", "cog"]
    ))
