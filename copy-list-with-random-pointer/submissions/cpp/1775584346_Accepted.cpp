/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertnode(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* newnode = new Node(temp->val);
            Node* nextnode = temp->next;
            newnode->next = nextnode;
            temp->next = newnode;
            temp = nextnode;
        }
    }
    void connectrandompointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* coppynode = temp->next;
            if (temp->random) {
                coppynode->random = temp->random->next;
                temp=temp->next->next;
            } else {
                coppynode->random = nullptr;
                temp=temp->next->next;
            }
        }
    }
    Node* deepcopy(Node* head) {
        Node* dummynode = new Node(-1);
        Node* res = dummynode;
        Node* temp = head;
        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummynode->next;
    }

    Node* copyRandomList(Node* head) {
        insertnode(head);
        connectrandompointers(head);
        return deepcopy(head);
    }
};