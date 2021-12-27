/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    void print(vector<vector<int>> m){
        for(auto&& i : m){
            for(auto&& j: i) cout<< j << " ";
            cout<< endl;
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        cout << n << " " << m << " " << endl;
        vector<vector<int>> g(n);
        for(auto&& i: g) i.resize(m);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(i == 0) g[i][j] = matrix[i][j] == '1';
                else g[i][j] = matrix[i][j] == '1' ? g[i - 1][j] + 1 : 0;
            }
        }
        int ans = 0;
        vector<int> left(m), right(m);
        stack<pair<int, int>> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                while(!s.empty() && s.top().second > g[i][j]){
                    pair<int, int> p = s.top();
                    right[p.first] = j;
                    s.pop();
                }
                if(!s.empty()){
                    left[j] = s.top().first + 1;
                }
                else{
                    left[j] = 0;
                }
                s.push(make_pair(j, g[i][j]));
            }
            while(!s.empty()){
                right[s.top().first] = m;
                s.pop();
            }
            for(int j = 0; j < m; j ++){
                if ((right[j] - left[j]) * g[i][j] > ans){
                    ans = (right[j] - left[j]) * g[i][j];
                }
            }
        }
        return ans;
    }
    
};
// @lc code=end

