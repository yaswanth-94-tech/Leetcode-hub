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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            length++;
        }
        k = k % length;
        if (k == 0) {
            return head;
        } else {

            temp = head;
            for (int i = 0; i < length-k-1; i++) {
                temp = temp->next;
            }
            ListNode* newhead = temp->next;
            ListNode* tail = head;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = head;
            temp->next = NULL;
            return newhead;
        }
    }
};