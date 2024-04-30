import math
from typing import List


class Solution:
    def minKBitFlips(self, a: List[int], k: int) -> int:
        n = len(a)

        is_f = [False] * n
        all_f, curr_f = 0, 0
        i = 0
        for i in range(0, n):
            if i >= k and is_f[i - k]:
                curr_f -= 1

            if (a[i] == 0 and curr_f % 2 == 0) or (a[i] == 1 and curr_f % 2 == 1):
                if i + k > n:
                    return -1

                curr_f += 1
                all_f += 1
                is_f[i] = True

        return all_f


if __name__ == '__main__':
    s = Solution()
    print(s.minKBitFlips([0, 0, 0, 1, 1],
                         3))
