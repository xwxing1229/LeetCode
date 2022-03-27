# https://leetcode-cn.com/problems/minimum-window-substring/

class Solution1:
    def minWindow(self, s, t):
        """
        Inputs:
            s: str
            t: str
        Outputs:
            res: str
        """
        
        len_s = len(s)
        len_t = len(t)
        
        need = {} # need = {str: counts}
        for i in t:
            need[i] = need.get(i,0) + 1
        
        # Left and right pointers of the result.
        res_left = 0
        res_right = len_s + 1
        
        win = {} # win = {str: counts}
        right = 0 # right pointer of the current window
        find = False
        for left in range(len_s-len_t+1):
            if left > 0:
                # Remove the leftmost str.
                win[s[left-1]] = win[s[left-1]] - 1
                # Check if the current window meets the requirement.
                if s[left-1] in need and win[s[left-1]] < need[s[left-1]]:
                    find = False
                    # Record the str because of which the requirement
                    # is not met. We will only need to check if this
                    # str is added as we move the right pointer.
                    check = s[left-1]
            
            while not find and right < len_s:
                # Add a str to the current window.
                win[s[right]] = win.get(s[right],0) + 1
                right = right + 1
                
                find = True
                if left == 0:
                    for i in need:
                        # The requirement is not met.
                        if win.get(i,0) < need[i]:
                            find = False
                            break
                else:
                    if check != s[right]:
                        find = False
            
            # If the current window meets the requirement, check if it
            # is shorter.
            if find and (right-left) < (res_right-res_left):
                res_left = left
                res_right = right
        
        # In case that there is no answer.
        if res_right - res_left <= len_s:
            res = s[res_left:res_right]
        else:
            res = ''
        return res