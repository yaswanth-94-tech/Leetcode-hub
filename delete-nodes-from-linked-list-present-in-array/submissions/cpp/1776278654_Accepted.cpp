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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(begin(nums), end(nums));
        // handling head;
        while (head != NULL && set.find(head->val) != set.end()) {
            
            head = head->next;
            
        }
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (set.find(curr->next->val) != set.end()) {
                
                curr->next = curr->next->next;
                

            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};