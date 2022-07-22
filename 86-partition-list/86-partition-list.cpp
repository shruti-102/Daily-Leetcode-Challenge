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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1=new ListNode(-1);
        ListNode* dummy2=new ListNode(-1);
        ListNode* d1=dummy1;
        ListNode* d2=dummy2;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                d1->next=temp;
                d1=d1->next;
            }
            else if(temp->val>=x){
                d2->next=temp;
                d2=d2->next;
            }
            temp=temp->next;
        }
        d2->next=NULL;
        d1->next=dummy2->next;
        return dummy1->next;
    }
};