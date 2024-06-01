import collections
import heapq
import math
from typing import List


class Solution:
    def wordBreak(self, s: str, a: List[str]) -> bool:
        set_ = set(a)

        n = len(s)
        dp = [False] * n
        for i in range(0, n):
            if s[0:i + 1] in set_:
                dp[i] = True

        for i in range(0, n):
            for j in range(0, i):
                if dp[j] and s[j + 1:i + 1] in set_:
                    dp[i] = True
                    break

        print(dp)
        return dp[n - 1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.wordBreak("ndog", ["cats", "dog", "nd", "and", "cat"]))
