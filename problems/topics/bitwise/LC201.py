import math


class Solution:
    def rangeBitwiseAnd(self, l: int, r: int) -> int:
        if r == 0:
            return 0

        len_ = math.floor(math.log2(r))
        res = 0

        while len_ >= 0:
            bit_at_pos_l = l >> len_ & 1
            bit_at_pos_r = r >> len_ & 1
            if bit_at_pos_l != bit_at_pos_r:
                break

            if bit_at_pos_l == bit_at_pos_r == 1:
                res += 2 ** len_
            len_ -= 1

        return res


if __name__ == '__main__':
    s = Solution()
    print(s.rangeBitwiseAnd(74, 88))
