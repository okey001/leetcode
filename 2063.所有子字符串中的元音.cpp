/*
 * @lc app=leetcode.cn id=2063 lang=cpp
 *
 * [2063] 所有子字符串中的元音
 */

// @lc code=start
class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        for(int i = 0; i < word.length(); i ++) {
            char ch = word[i];
            if(ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u'){
                ans += (long long)((i+1) * (word.length() - i));
            }
        }
        return ans;
    }
};
// @lc code=end

