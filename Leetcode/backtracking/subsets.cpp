#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> sub;

    void subs(vector<int> &nums, vector<int> at, int idx) {
        sub.push_back(at);
        for (int i = idx; i < nums.size(); i++) {
            at.push_back(nums[i]);
            subs(nums, at, i + 1);
            at.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subs(nums, vector<int>(), 0);
        return sub;
    }
};

int main () {
    Solution s();
    vector<int> v = {1, 2, 3};

    vector<vector<int>> subs = Solution().subsets(v);

    for (int i = 0; i < subs.size(); i++) {
        for (int &j : subs[i]) cout << j << " ";
        cout << "\n";
    }
}