# https://leetcode-cn.com/problems/permutation-in-string/

class Solution:
    def checkInclusion(self, s1, s2):
        """
        Inputs:
            s1: str
            s2: str
        Outpus:
            res: bool
        """
        
        res = False
        need = {}
        for s in s1:
            need[s] = need.get(s,0) + 1
        
        n1 = len(s1)
        n2 = len(s2)
        win = {} # current window
        for i in range(n2):
            if s2[i] in s1:
                win[s2[i]] = win.get(s2[i],0) + 1
                
            if i >= n1 - 1:
                # The current window meets the requirement.
                if win == need:
                    res = True
                    break
                
                # Remove the leftmost element in the current
                # window.
                if s2[i-n1+1] in s1:
                    win[s2[i-n1+1]] = win[s2[i-n1+1]] - 1
        return res