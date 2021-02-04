# https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

class Solution:
    def letterCombinations(self, digits):
        """
        Inputs:
            digits: str
        Outputs:
            res: list[str]
        """
        
        '''
        if not digits:
            return []
        
        # Digit-string map.
        m = ['', '*', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = []
        
        def backtracking(tmp, idx):
            if idx == len(digits):
                res.append(tmp)
                return
            
            digit = digits[idx] # current digit
            # Letters corresponding to the current digit.
            letters = m[ord(digit) - ord('0')]
            
            for i in letters:
                backtracking(tmp+i, idx+1)
        
        backtracking('', 0)
        return res
        '''
        
        if not digits:
            return []
        
        # Digit-string map.
        m = ['', '*', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = ['']
        for i in digits:
            # Letters corresponding to the current digit.
            letters = m[ord(i) - ord('0')]
            for _ in range(len(res)):
                tmp = res.pop(0)
                for j in letters:
                    res.append(tmp+j)
        return res