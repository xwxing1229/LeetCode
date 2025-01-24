// https://leetcode.cn/problems/number-of-visible-people-in-a-queue/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            int height = heights[i];
            while (!st.empty() && st.top() < height) {
                res[i] += 1;
                st.pop();
            }
            if (!st.empty()) {
                res[i] += 1;
            }
            st.push(height);
        }
        return res;
    }
};