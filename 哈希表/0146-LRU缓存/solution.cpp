#include <cassert>
#include <iostream>
#include <map>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* pre;
    Node():val(-1) , next(nullptr), pre(nullptr){
    }
    Node(int value): val(value), next(nullptr), pre(nullptr){
    }
};


class LRUCache {
public:
    LRUCache(int) {
        map<int,int> m;
        Node* head = new Node();
        Node* tail = new Node();
        head = tail;
    }

    int get(int) {
        return -1;
    }

    void put(int, int) {
    }
};

int main() {
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
