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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* newhead=new ListNode(-1);
        ListNode* prev=newhead;
        
        if(list1==NULL && list2==NULL) return list1;
        if(list1!=NULL && list2==NULL) return list1;
        if(list1==NULL && list2!=NULL) return list2;
        
        while(ptr1!=NULL && ptr2!=NULL)
        {
            
            if(ptr1->val<=ptr2->val)
            {
                prev->next=ptr1;
                prev=ptr1;
                ptr1=ptr1->next;
            }
            else
            {
                prev->next=ptr2;
                prev=ptr2;
                ptr2=ptr2->next;
            }
            
        }
        
        
        while(ptr1!=NULL)
        {
            prev->next=ptr1;
            prev=ptr1;
            ptr1=ptr1->next;
        }
        
        while(ptr2!=NULL)
        {
            
            prev->next=ptr2;
            prev=ptr2;
            ptr2=ptr2->next;
        }
        
        return newhead->next;
    }
};