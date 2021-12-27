/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int getValue(char ch){
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        if (ch == 'M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        int last = 1000;
        for(auto ch: s){
            int v = getValue(ch);
            if (v > last){
                ans -= last * 2;
            }
            ans += v;
            last = v;
        }
        return ans;
    }
};
// @lc code=end

