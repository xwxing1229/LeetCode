// https://leetcode.cn/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        vector<int> check(n);
        stack<int> st;
        for (int k = 0; k < 2; ++k) {
            for (int i = n-1; i >= 0; --i) {
                int num = nums[i];
                while (!st.empty() && st.top() <= num) {
                    st.pop();
                }
                if (!st.empty() && !check[i]) {
                    res[i] = st.top();
                    check[i] = 1;
                }
                st.push(num);
            }
        }
        return res;
    }
};

