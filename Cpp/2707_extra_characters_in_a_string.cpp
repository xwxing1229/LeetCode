// https://leetcode.cn/problems/extra-characters-in-a-string/
        
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        for (int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i-j);
                if (words.find(sub) != words.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};