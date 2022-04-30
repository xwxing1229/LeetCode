// https://leetcode-cn.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int l = s.size(), res = table[s[l-1]];
        for (int i = l-2; i >= 0; --i) {
            int key = table[s[i]], key_ = table[s[i+1]];
            if (key < key_) res = res - key;
            else res = res + key;
        }

        return res;
    }
};