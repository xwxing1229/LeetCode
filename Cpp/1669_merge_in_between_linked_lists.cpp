// https://leetcode.cn/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1, *cur = list1;
        for (int i = 0; i < a-1; ++i) {
            cur = cur->next;
        }
        ListNode *start = cur;
        for (int i = a-1; i < b; ++i) {
            cur = cur->next;
        }
        ListNode *end = cur->next;
        /* The commented way is slower.
        // ListNode *start, *end;
        // for (int i = 0; i < b; ++i) {
        //     if (i == a - 1) {
        //         start = cur;
        //     }
        //     cur = cur->next;
        // }
        // end = cur->next;
        */

        start->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = end;
        return head;
    }
};