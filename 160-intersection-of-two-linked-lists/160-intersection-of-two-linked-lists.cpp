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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(headA==headB) return headA;
        int a=0,b=0;
        
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        if(temp1==NULL) //means it is smaller now found how much the second one is greater
        {
            while(temp2!=NULL)
            {
                b++;
                temp2=temp2->next;
            }
        }
        
        if(temp2==NULL) //means it is smaller now found how much the first one is greater
        {
            while(temp1!=NULL)
            {
                a++;
                temp1=temp1->next;
            }
        }
        temp1=headA;
        temp2=headB;
        
        while(a--)
        {
            temp1=temp1->next;
        }
        
        while(b--)
        {
            temp2=temp2->next;
        }
        
        while(temp1!=temp2 && temp1!=NULL && temp2!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};