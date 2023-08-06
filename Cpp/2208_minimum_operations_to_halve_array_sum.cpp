// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int res = 0;
        double half = 0, s = 0;
        priority_queue<double, vector<double>, less<double>> pq;
        for (int num: nums) {
            pq.push(num);
            half += num;
        }
        half /= 2;
        while (s < half) {
            double cur = pq.top() / 2;
            pq.pop();
            s += cur;
            pq.push(cur);
            res += 1;
        }
        return res;
        
    }
};