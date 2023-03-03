// https://leetcode.cn/problems/making-file-names-unique/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> records;
        for (auto &name: names) {
            if (records.find(name) != records.end()) {
                int i = records[name];
                while (true) {
                    string tmp = name + '(' + to_string(i) + ')';
                    if (records.find(tmp) == records.end()) {
                        res.push_back(tmp);
                        records[tmp] = 1;
                        records[name] = i + 1;
                        break;
                    }
                    i += 1;
                }
            }
            else {
                res.push_back(name);
                records[name] = 1;
            }
        }
        return res;
    }
};
