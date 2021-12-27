/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = head;
        while(n && r){
            r = r->next;
            n --;
        }
        if(n){
            return head;
        }
        ListNode* l = new ListNode();
        l->next = head;
        head = l;
        while(r){
            r = r->next;
            l = l->next;
        }
        if(l->next) l->next = l->next->next;
        return head->next;
    }
};
// @lc code=end

