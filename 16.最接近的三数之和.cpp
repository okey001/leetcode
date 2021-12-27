/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0x3fffffff;
        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int s = nums[i] + nums[l] + nums[r];
                if(abs(s - target) < abs(ans - target)){
                    ans = s;
                    
                }
                if(s > target) r --;
                else l ++;
            }
        }
        return ans;
    }
};
// @lc code=end

