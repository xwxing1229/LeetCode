// https://leetcode.cn/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> table;
        stack<int> st; // monotone stack
        for (int i = nums2.size()-1; i >= 0; --i) {
            int num = nums2[i];
            while ((st.size() > 0) && (st.top() <= num)) st.pop();

            if (st.size() > 0) table[num] = st.top();
            else table[num] = -1;

            st.push(num);
        }
        vector<int> res;
        for (int num: nums1) res.push_back(table[num]);
        return res;
    }
};
