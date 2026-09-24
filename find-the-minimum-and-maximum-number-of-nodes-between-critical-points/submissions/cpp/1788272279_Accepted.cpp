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
    bool criticnode(ListNode* n1, ListNode* n2, ListNode* n3) {
        if (n2->val > n3->val && n1->val < n2->val) {
            return true;
        }
        if (n2->val < n3->val && n1->val > n2->val) {
            return true;
        } else {
            return false;
        }
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        int i = 1;
        int firstnode = 0;
        int latestnode = 0;
        int mini = 1e9;
        int maxi = -1;
        while (next) {

            if (criticnode(prev, curr, next) == true) {
                if (firstnode == 0) {
                    firstnode = i;
                    latestnode = i;
                } else {
                    mini = min(mini,i - latestnode);
                    latestnode = i;
                    maxi = i - firstnode;
                    
                }
            }
            prev=curr;
            curr=next;
            next=next->next;
            i++;
        }
        if(mini==1e9) mini=-1;
        return {mini,maxi};
    }
};