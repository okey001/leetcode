/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 *
 * [2059] 转化数字的最小运算数
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int visited[1001];
        memset(visited, 0, sizeof(visited));
        vector<int> q;
        q.push_back(start);
        int cur = 0;
        int end = 1;
        visited[start] = true;
        int ans = 0;
        while(end > cur){
            ans++;
            for(int i = cur; i < end; i ++){
                int v = q[i];
                for(auto num: nums){
                    if (v + num == goal) return ans;
                    if (v - num == goal) return ans;
                    if ((v ^ num) == goal) return ans;
                    if((v + num) >= 0 && (v + num) < 1000 && !visited[v + num]) 
                    {q.push_back(v + num); visited[v + num] = true;}
                    if((v - num) >= 0 && (v - num) < 1000 && !visited[v - num]) 
                    {q.push_back(v - num); visited[v - num] = true;}
                    if((v ^ num) >= 0 && (v ^ num) < 1000 && !visited[v ^ num]) 
                    {q.push_back(v ^ num); visited[v ^ num] = true;}
                }
            }
            cur = end;
            end = q.size();
        }
        return -1;
    }
};
// @lc code=end

int main(){
    vector<int> nums= {3,5,7};
    Solution s;
    s.minimumOperations(nums, 0, -4);
    return 0;
}
