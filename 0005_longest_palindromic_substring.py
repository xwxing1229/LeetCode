# https://leetcode-cn.com/problems/longest-palindromic-substring/
    
class Solution:
    '''
    def longestPalindrome(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        
        # Dynamic programming.
        # If s[i] = s[j], then s[i:j+1] is a palindrome iff s[i+1:j]
        # is a palindrome.
        # dp[i][j] = True: s[i:j+1] is a palindrome.
        # dp[i][j] = False: s[i:j+1] is not a palindrome.
        # dp[i][j] is decided by dp[i+1][j-1].
        
        start = 0 # start pointer of the longest palindrome
        max_len = 1
        
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        
        for j in range(1,n):
            for i in range(0,j):
                if s[i] == s[j]:
                    if j - i > 2:
                        dp[i][j] = dp[i+1][j-1]
                    else:
                        dp[i][j] = True
                
                # Check if we need to update the longest palindrome.
                if dp[i][j] == True and j - i + 1 > max_len:
                    max_len = j - i + 1
                    start = i
                    
        res = s[start: start+max_len]
        return res
    '''

    
    def longestPalindrome(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        
        start = 0
        max_len = 1
        
        n = len(s)
        for mid in range(n-1):
            # Get palindromes of even and odd length, with mid
            # being the middle element.
            even_len, even_start = self.get_pal(s, mid, n, even=1)
            odd_len, odd_start = self.get_pal(s, mid, n, even=0)
            
            if even_len > odd_len and even_len > max_len:
                max_len = even_len
                start = even_start
            elif odd_len > even_len and odd_len > max_len:
                max_len = odd_len
                start = odd_start
        
        res = s[start: start+max_len]
        return res
    
    def get_pal(self, s, mid, n, even):
        tmp_len = 0
        tmp_start = 0
        if even:
            if s[mid] == s[mid+1]:
                tmp_len = 2
                i = mid - 1
                j = mid + 2
                while i >= 0 and j < n:
                    if s[i] == s[j]:
                        tmp_len = tmp_len + 2
                        i = i - 1
                        j = j + 1
                    else:
                        break
                tmp_start = i + 1
        else:
            if mid > 0 and s[mid-1] == s[mid+1]:
                tmp_len = 3
                i = mid - 2
                j = mid + 2
                while i >= 0 and j < n:
                    if s[i] == s[j]:
                        tmp_len = tmp_len + 2
                        i = i - 1
                        j = j + 1
                    else:
                        break
                tmp_start = i + 1
        return tmp_len, tmp_start
    

a = Solution()
print(a.longestPalindrome('ababd'))