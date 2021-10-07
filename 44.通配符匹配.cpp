/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        int (**f) = new int*[n + 1];
        for (int i = 0; i <= n; i++){
            f[i] = new int[m + 1];
            memset(f[i], 0, sizeof(int) * (m+1));
        }
        f[0][0] = 1;
        for (int i = 0; i <= n; i ++){
            for (int j = 0; j <= m; j++){
                if(i && j && s[i-1] == p[j-1] && f[i-1][j-1]) f[i][j] = 1;
                else if(i && j && p[j-1] == '?' && f[i-1][j-1]) f[i][j] = 1;
                else if(i && j && p[j-1] == '*' && f[i-1][j]) f[i][j] = 1;
                else if(i && j && p[j-1] == '*' && f[i-1][j-1]) f[i][j] = 1;
                else if(j && p[j-1] == '*' && f[i][j-1]) f[i][j] = 1;
            }  
        }
        bool ans = f[n][m];
        for (int i = 0; i < n; i++) delete[] f[i];
        delete[] f;
        return ans;
    }
};
// @lc code=end
int main(){
    Solution s;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "?")<<endl;
    cout<<s.isMatch("aa", "??")<<endl;
    cout<<s.isMatch("aa", "ab")<<endl;
    cout<<s.isMatch("aa", "a?")<<endl;
    cout<<s.isMatch("aa", "*a")<<endl;
    cout<<s.isMatch("adceb", "*a*b")<<endl;
    return 0;
}
