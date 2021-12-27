/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string getStr(char v1, char v5, char v10, int value){
        string ans;
        if (value <= 3){
            for(int i = 0; i < value; i ++) ans += v1;
        }
        else if (value == 4){
            ans += v1;
            ans += v5;
        }
        else if (value <= 8){
            ans += v5;
            for (int i = 0; i < value - 5; i++) ans += v1;
        }
        else if (value == 9){
            ans += v1;
            ans += v10;
        }
        return ans;
    }
    string chs = "IVXLCDM___";
    string intToRoman(int num) {
        int i = 0;
        string ans;
        while(num){
            int v = num % 10;
            ans = getStr(chs[i], chs[i + 1], chs[i + 2], v) + ans;
            num = num / 10;
            i++;
            i++;
        }
        return ans;
    }
};
// @lc code=end

