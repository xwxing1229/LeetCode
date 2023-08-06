// https://leetcode.cn/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(), *cur = new ListNode();
        dummy->next = cur;
        cur->next = head;
        while (head != nullptr && head->next != nullptr) {
            ListNode *tmp = head->next;
            cur->next = tmp;
            head->next = tmp->next;
            tmp->next = head;
            cur = head;
            head = head->next;
        }
        return dummy->next->next;
    }
};