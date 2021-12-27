/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
class RangeFreqQuery {
public:
    map<int, vector<int>> pos;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto l = lower_bound(pos[value].begin(), pos[value].end(), left);
        auto r = upper_bound(pos[value].begin(), pos[value].end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

