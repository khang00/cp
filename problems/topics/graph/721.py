import math
from typing import List


class Solution:
    def accountsMerge(self, acc: List[List[str]]) -> List[List[str]]:
        n = len(acc)
        dsu = DSU()
        for i in range(0, n):
            dsu.make_set(i)
            for j in range(1, len(acc[i])):
                dsu.make_set(acc[i][j])

        for i in range(0, n):
            a = dsu.find_set(i)
            for j in range(1, len(acc[i])):
                dsu.merge(a, acc[i][j])

        f = {}
        for i in range(0, n):
            for j in range(1, len(acc[i])):
                a = dsu.find_set(acc[i][j])
                if a in f:
                    f[a].add(acc[i][j])
                else:
                    f[a] = set()
                    f[a].add(acc[i][j])

        ans = []
        for k, v in f.items():
            temp = [acc[k][0]]
            temp += sorted(list(v))
            ans.append(temp)

        return ans


class DSU:
    def __init__(self):
        self.anc = {}

    def make_set(self, a):
        self.anc[a] = a

    def find_set(self, a):
        if a in self.anc and self.anc[a] == a:
            return a

        return self.find_set(self.anc[a])

    def merge(self, a, b):
        sa = self.find_set(a)
        sb = self.find_set(b)
        if sa != sb:
            self.anc[sb] = sa


if __name__ == '__main__':
    s = Solution()
    print(s.accountsMerge(
        [["John", "johnsmith@mail.com", "john_newyork@mail.com"],
         ["John", "johnsmith@mail.com", "john00@mail.com"],
         ["Mary", "mary@mail.com"],
         ["John", "johnnybravo@mail.com"]]
    ))
