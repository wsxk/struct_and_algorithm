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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * merge=new ListNode(0);
        ListNode * tmp = merge;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<=l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 =l2->next;
            }
            tmp = tmp->next;
        }
        if(l1!=nullptr){
            tmp->next = l1;
            
        }
        if(l2!=nullptr){
            tmp->next=l2; 
        }
        return merge->next;
    }
};