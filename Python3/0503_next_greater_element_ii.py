# https://leetcode.cn/problems/next-greater-element-ii/

class Solution:
    def nextGreaterElements(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        n = len(nums)
        res = [-1 for i in range(n)]
        check = [0 for i in range(n)]
        st = []
        for k in range(2):
            for i in range(n-1, -1, -1):
                num = nums[i]
                while st and st[-1] <= num:
                    st.pop()
                if st and not check[i]:
                    res[i] = st[-1]
                    check[i] = 1
                st.append(num)
        return res