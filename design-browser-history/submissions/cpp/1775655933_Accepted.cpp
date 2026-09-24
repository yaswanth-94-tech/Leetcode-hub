class Node {
    public:
    string data;
    Node* next;
    Node* back;
    // Node() : data(""), next(nullptr), back(nullptr) {}
    // Node(string x) : data(x), next(nullptr), back(nullptr) {}
    Node(){
        data="";
        next=nullptr;
        back=nullptr;
    }
    Node(string x){
        data=x;
        next=nullptr;
        back=nullptr;
    }
};
class BrowserHistory {
public:
    Node* currentpage;
    BrowserHistory(string homepage) { currentpage = new Node(homepage); }

    void visit(string url) {
        // 🔴 Step 1: delete all forward histor
        Node* temp = currentpage->next;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        currentpage->next = nullptr;

        // 🟢 Step 2: add new pag
        Node* newnode = new Node(url);
        currentpage->next = newnode;
        newnode->back = currentpage;
        currentpage = newnode;
    }

    string back(int steps) {
        while (steps--) {
            if (currentpage->back) {
                currentpage = currentpage->back;
            } else {
                break;
            }
        }
        return currentpage->data;
    }

    string forward(int steps) {
        while (steps--) {
            if (currentpage->next) {
                currentpage = currentpage->next;
            } else {
                break;
            }
        }
        return currentpage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */