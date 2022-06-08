/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& r) {
        vector<int> in(n);
        vector<vector<int>> v(n);
        for(auto& e: r){
            in[e[0]] ++;
            v[e[1]].push_back(e[0]);
        }
        vector<int> visited(n);
        queue<int> q;
        for(int i = 0; i < n; i ++){
            if(in[i] == 0) {q.push(i);
            visited[i] = true;}
            
            
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto end: v[i]) {
                in[end]--;
                if(in[end] == 0 && !visited[end]) 
                {q.push(end);visited[end] = true;}
            }
        }
        for(auto i: visited) if(!i) return false;
        return true;
    }
};
// @lc code=end

