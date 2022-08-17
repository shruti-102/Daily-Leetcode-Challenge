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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int k=lists.size();
        if(k==0) return NULL;
        
        for(int i=0;i<k;i++){
            ListNode* temp=lists[i];
            while(temp!=NULL)
            {
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        
        ListNode* head=NULL;
        ListNode* temp=head;
        
        while(!pq.empty())
        {
            if(head==NULL)
            {
                ListNode* newnode=new ListNode(pq.top());
                head=newnode;
                temp=head;
                pq.pop();
            }
            else
            {
                ListNode* newnode=new ListNode(pq.top());
                temp->next=newnode;
                temp=newnode;
                pq.pop();
            }
        }
        return head;
    }
};