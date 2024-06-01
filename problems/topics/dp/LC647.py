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
    def countSubstrings(self, s: str) -> int:
        # f(i) number of palindromic substring of s[0:i]
        # f(i) = f(i - 1) + num_palindrome(mid at i) + num_palindrome(mid at i - 1 and i)

        n = len(s)
        last_cnt = 1
        for i in range(1, n):
            cnt = 0
            (l, r) = self.get_palindrome(s, i, i)
            cnt += math.ceil((r - l + 1) / 2)

            (l, r) = self.get_palindrome(s, i - 1, i)
            cnt += (r - l + 1) // 2

            last_cnt = last_cnt + cnt

        return last_cnt



if __name__ == '__main__':
    sol = Solution()
    print(sol.countSubstrings("aaabab"))
