/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<vector<char>> result;
        result.resize(numRows);
        int i = 0;
        bool down = false;
        for (auto ch: s)
        {
            result[i].push_back(ch);
            if (i == 0 || i == numRows - 1)
                down = !down;
            i += (down ? 1 : -1);
        }
        
        string ans;
        for(auto s: result){
            for(auto ch: s){
                ans += ch;
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.convert(string("PAYPALISHIRING"), 3);
    return 0;
}