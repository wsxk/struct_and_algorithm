/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val)
            return head->next;
        ListNode * ret=head;
        ListNode * before = head;
        while(head){
            if(head->val!=val){
                before=head;
                head=head->next;
                continue;
            }
            ListNode * next =head->next;
            before->next=next;
            break;
        }
        return ret;
    }
};