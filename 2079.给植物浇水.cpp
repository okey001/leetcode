/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cur = capacity;
        int pos = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(cur < plants[i]){
                ans += i + i;
                cur = capacity;
            }
            ans ++;
            cur -= plants[i];
            pos = i;
        }
        return ans;
    }
};
// @lc code=end

