/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> f(n + 1);
        for(auto&& i: f) i.resize(m + 1);
        for(int i = 0; i <= n; i++){
            f[i][0] = i;
        }
        for(int i = 0; i <= m; i++){
            f[0][i] = i;
        }
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                f[i][j] = i > j ? i : j;
                if(f[i - 1][j] + 1 < f[i][j])
                    f[i][j] = f[i - 1][j] + 1;
                if (f[i][j - 1] + 1 < f[i][j])
                    f[i][j] = f[i][j - 1] + 1;
                int delta = word1[i - 1] != word2[j - 1];
                if (f[i - 1][j - 1] + delta < f[i][j])
                    f[i][j] = f[i - 1][j - 1] + delta;
            }
        }
        for(auto&& i: f){
            for(auto && j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        return f[n][m];
    }
};
// @lc code=end

