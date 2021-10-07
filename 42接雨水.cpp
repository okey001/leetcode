/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int last = 0;
        int n = height.size();
        vector<int> left(n), right(n);
        for (int i=0; i<height.size(); i++) {
            if (height[i] > last) last = height[i];
            left[i] = last;
        }
        last = 0;
        for (int i=height.size() - 1; i>=0; i--) {
            if (height[i] > last) last = height[i];
            right[i] = last;
        }
        int ans = 0;
        for (int i=0; i<height.size();i++){
            int min = left[i] < right[i] ? left[i] : right[i];
            ans += min - height[i]; 
        }
        return ans;
    }
    
};
// @lc code=end

int main(){
    Solution s;
    vector<int> a{0, 1, 1, 1};
    s.trap(a);
    return 0;
}