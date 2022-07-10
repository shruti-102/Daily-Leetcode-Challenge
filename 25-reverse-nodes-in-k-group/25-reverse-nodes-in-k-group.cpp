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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* next=NULL;
        ListNode* temp=head;
        
        int count=0,n=0;
        
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        
        while(count<k && cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            
            count++;
        }
        
        if(n-count<k && next!=NULL) //means reverse is not possible as enoungh k nodes are not left
        //therefore we will point the head->next to the next calculated after reverse
        // in second example head=1, next=4 
        {
            head->next=next;
        }
        else if(next!=NULL) //means there are >=k nodes left 
        {
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};