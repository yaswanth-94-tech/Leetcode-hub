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
    ListNode* findlastnode(ListNode* head,int n){
        int count=1;
        ListNode* temp1=head;
        while(count<n){
            temp1=temp1->next;
            count++;
        }
        return temp1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int length=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }
        if(k%length==0){
            return head;
        }
        k=k%length;
        ListNode* newlastnode=findlastnode(head,length-k);
        temp->next=head;
        ListNode* newhead=newlastnode->next;
        newlastnode->next=NULL;
        return newhead;
    }
};