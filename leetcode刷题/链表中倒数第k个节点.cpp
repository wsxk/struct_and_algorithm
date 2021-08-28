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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        unordered_map<int,ListNode *> map;
        int count = 0;
        ListNode * tmp = head;
        while(tmp!=nullptr){
            count++;
            map[count] = tmp;
            tmp = tmp->next;
        }
        return map[count-k+1];
    }
};