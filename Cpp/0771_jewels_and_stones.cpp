// https://leetcode.cn/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for (char ch: jewels) {
            s.insert(ch);
        }
        int res = 0;
        for (char ch: stones) {
            if (s.find(ch) != s.end()) {
                res += 1;
            }
        }
        return res;
    }
};