// https://leetcode.cn/problems/strong-password-checker-ii/

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        unordered_set<char> specials = {
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'
        };
        bool lower = false, upper = false, digit = false, special = false;
        for (int i = 0; i < password.size(); ++i) {
            char ch = password[i];
            if ((i > 0) && (ch == password[i-1])) return false;

            if ((ch - 'a' >= 0) && (ch - 'z' <= 0)) lower = true;
            else if ((ch - 'A' >= 0) && (ch - 'Z' <= 0)) upper = true;
            else if (isdigit(ch)) digit = true;
            else if (specials.count(ch)) special = true;
        }
        return lower && upper && digit && special;
    }
};