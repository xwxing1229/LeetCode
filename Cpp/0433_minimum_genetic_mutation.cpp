// https://leetcode.cn/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        res = bank.size() + 1;
        unordered_set<string> check = {start};
        dfs(end, bank, start, 0, check);
        if (res > bank.size()) {
            return -1;
        }
        return res;
    }

private:
    void dfs(string end, vector<string>& bank, string cur, int cnt,
        unordered_set<string>& check) {
        if (cur == end) {
            if (cnt < res) {
                res = cnt;
            }
            return;
        }

        for (string gene: bank) {
            if (check.find(gene) != check.end()) {
                continue;
            }

            int diff = 0;
            for (int i = 0; i < 8; ++i) {
                if (cur[i] != gene[i]) {
                    diff += 1;
                }
            }
            if (diff == 1) {
                check.insert(gene);
                dfs(end, bank, gene, cnt+1, check);
                check.erase(gene);
            }
        }
    }

    int res;
};
