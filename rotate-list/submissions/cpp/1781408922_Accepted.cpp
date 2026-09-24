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
        if(head==NULL || k==0){
            return head;
        }
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==1){
            return head;
        }
        int len=count;
        count=k%len;
        if(count==0){
            return head;
        }

        temp=head;
        for(int i=0;i<len-1-count;i++){
            temp=temp->next;
        }
        ListNode* newhead=temp->next;
        ListNode* tail=newhead;
        while(tail && tail->next){
            tail=tail->next;
        }
        temp->next=nullptr;
        tail->next=head;
        return newhead;
    }
};