/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cache = -1;
        if(root) s.push({root, 0});
    }
    
    int getNext() {
        while(s.size()){
            auto& v = s.top();
            auto cur = v.first;
            auto order = v.second;
            if(order <= 0 && cur->left){
                v.second = 1;
                s.push({cur->left, 0});
                continue;
            }
            
            if (order <= 1){
                v.second = 2;
                return cur->val;
            }
            s.pop();
            if(order <= 2 && cur->right){
                v.second = 3;
                s.push({cur->right, 0});
                continue;
            }
            
        }
        return -2;
    }
    
    int next(){
        if(cache == -1){
            return getNext();
        }
        else{
            int ret = cache;
            cache = -1;
            return ret;
        }
    }

    bool hasNext() {
        if(cache == -1){
            cache = getNext();
        }
        return cache != -2;
    }
private:
    stack<pair<TreeNode*, int>> s;
    int cache;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

