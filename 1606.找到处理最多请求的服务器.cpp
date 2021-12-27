/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */
#include<iostream>
#include<set>
#include<queue>
using namespace std;
// @lc code=start
struct Task{int i, end;};
struct HeapComp{
    bool operator()(Task a, Task b){return a.end > b.end;}
};
struct TreeComp{
    bool operator()(const Task& a, const Task& b)const 
    {return a.i < b.i;}
};
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<Task, vector<Task>, HeapComp> heap;
        for(int i = 0; i < k; i++) heap.push({i, 0});
        set<Task, TreeComp> spared;
        vector<int> count(k);
        for(int i = 0; i < arrival.size(); i++){
            int s = arrival[i];
            while(!heap.empty() && heap.top().end <= s){
                spared.insert(heap.top());
                heap.pop();
            }
            if(spared.empty()) continue;
            auto it = spared.lower_bound({i % k, 0});
            if(it == spared.end()) it = spared.lower_bound({0, 0});
            auto task = *it;
            count[task.i] ++;
            task.end = s + load[i];
            heap.push(task);
            spared.erase(it);
        }
        int maxCount = 0;
        for(auto& v: count) if (maxCount < v) maxCount = v;
        vector<int> ans;
        for(int i = 0; i < k; i ++) if (count[i] == maxCount) ans.push_back(i);
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> a;
    s.busiestServers(3, a, {5,2,3,3,3});
    return 0;
}