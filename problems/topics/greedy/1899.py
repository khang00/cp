import math
from typing import List


class Solution:
    def mergeTriplets(self, arr: List[List[int]], t: List[int]) -> bool:
        n = len(arr)
        a = [[], [], []]
        mask = [0, 0, 0]
        for i in range(0, n):
            for j in range(0, 3):
                if arr[i][j] == t[j]:
                    mask[j] = 1
                    a[j].append(i)

        if sum(mask) < 3:
            return False

        inf = 10 ** 9
        for o in range(0, 3):
            b = [inf, inf, inf]
            for i in a[o]:
                for j in range(0, 3):
                    b[j] = min(b[j], arr[i][j])

            for i in range(0, 3):
                if b[i] > t[i]:
                    return False

        return True


if __name__ == '__main__':
    s = Solution()
    print(s.mergeTriplets([
        [2, 5, 3], [1, 8, 4], [1, 7, 5]
    ], [2, 7, 5]))
