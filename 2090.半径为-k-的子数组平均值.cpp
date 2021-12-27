/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        long long sum = 0, n = nums.size();
        for(int i = 0; i < k; i++) if(i<n)sum += nums[i];
        for(int i = 0; i < n; i++){
            int l = i - k, r = i + k;
            if(l - 1 >= 0) sum -= nums[l - 1];
            if(r < n) sum += nums[r];
            if(l < 0 || r >= n) ans.push_back(-1);
            else{
                ans.push_back(sum / (k * 2 + 1));
            }
        }
        return ans;
    }
};
// @lc code=end

