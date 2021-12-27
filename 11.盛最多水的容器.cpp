/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r){
            int h;
            if (height[l] < height[r]){
                h = height[l];
                l++;
            }
            else{
                h = height[r];
                r--;
            }
            int count = (r - l + 1) * h;
            if (count > ans) ans = count;
        }
        return ans;
    }
};
// @lc code=end

