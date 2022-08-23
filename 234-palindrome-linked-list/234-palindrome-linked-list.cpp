class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(!head->next)  return true;
        while(fast->next && fast->next->next){              // finding middle of linked list 
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=NULL,*curr=slow->next,*temp;
        while(curr!=NULL){                                 // reversing the linked list after the middle node
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;                                   // joining the reversed linked list after the middle node
        ListNode *start=head,*mid=slow->next;
        while(mid){                                        // valued being checked here
            if(start->val!=mid->val) return false;
            start=start->next;
            mid=mid->next;
        }
        return true;
    }
};