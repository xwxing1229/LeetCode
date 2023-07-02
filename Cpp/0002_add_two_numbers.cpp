// https://leetcode.cn/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = l1;
        ListNode *cur = l1;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int s = l1->val + l2->val + carry;
            l1->val = s % 10;
            carry = s / 10;

            cur = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr && l2 == nullptr && carry > 0) {
            cur->next = new ListNode(1);
        }
        else if (l1 == nullptr && l2 != nullptr) {
            cur->next = l2;
            l1 = cur->next;
        }
        while (l1 != nullptr) {
            int s = l1->val + carry;
            l1->val = s % 10;
            carry = s / 10;

            cur = l1;
            l1 = l1->next;
        }
        if (carry > 0) {
            cur->next = new ListNode(1);
        }
        return res;
    }
};