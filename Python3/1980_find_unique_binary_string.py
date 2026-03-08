# https://leetcode.cn/problems/find-unique-binary-string/

class Solution:
    def findDifferentBinaryString(self, nums: list[str]) -> str:
        nums.sort()
        n = len(nums)
        for num in range(1<<n):
            tar = bin(num)[2:]
            tar = "0" * (n - len(tar)) + tar
            left, right = 0, n-1
            find = False
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] < tar:
                    left = mid + 1
                elif nums[mid] > tar:
                    right = mid - 1
                else:
                    find = True
                    break
            if not find:
                return tar
        return "0" * n