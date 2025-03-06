// https://leetcode.cn/problems/break-a-palindrome/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        int idx = -1;
        for (int i = 0; i < (n+1)/2; ++i) {
            if (palindrome[i] != 'a') {
                idx = i;
                break;
            }
        }
        if ((idx == n / 2 && n % 2 == 1) || idx < 0) {
            palindrome.back() = 'b';
        }
        else {
            palindrome[idx] = 'a';
        }
        return palindrome;
    }
};

int main() {
    Solution sol;
    string palindrome = "abccba";
    cout << sol.breakPalindrome(palindrome) << '\n';
    return 0;
}