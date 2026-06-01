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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode *next = nullptr;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main() {
    Solution solution;

    // 示例 1: [1,2,3,4,5] -> [5,4,3,2,1]
    {
        ListNode* head = buildList({1, 2, 3, 4, 5});
        ListNode* reversed = solution.reverseList(head);
        assert(listToVector(reversed) == vector<int>({5, 4, 3, 2, 1}));
        freeList(reversed);
    }

    // 示例 2: [1,2] -> [2,1]
    {
        ListNode* head = buildList({1, 2});
        ListNode* reversed = solution.reverseList(head);
        assert(listToVector(reversed) == vector<int>({2, 1}));
        freeList(reversed);
    }

    // 示例 3: [] -> []
    {
        ListNode* head = nullptr;
        ListNode* reversed = solution.reverseList(head);
        assert(reversed == nullptr);
    }

    // 单节点: [1] -> [1]
    {
        ListNode* head = buildList({1});
        ListNode* reversed = solution.reverseList(head);
        assert(listToVector(reversed) == vector<int>({1}));
        freeList(reversed);
    }

    cout << "所有测试用例通过！" << endl;
    return 0;
}
