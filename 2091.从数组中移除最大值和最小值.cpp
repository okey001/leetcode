/*
 * @lc app=leetcode.cn id=2091 lang=cpp
 *
 * [2091] 从数组中移除最大值和最小值
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxI = 0, minI = 0, n = nums.size();
        for(int i = 0; i < n; i ++){
            if(nums[i] > nums[maxI]) maxI = i;
            if(nums[i] < nums[minI]) minI = i;
        }
        if (maxI < minI){
            swap(maxI, minI);
        }
        int ans = n;
        ans = min(ans, maxI + 1);
        ans = min(ans, minI + 1 + n - maxI);
        ans = min(ans, n - minI);
        return ans;
    }
};
// @lc code=end

