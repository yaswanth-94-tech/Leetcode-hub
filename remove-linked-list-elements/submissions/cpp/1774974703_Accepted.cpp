class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Remove nodes from the beginning (head)
        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            if(temp->val == val){
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};