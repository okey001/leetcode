/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 *
 * [2058] 找出临界点之间的最小和最大距离
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int ansMin = -1;
        int ansMax = -1;
        if(head == nullptr || head->next == nullptr) return vector<int>{-1, -1};
        ListNode* pre = head;
        ListNode* cur = head->next;
        int i = 0;
        while(cur->next){
            ListNode* next = cur->next;
            if(next->val > cur->val && pre->val > cur->val){
                if(first != -1){
                    if(i - first > ansMax) ansMax = i - first;
                }
                if(last != -1){
                    if(ansMin == -1) ansMin = i - last;
                    if(i - last < ansMin) ansMin = i - last;
                }
                if(first == -1) first = i;
                last = i;
            }
            if(next->val < cur->val && pre->val < cur->val){
                if(first != -1){
                    if(i - first > ansMax) ansMax = i - first;
                }
                if(last != -1){
                    if(ansMin == -1) ansMin = i - last;
                    if(i - last < ansMin) ansMin = i - last;
                }
                if(first == -1) first = i;
                last = i;
            }
            pre = cur;
            cur = next;
            next = cur->next;
            i++;
        }
        return vector<int>{ansMin, ansMax};
    }
};
// @lc code=end

