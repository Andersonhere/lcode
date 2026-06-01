#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //建堆

        //堆排序
    }
};

int main() {
    Solution solution;

    // 示例 1: [3,2,1,5,6,4], k=2 -> 5
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        assert(solution.findKthLargest(nums, 2) == 5);
    }

    // 示例 2: [3,2,3,1,2,4,5,5,6], k=4 -> 4
    {
        vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        assert(solution.findKthLargest(nums, 4) == 4);
    }

    // 单元素: [1], k=1 -> 1
    {
        vector<int> nums = {1};
        assert(solution.findKthLargest(nums, 1) == 1);
    }

    // k等于数组长度（找最小元素）
    {
        vector<int> nums = {7, 2, 9, 1, 5};
        assert(solution.findKthLargest(nums, 5) == 1);
    }

    // 有重复元素: [2,2,2,2], k=3 -> 2
    {
        vector<int> nums = {2, 2, 2, 2};
        assert(solution.findKthLargest(nums, 3) == 2);
    }

    cout << "所有测试用例通过！" << endl;
    return 0;
}
