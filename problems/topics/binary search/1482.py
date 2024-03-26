from typing import List


class Solution:
    def is_posible(self, b: List[int], m: int, k: int, d: int):
        curr_b = 0
        curr_f = 0
        for i in range(0, len(b)):
            if b[i] > d:
                curr_f = 0
                continue

            curr_f += 1
            if curr_f == k:
                curr_f = 0
                curr_b += 1

        return curr_b < m

    def minDays(self, b: List[int], m: int, k: int) -> int:
        if m * k > len(b):
            return -1

        l, r = 0, 10 ** 9
        while r - l > 1:
            mid = l + (r - l) // 2
            if self.is_posible(b, m, k, mid):
                l = mid
            else:
                r = mid

        return r


if __name__ == '__main__':
    s = Solution()
    print(s.minDays([1, 10, 3, 10, 2], 3, 1))
