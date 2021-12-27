/*
 * @lc app=leetcode.cn id=5935 lang=cpp
 *
 * [5935] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int l = 1, r = 1;
        vector<int> ans;
        for(int i = 0; i < security.size(); i++) {
            int j = i - time;
            if(j > 0 && security[j - 1] >= security[j]) l ++;
            else l = 1;
            if(i > 0 && security[i - 1] <= security[i]) r ++;
            else r = 1;
            if(l > time && r > time) ans.push_back(i - time);
        }
        return ans;
    }
};
// @lc code=end

