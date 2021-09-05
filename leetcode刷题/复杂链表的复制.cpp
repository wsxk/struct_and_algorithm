/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    unordered_map<Node *,Node *> hash;
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        if(!hash.count(head)){
            Node * head_new=new Node(head->val);
            hash[head]=head_new;
            head_new->next = copyRandomList(head->next);
            head_new->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};