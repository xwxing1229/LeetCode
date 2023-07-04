// https://leetcode.cn/problems/add-two-numbers-ii/

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
        string num1, num2;
        while (l1 != nullptr) {
            num1 += '0' + l1->val;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            num2 += '0' + l2->val;
            l2 = l2->next;
        }
        if (num1.size() < num2.size()) {
            int n = num1.size();
            num1 += num2;
            num2 = num1.substr(0, n);
            num1 = num1.substr(n);
        }
        int n1 = num1.size(), n2 = num2.size();
        int i = n1-1, j = n2-1;
        int carry = 0;
        while (j >= 0) {
            int s = num1[i] - '0' + num2[j] - '0' + carry;
            num1[i] = '0' + (s % 10);
            carry = s / 10;
            i -= 1;
            j -= 1;
        }
        while (i >= 0) {
            int s = num1[i] - '0' + carry;
            num1[i] = '0' + (s % 10);
            carry = s / 10;
            i -= 1;
        }

        ListNode *cur = new ListNode(1);
        ListNode *dummy = new ListNode(0, cur);
        for (char ch: num1) {
            ListNode *tmp = new ListNode(ch-'0');
            cur->next = tmp;
            cur = cur->next;
        }
        if (carry > 0) {
            return dummy->next;
        }
        else {
            return dummy->next->next;
        }
    }
};