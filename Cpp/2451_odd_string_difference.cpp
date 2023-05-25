// https://leetcode.cn/problems/odd-string-difference/

class Solution {
public:
    string oddString(vector<string>& words) {
        for (int i = 0; i < words[0].size() - 1; ++i) {
            int diff = words[0][i+1] - words[0][i];
            int cnt = 1;
            for (int j = 1; j < words.size(); ++j) {
                if (diff == words[j][i+1] - words[j][i]) {
                    cnt += 1;
                }
                else if (cnt == 1 && j == 1 &&diff != words[j+1][i+1] - words[j+1][i]) {
                    return words[0];
                }
                else {
                    return words[j];
                }
            }
        }
        return "Invalid input";
    }
};