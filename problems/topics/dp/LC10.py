import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)

        @cache
        def solve(i, j):
            if i == 0 and j == 0:
                return True

            if i == 0:
                if j >= 0 and p[j - 1] == '*':
                    return solve(i, j - 2)
                else:
                    return False

            if j == 0 and i > 0:
                return False

            if p[j - 1] == '.' or s[i - 1] == p[j - 1]:
                return solve(i - 1, j - 1)
            elif p[j - 1] == '*':
                return solve(i, j - 2) or (solve(i - 1, j) and (p[j - 2] == '.' or s[i - 1] == p[j - 2]))

            return False

        return solve(n, m)


if __name__ == '__main__':
    sol = Solution()
    print(sol.isMatch("aaa", "a"))
