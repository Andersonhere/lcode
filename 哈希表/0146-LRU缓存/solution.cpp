#include <cassert>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class LRUCache
{
    class Node
    {
    public:
        int val;
        Node *next;
        Node *pre;
        Node()
            : val(-1)
            , next(nullptr)
            , pre(nullptr)
        {
        }
        Node(int value)
            : val(value)
            , next(nullptr)
            , pre(nullptr)
        {
        }
    };
    unordered_map<int, Node *> m;
    int cap;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity)
        : cap(capacity)
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key)
    {
        if (m.find(key) != m.end()) {
            // Move the node to the head
            Node *node = m[key];
            if (node->pre) {
                node->pre->next = node->next;
            }
            if (node->next) {
                node->next->pre = node->pre;
            }
            node->next = head->next;
            node->pre = head;
            head->next->pre = node;
            head->next = node;
            return m[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end()) {
            // Update existing key
            m[key]->val = value;
            // Move the node to the head
            Node *node = m[key];
            if (node->pre) {
                node->pre->next = node->next;
            }
            if (node->next) {
                node->next->pre = node->pre;
            }
            node->next = head->next;
            node->pre = head;
            head->next->pre = node;
            head->next = node;
        } else {
            if (m.size() >= cap) {
                // Remove the least recently used item
                Node *last = tail->pre;
                tail->pre = last->pre;
                last->pre->next = tail;
                m.erase(last->val);
                delete last;
            }
            // Insert the new item
            m[key] = new Node(value);
            Node *node = m[key];
            node->next = head->next;
            node->pre = head;
            head->next->pre = node;
            head->next = node;
        }
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    assert(cache.get(1) == 1);
    cache.put(3, 3);
    assert(cache.get(2) == -1);
    cache.put(4, 4);
    assert(cache.get(1) == -1);
    assert(cache.get(3) == 3);
    assert(cache.get(4) == 4);
    return 0;
}
