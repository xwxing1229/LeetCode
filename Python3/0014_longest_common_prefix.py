# https://leetcode-cn.com/problems/longest-common-prefix/

class Solution: 
    def longestCommonPrefix(self, strs:List[str]) -> str:
        if strs == []:
            return ''
        
        nums = []
        for i in range(len(strs)):
            nums.append(len(strs[i]))
        min_len = min(nums)
        if min_len == 0:
            return ''
        
        for i in range(min_len):
            tmp = strs[0][i]
            for j in range(1,len(strs)):
                if tmp != strs[j][i]:
                    return strs[0][:i]
        return strs[0][:i+1]
