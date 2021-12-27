/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
class Solution {
public:
    int n;
    int result;
    vector<bool> visited;
    bool connected(int a, int b){
        int s = a + b;
        int t = sqrt(s);
        return t * t == s;
    }
    void dfs(int depth, int last, vector<int>& nums){
        if (depth == n){
            result ++;
            return;
        }
        for(int i = 0; i < n; i++){
            if (visited[i]) continue;
            if(i && !visited[i - 1] && nums[i] == nums[i - 1]) continue;
            if(connected(nums[last], nums[i])){
                visited[i] = true;
                dfs(depth + 1, i, nums);
                visited[i] = false;
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        result = 0;
        visited.resize(n);
        for(auto&& v: visited){ v = false; }
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; i ++){
            if(i && nums[i] == nums[i - 1]) continue;
            visited[i] = true;
            dfs(1, i, nums);
            visited[i] = false;
        }
        return result;
    }
};
// @lc code=end

