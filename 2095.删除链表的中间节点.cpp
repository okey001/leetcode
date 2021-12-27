/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *pre = new ListNode();
        pre->next = head;
        ListNode *fast = pre, *slow = pre;
        while(true){
            fast = fast->next;
            if(fast) fast = fast->next;
            if(!fast){
                slow->next = slow->next->next;
                return pre->next;
            }
            slow = slow->next;
        }
    }
};
// @lc code=end

