// https://leetcode.cn/problems/rotate-list/

/**
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(): val(0), next(nullptr) {};
*     ListNode(int x): val(x), next(nullptr) {};
*     ListNode(int x, ListNode *next): val(x), next(next) {};
*  };
**/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ((k == 0) || (!head) || (!head->next)) {
            return head;
        }

        int n = 1;
        ListNode *cur = head;
        while (cur->next) {
            n = n + 1;
            cur = cur->next;
        }

        cur->next = head;
        for (int i = 0; i < n - k % n; ++i) {
            cur = cur->next;
        }
        ListNode *res = cur->next;
        cur->next = nullptr;
        return res;
    }
}