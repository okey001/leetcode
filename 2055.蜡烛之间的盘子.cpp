/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        if(n < 3) return vector<int>(queries.size());
        vector<int> c(n);
        vector<int>first(n), last(n);
        last[0] = -1;
        if(s[0] == '|') last[0] = 0;
        for(int i = 1; i < n; i ++){
            c[i] = c[i- 1] + (s[i] == '*');
            last[i] = last[i - 1];
            if(s[i] == '|')
                last[i] = i;
        }
        first[n - 1] = -1;
        if(s[n - 1] == '|') first[n - 1] = n - 1;
        for(int i = n - 2; i >= 0 ; i --){
            first[i] = first[i + 1];
            if(s[i] == '|') first[i] = i;
        }
        vector<int> ans;
        for(auto&& v: queries){
            int l = first[v[0]];
            int r = last[v[1]];
            if (l == -1 || r == -1 || l + 2 > r)
                ans.push_back(0);
            else
                ans.push_back(c[r - 1] - c[l]);
        }
        return ans;
    }
};
// @lc code=end

