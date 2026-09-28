// https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> prev;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                prev.push_back(i);
            }
            else if (s[i] == ')') {
                int begin = prev.back() + 1;
                int end = i - 1;
                int tmp = begin + end;
                for (int left = begin; left < (tmp+1)/2; ++left) {
                    swap(s[left], s[tmp-left]);
                }
                prev.pop_back();
            }
        }
        string res;
        res.reserve(s.size());
        for (char ch: s) {
            if (ch != '(' && ch != ')') {
                res.push_back(ch);
            }
        }
        return res;
    }
};