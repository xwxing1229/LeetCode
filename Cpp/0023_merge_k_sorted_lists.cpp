// https://leetcode.cn/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ListNode *res = nullptr;
        // for (auto &ln: lists) {
        //     res = mergeTwoLists(res, ln);
        // }
        // return res;
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(vector<ListNode*> &lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        else if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right));
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(), *cur = new ListNode();
        head->next = cur;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) {
            cur->next = l1;
        }
        if (l2 != nullptr) {
            cur->next = l2;
        }
        return head->next->next;
    }
};