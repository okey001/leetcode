/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.length(), m = p.length();
        if (m == 0) return 0;
        vector<int> next(m);
        for(int i = 1, j = 0; i < m; i ++){
            while(j && p[i] != p[j]) j = next[j - 1];
            if(p[i] == p[j]) j++;
            next[i] = j;
        }
        for(int i = 0, j = 0; i < n; i ++){
            while(j && s[i] != p[j]) j = next[j - 1];
            if(s[i] == p[j]) j++;
            if(j == m) return i - m + 1;
        }
        return  -1;
    }
};
// @lc code=end

