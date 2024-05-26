import collections
import heapq
import math
from typing import List

class Solution:
    def subsetsWithDup(self, a: List[int]) -> List[List[int]]:
        n = len(a)
        a.sort()

        def backtrack(i, anc):
            if i == n - 1:
                return [anc + [a[i]]]

            ans = [anc + [a[i]]]
            for j in range(i + 1, n):
                ans += backtrack(j, anc + [a[i]])

            return ans

        b = set()
        for i in range(0, n):
            temp = backtrack(i, [])
            for j in range(0, len(temp)):
                temp[j] = tuple(temp[j])

            b = b.union(temp)

        b = list(b)
        b.append([])
        for j in range(0, len(b)):
            b[j] = list(b[j])

        return b


if __name__ == '__main__':
    s = Solution()
    print(s.subsetsWithDup(
        [1, 2, 3]
    ))
