/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> f(n);
        for(auto&& i: f)i.resize(m);
        f[0][0]=1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if (obstacleGrid[i][j] == 1)
                    f[i][j] = 0;
                else {
                    f[i][j] = 0;
                    if (i+j == 0)f[i][j] = 1;
                    if (i>0) f[i][j] += f[i-1][j];
                    if (j>0) f[i][j] += f[i][j-1];
                
                }
            }
        }
        return f[n-1][m-1];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> f(3);
    for(auto&& i: f) i.resize(3);
    f[1][1] = 1;
    s.uniquePathsWithObstacles(f);
}