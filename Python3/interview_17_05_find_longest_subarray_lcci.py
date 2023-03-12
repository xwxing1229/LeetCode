# https://leetcode.cn/problems/find-longest-subarray-lcci/

class Solution:
    def findLongestSubarray(self, array):
        """
        Inputs:
            array: list[str]
        Outputs:
            res: list[str]
        """
        start, length = -1, 0
        record = {0: -1}
        diff = 0 # cnt_digits - cnt_letters
        for i, ch in enumerate(array):
            if ch.isdigit():
                diff += 1
            else:
                diff -= 1
            
            if diff in record:
                if i - record[diff] > length:
                    start = record[diff] + 1
                    length = i - record[diff]
            else:
                record[diff] = i
        
        return array[start: start + length]