// https://leetcode.cn/problems/next-greater-node-in-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};
