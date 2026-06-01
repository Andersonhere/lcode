#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(const vector<int>& nums) {
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int x : nums) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    }
};

int main() {
    Solution solution;

    // 示例 1: [1,2,3,4,5], k=2 -> [2,1,4,3,5]
    {
        ListNode* head = buildList({1, 2, 3, 4, 5});
        ListNode* result = solution.reverseKGroup(head, 2);
        assert(listToVector(result) == vector<int>({2, 1, 4, 3, 5}));
        freeList(result);
    }

    // 示例 2: [1,2,3,4,5], k=3 -> [3,2,1,4,5]
    {
        ListNode* head = buildList({1, 2, 3, 4, 5});
        ListNode* result = solution.reverseKGroup(head, 3);
        assert(listToVector(result) == vector<int>({3, 2, 1, 4, 5}));
        freeList(result);
    }

    // 示例 3: [1,2,3,4,5], k=1 -> [1,2,3,4,5]
    {
        ListNode* head = buildList({1, 2, 3, 4, 5});
        ListNode* result = solution.reverseKGroup(head, 1);
        assert(listToVector(result) == vector<int>({1, 2, 3, 4, 5}));
        freeList(result);
    }

    // k 等于链表长度: [1,2,3,4], k=4 -> [4,3,2,1]
    {
        ListNode* head = buildList({1, 2, 3, 4});
        ListNode* result = solution.reverseKGroup(head, 4);
        assert(listToVector(result) == vector<int>({4, 3, 2, 1}));
        freeList(result);
    }

    // 单节点: [1], k=1 -> [1]
    {
        ListNode* head = buildList({1});
        ListNode* result = solution.reverseKGroup(head, 1);
        assert(listToVector(result) == vector<int>({1}));
        freeList(result);
    }

    cout << "所有测试用例通过！" << endl;
    return 0;
}
