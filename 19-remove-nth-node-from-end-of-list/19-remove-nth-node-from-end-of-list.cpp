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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        
        if(size==1) return NULL;
        if(size==n)
        {
            head=head->next;
            return head;
        }
        size=size-n;
        temp=head;
        while(size!=1)
        {
            temp=temp->next;
            size--;
        }
        temp->next=temp->next->next;
        return head;
    }
};