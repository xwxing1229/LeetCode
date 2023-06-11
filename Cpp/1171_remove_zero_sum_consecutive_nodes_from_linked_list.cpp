// https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        int cumsum = 0;
        unordered_map<int, ListNode*> seen;
        seen[0] = dummy;
        while (head) {
            cumsum += head->val;
            seen[cumsum] = head;
            head = head->next;
        }
        head = dummy;
        cumsum = 0;
        while (head) {
            cumsum += head->val;
            head->next = seen[cumsum]->next;
            head = head->next;
        }
        return dummy->next;
    }
};