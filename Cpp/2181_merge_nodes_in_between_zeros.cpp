// https://leetcode.cn/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *res = new ListNode(0, dummy);

        stack<int> stk;
        stk.push(0);
        ListNode *cur = head->next;
        while (cur != nullptr) {
            if (cur->val != 0) {
                stk.push(cur->val);
            }
            else {
                ListNode *node = new ListNode();
                while (stk.top() != 0) {
                    node->val += stk.top();
                    stk.pop();
                }
                dummy->next = node;
                dummy = dummy->next;
            }
            cur = cur->next;
        }
        return res->next->next;
    }
};