/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if (m == 0) return 0;
        vector<int> f(m);
        for(int j = 0, i = 1; i < m; i ++){
            while(j && needle[i] != needle[j]) j = f[j - 1];
            if(needle[j] == needle[i]) j++;
            f[i] = j;
        }
        for(int j = 0, i = 0; i < n; i ++){
            while(j && haystack[i] != needle[j]) j = f[j - 1];
            if(needle[j] == haystack[i]) j++;
            if(j == m) return i - m +1;
        }
        return  -1;
    }
};
// @lc code=end

