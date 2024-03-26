import math
from typing import List


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        f = [0, 0, 0]
        for c in s:
            f[ord(c) - ord('a')] += 1
        for c in f:
            if c < k:
                return -1

        c = [0, 0, 0]
        n, ans = len(s), 10 ** 9
        l, r = 0, 0
        while n > r >= l:
            c[ord(s[r]) - ord('a')] += 1
            while f[0] - c[0] < k or f[1] - c[1] < k or f[2] - c[2] < k:
                c[ord(s[l]) - ord('a')] -= 1
                l += 1

            ans = min(ans, (n - r) + l - 1)
            r += 1

        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.takeCharacters('aabaaaacaabc', 2))
