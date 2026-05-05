// https://leetcode.cn/problems/rotate-list/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode *next): val(x), next(next) {};
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int n = 1;
        ListNode *curr = head;
        while (curr->next) {
            n += 1;
            curr = curr->next;
        }
        k %= n;

        curr->next = head;

        ListNode *last = head;
        for (int i = 0; i < n-k-1; ++i) {
            last = last->next;
        }
        ListNode *res = last->next;
        last->next = nullptr;
        return res;
    }
};