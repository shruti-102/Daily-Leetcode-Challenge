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
    bool isPalindrome(ListNode* head) {
        ListNode* temp1=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        if(head==NULL || head->next==NULL) return true;
        int n=0;
        while(temp1!=NULL)
        {
            temp1=temp1->next;
            n++;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            temp1=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* prev=NULL;
        ListNode* cur;
        ListNode* next;
        if(n%2!=0)
        {
            temp1->next=NULL;
            cur=slow->next;
            next=slow->next;
        }
        else
        {
            temp1->next=NULL;
            cur=slow;
            next=slow;
        }
        
        while(cur!=NULL)
        {
            
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode* temp2=prev;
        temp1->next=NULL;
        temp1=head;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val!=temp2->val) return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        if(temp1!=NULL || temp2!=NULL) return false;
        return true;
        
    }
};