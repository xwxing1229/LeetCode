// https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/
        
class Solution {
public:
    int minLength(string s) {
        int n = s.size(), i = 0;
        int res = n;
        vector<int> remove(n, 0);
        while (i < n-1) {
            if (s.substr(i,2) == "AB" || s.substr(i,2) == "CD") {
                res -= 2;
                remove[i] = 1;
                remove[i+1] = 1;
                int left = i, right = i+1;
                while (left >= 0 && right < n) {
                    while (left >= 0 && remove[left] == 1) {
                        left -= 1;
                    }
                    while (right < n && remove[right] == 1) {
                        right += 1;
                    }
                    if (left >= 0 && right < n) {
                        string tmp(1, s[left]);
                        tmp += s[right];
                        if (tmp == "AB" || tmp == "CD") {
                            res -= 2;
                            remove[left] = 1;
                            remove[right] = 1;
                        }
                        else {
                            break;
                        }
                    }
                }
                i = right;
            }
            else {
                i += 1;
            }
        }
        return res;
    }
};
