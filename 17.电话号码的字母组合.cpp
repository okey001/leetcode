/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    void dfs(string& digits, int depth, vector<string>& result, string& cur, int n){
        if(depth == digits.length()){
            result.push_back(cur);
            return;
        }
        if (digits[depth] == '1'){
            dfs(digits, depth + 1, result, cur, n);
            return;
        }
        char ch = 'a' + (digits[depth] - '2') * 3;
        if (digits[depth] > '7') ch += 1;
        int count = 3;
        if (digits[depth] == '7' || digits[depth] == '9') count = 4;
        for(char i = ch; i < ch + count; i++){
            cur[n] = i;
            dfs(digits, depth + 1, result, cur, n + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        string s(digits.length() + 1, '\0');
        dfs(digits, 0, ans, s, 0);
        return ans;
    }
};
// @lc code=end

