/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, vector<int> &path, int t){
        if(root == nullptr) return 0;
        if(root->val == t) return 1;
        bool ret = dfs(root->left, path, t);
        if(ret) {path.push_back(-1); return ret;}
        ret = dfs(root->right, path, t);
        if(ret) {path.push_back(1); return ret;}
        return ret;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> pathS, pathT;
        dfs(root, pathS, startValue);
        dfs(root, pathT, destValue);
        int nS = pathS.size(), nT = pathT.size();
        int len = 0;
        while(nS > len && nT > len && pathS[nS - len - 1] == pathT[nT - len - 1]) len++;
        string ans = "";
        for(int i = 0; i < nS - len; i ++) ans += 'U';
        for(int i = 0; i < nT - len; i ++) ans += (pathT[nT - len - i - 1] == -1 ? 'L' : 'R'); 
        return ans;
    }
};
// @lc code=end

