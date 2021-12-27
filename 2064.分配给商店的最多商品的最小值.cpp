/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 *
 * [2064] 分配给商店的最多商品的最小值
 */

// @lc code=start
class Solution {
public:
    bool isValid(int n, int num, vector<int>& quantities){
        
        for(auto v: quantities){
            n -= v / num;
            v = v % num;
            if(v) n--;
        }
        if(n>=0) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int r = 0;
        for(auto&& v: quantities) if(v > r) r = v;
        int l = 0;
        while(l + 1 < r){
            int m = (l + r) / 2;
            if(isValid(n, m, quantities)){
                r = m;
            }else{
                l = m;
            }
        }
        return r;
    }
};
// @lc code=end

