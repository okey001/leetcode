/*
 * @lc app=leetcode.cn id=2086 lang=cpp
 *
 * [2086] 从房屋收集雨水需要的最少水桶数
 */

// @lc code=start
class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length();
        int ans = 0, last = -2;
        for(int i = 0; i < n; i ++){
            if(street[i] == 'H'){
                if(last == i - 1) continue;
                if(i + 1 < n && street[i + 1] == '.') {ans ++; last = i + 1;}
                else if (i && street[i - 1] == '.') ans ++;
                else return -1;
            }else{

            }
        }
        return ans;
    }
};
// @lc code=end

