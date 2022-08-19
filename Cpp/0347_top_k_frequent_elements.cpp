// https://leetcode.cn/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num] = count[num] + 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;

        for (auto& x: count) {
            q.push(x);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }

private:
    struct comp {
        bool operator()(pair<int,int>& p1, pair<int,int>& p2) {
            return p1.second > p2.second;
        }
    };
};
