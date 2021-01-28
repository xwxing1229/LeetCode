# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        
        '''
        left = 0
        right = 0
        len_s = len(s)
        res = 0
        while left < len_s:
            app = []
            # Check if next string has appeared.
            while right < len_s and s[right] not in app:
                app.append(s[right])
                right = right + 1
            res = max(res, right-left)
            
            left = left + 1
            right = left
        return res
        '''
        
        # Sliding window algorithm.
        app = set() # app records strings that have appeared
        n = len(s)
        right = 0 # right pointer
        res = 0
        for i in range(n):
            if i != 0:
                app.remove(s[i-1]) # remove a string
            while right < n and s[right] not in app:
                app.add(s[right])
                right = right + 1
            
            res = max(res, right-i)
        return res