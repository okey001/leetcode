/*
 * @lc app=leetcode.cn id=2075 lang=cpp
 *
 * [2075] 解码斜向换位密码
 */

// @lc code=start
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int i = 0, j = 0;
        int columns = encodedText.length() / rows;
        string ans;
        if(encodedText.length() == 0) return ans;
        while(true){
            ans += encodedText[i * columns + j];
            if(i == 0 && j == columns - 1) break;
            i++;
            j++;
            if(i >= rows || j >= columns){
                j = j - i + 1;
                i = 0;
            }
        }
        cout<<ans.c_str()<<endl;
        while(ans.length() && ans[ans.length() - 1] == ' ') ans.erase(ans.length() - 1);
        
        return ans;
    }
};
// @lc code=end

