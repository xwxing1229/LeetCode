// https://leetcode.cn/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while ((left < n) && (vowels.find(s[left]) == string::npos)) {
                left = left + 1;
            }
            while ((right >= 0) && (vowels.find(s[right]) == string::npos)) {
                right = right - 1;
            }

            if (left >= right) {
                break;
            }

            char ch = s[left];
            s[left] = s[right];
            s[right] = ch;
            left = left + 1;
            right = right - 1;
        }
        return s;
    }
};
