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
        ListNode* ans=new ListNode(-1);
        ListNode* ptr=ans;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        int carry=0;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            int addval=ptr1->val+ptr2->val;
            if(carry!=0)
            {
               addval=addval+carry;
                if(addval%10 != addval)
                {
                    carry=addval/10;
                    addval=addval%10;
                }
                else
                {
                    carry=0;
                }
            }
            else
            {
                if(addval%10 != addval)
                {
                    carry=addval/10;
                    addval=addval%10;
                }
            }
            
            ListNode* newnode=new ListNode(addval);
            ptr->next=newnode;
            ptr=newnode;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        while(ptr1!=NULL)
        {
            int addval=ptr1->val;
            if(carry!=0)
            {
                addval+=carry;
                if(addval%10 != addval)
                {
                    carry=addval/10;
                    addval=addval%10;
                }
                else
                {
                    carry=0;
                }
            }
            ListNode* newnode=new ListNode(addval);
            ptr->next=newnode;
            ptr=newnode;
            ptr1=ptr1->next;
        }
        
        while(ptr2!=NULL)
        {
            int addval=ptr2->val;
            if(carry!=0)
            {
                addval+=carry;
                if(addval%10 != addval)
                {
                    carry=addval/10;
                    addval=addval%10;
                }
                else
                {
                    carry=0;
                }
            }
            ListNode* newnode=new ListNode(addval);
            ptr->next=newnode;
            ptr=newnode;
            ptr2=ptr2->next;
        }
        
        if(carry)
        {
            ListNode* newnode=new ListNode(carry);
            ptr->next=newnode;
            ptr=newnode;
        }
        
        return ans->next;
    }
};