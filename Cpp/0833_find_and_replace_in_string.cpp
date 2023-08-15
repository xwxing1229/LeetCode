// https://leetcode.cn/problems/find-and-replace-in-string/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res;
        vector<int> idxs(indices.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int i, const int j) {
            return indices[i] < indices[j];
        });
        int i = 0, j = 0, n = s.size();
        while (i < n) {
            if (j >= indices.size()) {
                res += s.substr(i);
                break;
            }
            else if (i != indices[idxs[j]]) {
                res += s[i];
                i += 1;
            }
            else {
                string source = sources[idxs[j]];
                int len_source = source.size();
                if (i + len_source <= n && s.substr(i, len_source) == source) {
                    res += targets[idxs[j]];
                    i += len_source;
                }
                else {
                    res += s[i];
                    i += 1;
                }
                j += 1;
            }
        }
        return res;
    }
};