/*
 * @lc app=leetcode.cn id=2070 lang=cpp
 *
 * [2070] 每一个查询的最大美丽值
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int search(int price, vector<vector<int>> &items){
        int l = 0, r = items.size();
        while(l < r){
            int m = (l + r) / 2;
            if(items[m][0] > price) r = m;
            else l = m + 1;
        }
        if(l == 0) return 0;
        return items[l - 1][1];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), comp);
        int n = items.size();
        for(int i = 1; i < items.size(); i++){
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        vector<int> ans;
        for(int i = 0 ; i< queries.size(); i ++)
            ans.push_back(search(queries[i], items));
        return ans;
    }
};
// @lc code=end

