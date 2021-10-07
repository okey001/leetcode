/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
int min(int x, int y){return x < y? x: y;}
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)return string();
        string t("$#");
        for(int i = 0; i < n; i++){
            t.append(string(1, s[i]));
            t.append("#");
        }
        t += "@";
        n = t.length();
        int center = 0;
        int r = 0;
        vector<int> p{0};
        for (int i = 1; i < n; i++){
            int j = 2 * center - i;
            int value = 0;
            if (r > i) value = min(p[j], r - i);
            while(t[i + value + 1] == t[i - value - 1]) value++;
            if (i + value > r){
                r = i + value;
                center = i;
            }
            p.push_back(value);
        }
        int maxLength = 0;
        int maxIndex = 0;
        for(int i = 0; i < n; i ++){
            if (p[i] > maxLength){
                maxLength = p[i];
                maxIndex = i;
            }
        }
        int start = (maxIndex - maxLength) / 2;
        return s.substr(start, maxLength);
    }
};
// @lc code=end
int main(){
    Solution s;
    string ans = s.longestPalindrome("babad");
    cout << ans << endl;
    return 0;
}
