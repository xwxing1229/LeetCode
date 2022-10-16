// https://leetcode.cn/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (string line: cpdomains) {
            int num;
            int n = line.size(), idx = 0;
            for (int i = 0; i < n; ++i) {
                if (line[i] == ' ') {
                    num = stoi(line.substr(0, i));
                    idx = i + 1;
                    break;
                }
            }
            for (int i = n-1; i >= idx; --i) {
                if (line[i] == '.') {
                    string web = line.substr(i+1, n-i-1);
                    cnt[web] = cnt[web] + num;
                }
            }
            cnt[line.substr(idx, n-idx)] = cnt[line.substr(idx, n-idx)] + num;
        }

        vector<string> res;
        for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
            string tmp = to_string(iter->second) + ' ' + iter->first;
            res.push_back(tmp);
        }
        return res;
    }
};
