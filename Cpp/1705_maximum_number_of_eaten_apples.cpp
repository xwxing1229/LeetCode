// https://leetcode.cn/problems/maximum-number-of-eaten-apples/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        using pi = pair<int, int>;
        int res = 0, i = 0, n = apples.size();
        priority_queue<pi, vector<pi>, greater<pi>> valid;
        while (!valid.empty() || i < n) {
            if (i < n && apples[i] > 0) {
                valid.push(make_pair(i+days[i]-1, apples[i]));
            }
            while (!valid.empty()) {
                pi x = valid.top();
                valid.pop();
                if (x.first >= i) {
                    res += 1;
                    if (x.second > 1) {
                        valid.push(make_pair(x.first, x.second-1));
                    }
                    break;
                }
            }
            i += 1;
        }
        return res;
    }
};
