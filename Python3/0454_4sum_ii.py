# https://leetcode.cn/problems/4sum-ii/

class Solution:
    def fourSumCount(self, nums1, nums2, nums3, nums4):
        """
        Inputs:
            nums1, ..., nums4: list[int]
        Outputs:
            res: int
        """

        '''
        res = 0
        nums3.sort()
        nums4.sort()
        n = len(nums1)
        record = dict()
        for num1 in nums1:
            for num2 in nums2:
                goal = -num1 - num2
                if goal in record:
                    res += record[goal]
                    continue

                tmp = 0
                k, l = 0, n-1
                while k < n and l >= 0:
                    cur = nums3[k] + nums4[l]
                    if cur == goal:
                        cnt_k, cnt_l = 1, 1
                        while k < n-1 and nums3[k] == nums3[k+1]:
                            cnt_k += 1
                            k += 1
                        while l > 0 and nums4[l] == nums4[l-1]:
                            cnt_l += 1
                            l -= 1
                        tmp += (cnt_k * cnt_l)
                        k += 1
                        l -= 1
                    elif cur < goal:
                        k += 1
                    else:
                        l -= 1

                record[goal] = tmp
                res += tmp

        return res
        '''

        # Similar idea but better implementation way.
        res = 0
        record = dict()
        for num1 in nums1:
            for num2 in nums2:
                sum_1_2 = num1 + num2
                record[sum_1_2] = record.get(sum_1_2, 0) + 1

        for num3 in nums3:
            for num4 in nums4:
                res += record.get(-num3-num4, 0)
        return res
