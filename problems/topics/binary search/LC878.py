import math

class Solution:
    def lcm(self, a, b):
        return abs(a * b) // math.gcd(a, b)

    def is_nth(self, n: int, x: int, a: int, b: int):
        if a % b == 0:
            return x // b < n

        if b % a == 0:
            return x // a < n

        m = self.lcm(a, b)
        return x // a + x // b - x // m < n

    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        mod = 10 ** 9 + 7
        l, r = 1, 10 ** 19

        while r - l > 1:
            m = l + (r - l) // 2
            if self.is_nth(n, m, a, b):
                l = m
            else:
                r = m

        return r % mod


if __name__ == '__main__':
    s = Solution()
    print(s.nthMagicalNumber(1000000000, 40000, 40000))
