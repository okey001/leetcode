/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
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
    ListNode* reverse(ListNode *head, int n){
        ListNode dummyNode;
        ListNode *dummy = &dummyNode;
        dummyNode.next = head;
        ListNode *pre = head;
        ListNode *cur = head -> next;
        n--;
        while(n-- && cur){
            pre->next = cur->next;
            cur->next = cur->next->next;
            cur->next 
        }
        return dummy->next;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while(cur){
            n ++;
            cur = cur->next;
        }
        cout<<n<<endl;
        cur = head;
        ListNode *pre = nullptr;
        for(int i = 1; n > 0; n-=i, i++){
            int count = i;
            if(n < i) count = n;
            cout<<count<<endl;
            if(count % 2){
                while(count--){
                    pre = cur;
                    cur = cur->next;
                }
            }
            else{
                cur = reverse(cur, count);
                pre->next = cur;
                while(count--) {
                    pre = cur;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};
// @lc code=end

