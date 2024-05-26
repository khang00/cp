import collections
import heapq
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

        temp = self.find_set(self.anc[a])
        self.anc[a] = temp

        return temp

    def merge(self, a, b):
        set_a = self.find_set(a)
        set_b = self.find_set(b)
        if set_a != set_b:
            if self.size[set_a] < self.size[set_b]:
                set_a, set_b = set_b, set_a
            self.anc[set_a] = set_b
            self.size[set_b] += self.size[set_a]


class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        s = DSU()
        for i in range(0, n):
            s.make_set(i)

        for edge in edges:
            [a, b, _] = edge
            s.merge(a, b)

        min_cost = {}
        for edge in edges:
            [a, _, w] = edge
            r = s.find_set(a)
            if r in min_cost:
                min_cost[r] &= w
            else:
                min_cost[r] = w

        ans = []
        for q in queries:
            [a, b] = q
            if s.find_set(a) == s.find_set(b):
                r = s.find_set(a)
                ans.append(min_cost[r])
            else:
                ans.append(-1)

        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.minimumCost(5,
                          [[0, 1, 7], [1, 3, 7], [1, 2, 1]],
                          [[0, 3], [3, 4]]
                          ))
