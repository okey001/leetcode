/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    bool valid(string& s, int start, int len){
        if (s[start] == '0') return false;
        if (len > 1){
            if (s[start] == '2' && s[start + 1] > '6') return false;
            if (s[start] > '2') return false;
        }
        return true;
    }
    int numDecodings(string s) {
        int n  = s.length();
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            if(i > 1){
                if (valid(s, i - 2, 2)) f[i] += f[i - 2];
            }
            if (valid(s, i - 1, 1)) f[i] += f[i - 1];
        }
        return f[n];
    }
};
// @lc code=end

