// https://leetcode.cn/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *res = nullptr, *pre = head;
        while (pre != nullptr) {
            ListNode *tmp = pre->next;
            pre->next = res;
            res = pre;
            pre = tmp;
        }
        return res;
    }
}