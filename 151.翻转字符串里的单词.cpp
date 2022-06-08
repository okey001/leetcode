/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        if(n == 0) return s;
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(cur && s[cur - 1] != ' ') s[cur++] = s[i];
            }else{
                s[cur++] = s[i];
            }
        }
        if (cur && s[cur - 1] == ' ') cur --;
        n = cur;
        for(int i = 0; i < n / 2; i++){
            auto ch = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = ch;
        }
        int l = 0, r= 0;
        for(int i = 0; i <=n;){
            if(s[i] == ' ' || i == n){
                r = i;
                for(int j = l; j < (l + r) / 2; j ++){
                    auto ch = s[j];
                    s[j] = s[r - j + l - 1];
                    s[r - j + l - 1] = ch;
                }
                while(i < n && s[i] == ' ') i++;
                l = i;
                if(i == n) break;
            }
            else{
                i++;
            }
        }

        return s.substr(0, n);
    }
};
// @lc code=end

