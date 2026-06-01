#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
using namespace std;

/*
//set

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) {
            return 0;
        }
        int l = 0;
        std::set<char> windows;
        int ans = 0;
        for (int r = 0; r < static_cast<int>(s.length());) {
            while(windows.count(s[r])) {
                windows.erase(s[l]);
                l++;
            }
            windows.insert(s[r]);
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

*/

/*
//map

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) {
            return 0;
        }
        int l = 0;
        std::map<char, int> windows;
        int ans = 0;
        for (int r = 0; r < s.length();) {
            if (windows.count(s[r]) && windows[s[r]] >= l) {
                l = windows[s[r]] + 1;
            }
            windows[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

*/


//arrary

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) {
            return 0;
        }
        vector<int> pos_index(128, -1);
        int l = 0;
        int ans = 0;
        for (int r = 0; r < s.length(); r++) {
            if (pos_index[s[r]] >= l) {
                l = pos_index[s[r]] + 1;
            }
            pos_index[s[r]] = r ;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solution.lengthOfLongestSubstring("bbbbb") == 1);
    assert(solution.lengthOfLongestSubstring("pwwkew") == 3);
    assert(solution.lengthOfLongestSubstring("") == 0);
    assert(solution.lengthOfLongestSubstring(" ") == 1);
    assert(solution.lengthOfLongestSubstring("abba") == 2);
    assert(solution.lengthOfLongestSubstring("au") == 2);
    return 0;
}
