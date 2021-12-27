/*
 * @lc app=leetcode.cn id=2087 lang=cpp
 *
 * [2087] 网格图中机器人回家的最小代价
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int s = startPos[0], t = homePos[0];
        if(s > t){int temp = s; s = t; t = temp;}
        int ans = 0;
        for(int i = s; i <= t; i ++) ans += rowCosts[i];
        s = startPos[1];
        t = homePos[1];
        if(s > t){int temp = s; s = t; t = temp;}
        for(int i = s; i <= t; i ++) ans += colCosts[i];
        return ans - rowCosts[startPos[0]] - colCosts[startPos[1]];

    }
};
// @lc code=end

