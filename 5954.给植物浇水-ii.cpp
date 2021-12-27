/*
 * @lc app=leetcode.cn id=5954 lang=cpp
 *
 * [5954] 给植物浇水 II
 */

// @lc code=start
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int cA = capacityA, cB = capacityB;
        for(int i = 0; i < plants.size() / 2; i ++){
            int j = plants.size() - i - 1;
            if(plants[i] > cA){
                ans ++;
                cA = capacityA;
            }
            cA -= plants[i];
            if(plants[j] > cB){
                ans ++;
                cB = capacityB;
            }
            cB -= plants[j];
        }
        if(plants.size() % 2){
            int i = plants.size() / 2;
            if(cA >= cB){
                if(plants[i] > cA) ans ++;
            }
            else{
                if(plants[i] > cB) ans ++;
            }
        }
        return ans;
    }
};
// @lc code=end

