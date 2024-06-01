import collections
import heapq
import math
from typing import List


class Solution:
    def get_palindrome(self, s, l, r):
        n = len(s)
        l, r = l, r
        while l >= 0 and r < n:
            if s[l] != s[r]:
                break
            l -= 1
            r += 1

        return l + 1, r - 1

    def longestPalindrome(self, s: str) -> str:
        # f(i) longest palindrome with mid at i
        # f(i) = max(f(i - 1), [l, r]) if s[l, r] with mid at i is palindrome
        #      = f(i - 1)

        n = len(s)
        span = (0, 0)
        for i in range(1, n):
            (l, r) = self.get_palindrome(s, i, i)

            (le, re) = self.get_palindrome(s, i, i + 1)
            if re - le + 1 > r - l + 1:
                r, l = re, le

            (le, re) = self.get_palindrome(s, i - 1, i)
            if re - le + 1 > r - l + 1:
                r, l = re, le

            if span[1] - span[0] + 1 < r - l + 1:
                span = (l, r)

        return s[span[0]:span[1] + 1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.longestPalindrome("cbbd"))
