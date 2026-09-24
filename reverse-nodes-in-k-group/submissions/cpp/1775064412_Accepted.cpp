class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* kthnode(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;

        while (temp != NULL) {
            ListNode* kthnodeadd = kthnode(temp, k);

            // If less than k nodes left
            if (kthnodeadd == NULL) {
                if (prevnode) {
                    prevnode->next = temp;
                }
                break;
            }

            ListNode* nextnode = kthnodeadd->next;

            // disconnect
            kthnodeadd->next = NULL;

            // reverse current group
            ListNode* newHead = reverse(temp);

            // connect with previous part
            if (temp == head) {
                head = newHead;
            } else {
                prevnode->next = newHead;
            }

            // update prevnode (old head becomes tail)
            prevnode = temp;

            // move temp forward
            temp = nextnode;
        }

        return head;
    }
};