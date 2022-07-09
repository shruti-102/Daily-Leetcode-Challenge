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
    ListNode* reverseList(ListNode* head) {
       
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        //newhead will be generated
        //1->2->3->4->->
        //this reverseList(2) will return
        //5->4->3->2 newhead will be 5
        //now after 2 there should be 1
        //as 2->1 is not broken yet
        //head->next->next  1->2->__=head (1)
        //2->1
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
};