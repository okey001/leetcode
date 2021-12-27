/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int n;
    string s1, s2;
    int f[30][30][31];
    bool dp(int i, int j, int len){
        if (i + len > n || j + len > n) return false;
        if (len == 0) return true;
        if (f[i][j][len] != -1) return f[i][j][len] == 1;
        if (len == 1) f[i][j][len] = s1[i] == s2[j];
        else{
            f[i][j][len] = 0;
            for(int k = 1; k < len; k++){
                if (dp(i, j, k) && dp(i + k, j + k, len - k)) {
                    f[i][j][len] = 1;
                    break;
                }
                if (dp(i, j + len - k, k) && dp(i + k, j, len - k)){
                    f[i][j][len] = 1;
                    break;
                }
            }
        }
        return f[i][j][len] == 1;
    }
    bool isScramble(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        n = s1.length();
        if (s2.length() != n) return false;
        if (n == 0) return true;
        memset(f, -1, sizeof(f));
        return dp(0, 0, n);
    }
};
// @lc code=end

