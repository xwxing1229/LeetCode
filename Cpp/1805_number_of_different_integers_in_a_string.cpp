// https://leetcode.cn/problems/number-of-different-integers-in-a-string/

class Solution {
public:
    int numDifferentIntegers(string word) {
        string num = "";
        unordered_set<string> s;
        word += 'a';
        for (char ch: word) {
            if (isdigit(ch)) {
                if (num == "0") {
                    num = ch;
                }
                else {
                    num += ch;
                }
            }
            else if (num != "") {
                s.emplace(num);
                num.clear();
            }
        }
        return s.size();
    }
};
