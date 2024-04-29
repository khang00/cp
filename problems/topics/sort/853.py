import math
from typing import List


class Solution:
    def carFleet(self, t: int, c: List[int], s: List[int]) -> int:
        n = len(c)
        p = []
        for i in range(0, n):
            p.append([c[i], s[i]])

        p.sort(reverse=True)

        cnt = 1
        max_t = (t - p[0][0]) / p[0][1]
        for i in range(1, n):
            a, b = p[i]
            nt = (t - a) / b
            if nt > max_t:
                cnt += 1
                max_t = nt

        return cnt


if __name__ == '__main__':
    s = Solution()
    print(s.carFleet(44,
                     [43, 41, 38],
                     [5, 9, 5])
          )
