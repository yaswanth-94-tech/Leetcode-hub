#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    // Doubly linked list node
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = prev = NULL;
        }
    };

    Node* head;
    Node* tail;

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // insert right after head (most recent)
    void addNode(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    // remove node from list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        Node* node = m[key];
        int value = node->val;

        // move to front (most recently used)
        deleteNode(node);
        addNode(node);

        m[key] = head->next;

        return value;
    }

    void put(int key, int value) {
        // if already exists → remove old node
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        // if capacity full → remove LRU (before tail)
        if (m.size() == cap) {
            Node* lru = tail->prev;

            m.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        // insert new node at front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};