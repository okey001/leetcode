/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto& s: tokens){
            if(s[0] >= '0' && s[0] <= '9' || s.length() > 1){
                int num = 0;
                for(auto ch: s) if (ch!='-')num = num * 10 + ch - '0';
                nums.push(s[0] == '-' ? -num: num);
            }
            else{
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                int result;
                if(s[0] == '+') result = num1 + num2;
                else if (s[0] == '-') result = num1 - num2;
                else if (s[0] == '*') result = num1 * num2;
                else if (s[0] == '/') result = num1 / num2;
                nums.push(result);
            }
            
        }
        return nums.top();
    }
};
// @lc code=end

