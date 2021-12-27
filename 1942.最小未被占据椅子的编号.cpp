/*
 * @lc app=leetcode.cn id=1942 lang=cpp
 *
 * [1942] 最小未被占据椅子的编号
 */

// @lc code=start

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int> qArrival, qLeaving;
        set<int> chairs;
        for(int i = 0; i <= targetFriend; i++){
            int arrival = times[i][0];
            while(qLeaving.top() <= arrival){
                qLeaving.pop();
            }

        }
    }
};
// @lc code=end

