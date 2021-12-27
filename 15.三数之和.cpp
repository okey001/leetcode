/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                if (l == i) l++;
                else if (r == i) r--;
                else if(nums[l] + nums[r] < target){
                    l++;
                }
                else if (nums[l] + nums[r] > target){
                    r--;
                }
                else{
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    while(l<r && nums[l] == nums[l - 1]) l++;
                    r--;
                    while(l<r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

