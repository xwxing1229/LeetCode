// https://leetcode.cn/problems/partition-list/

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
    ListNode* deleteDuplicates(ListNode* head, int x) {
        ListNode *small = new ListNode;
        ListNode *small_head = small;
        ListNode *large = new ListNode;
        ListNode *large_head = large;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        small->next = large_head->next;
        large->next = nullptr;
        return small_head->next;
    }
};
