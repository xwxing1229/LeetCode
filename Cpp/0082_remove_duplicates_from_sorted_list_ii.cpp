// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *tmp = new ListNode;
        ListNode *res = new ListNode(0, tmp);
        ListNode *cur = head;
        int cnt = 1;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cnt = cnt + 1;
            }
            else if (cnt < 2) {
                tmp->next = cur;
                tmp = tmp->next;
                cnt = 1;
            }
            else {
                cnt = 1;
            }

            cur = cur->next;
        }

        if (cnt < 2) {
            tmp->next = cur;
        }
        else {
            tmp->next = nullptr;
        }

        return res->next->next;
    }
};
