from typing import List


class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        h = len(nums) // 2
        ls = set()
        rs = set()
        nums.sort()
        for i in range(0, len(nums)):
            num = nums[i]
            if len(ls) < len(rs):
                ls.add(num)
            else:
                rs.add(num)

        return len(ls) == len(rs) == h


if __name__ == '__main__':
    s = Solution()
    print(s.isPossibleToSplit([8, 9, 8, 5, 9, 3, 3, 1, 2, 1]))
