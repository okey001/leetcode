/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> c, r, cl, rl;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        c.resize(n);
        r.resize(n);
        cl.resize(n * 2 - 1);
        rl.resize(n * 2);
        vector<int> cur(n * n);
        for(int j=0; j<n; j++){
            int i = 0;
            c[i] = 1;
            r[j] = 1;
            cl[i + j] = 1;
            rl[n - i + j] = 1;
            cur[i * n + j] = 1;
            dfs(ans, cur, 1, n);
            c[i] = 0;
            r[j] = 0;
            cl[i + j] = 0;
            rl[n - i + j] = 0;
            cur[i * n + j] = 0;
        }
        return ans;
    }
    vector<string> format(vector<int> &cur, int n){
        vector<string> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(string(n, '.'));
        }
        for(int i = 0; i < n * n; i++){
            if(cur[i]){
                ans[i / n][i % n] = 'Q';
            }
        }
        return (ans);
    }
    void dfs(vector<vector<string>> &ans, vector<int> &cur, int i, int n){
        if (i >= n){
            ans.push_back(format(cur, n));
            return;
        }
        for (int j = 0; j < n; j++){
            if (!c[i] && !r[j] && !cl[i + j] && !rl[n - i + j]){
                c[i] = 1;
                r[j] = 1;
                cl[i + j] = 1;
                rl[n - i + j] = 1;
                cur[i * n + j] = 1;
                dfs(ans, cur, i + 1, n);
                c[i] = 0;
                r[j] = 0;
                cl[i + j] = 0;
                rl[n - i + j] = 0;
                cur[i * n + j] = 0;
            }
        }
    }
};
// @lc code=end
