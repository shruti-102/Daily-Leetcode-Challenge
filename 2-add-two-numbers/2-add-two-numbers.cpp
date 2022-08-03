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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newhead=new ListNode(-1);
        ListNode* prev=newhead;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            int add=temp1->val+temp2->val;
            add=add+carry;
            carry=add/10;
            add=add%10;
            ListNode* newnode=new ListNode(add);
            prev->next=newnode;
            prev=newnode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL)
        {
            int add=temp1->val;
            add=add+carry;
            carry=add/10;
            add=add%10;
            ListNode* newnode=new ListNode(add);
            prev->next=newnode;
            prev=newnode;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            int add=temp2->val;
            add=add+carry;
            carry=add/10;
            add=add%10;
            ListNode* newnode=new ListNode(add);
            prev->next=newnode;
            prev=newnode;
            temp2=temp2->next;
        }
        
        if(carry)
        {
            ListNode* newnode=new ListNode(carry);
            prev->next=newnode;
            prev=newnode;
        }
        return newhead->next;
    }
};