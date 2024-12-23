// https://leetcode.cn/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (int val: arr) {
            cnts[val] += 1;
        }
        priority_queue<int> pq;
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            pq.push(it->second);
        }
        int res = 0, half = (arr.size() + 1) / 2, cnt = 0;
        while (cnt < half) {
            cnt += pq.top();
            pq.pop();
            res += 1;
        }
        return res;
    }
};