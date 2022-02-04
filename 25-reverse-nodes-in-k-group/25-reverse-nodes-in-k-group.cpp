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
        if(!head) return NULL;
        ListNode *curr=head;
        ListNode *next=NULL;
        ListNode *prev=NULL;
        int cnt=0;
        ListNode *temp=head;
        int check=0;
        while(temp!=NULL){
            check++;
            temp=temp->next;
        }
        if(check<k){
            return head;
        }
        while(curr!=NULL and cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(curr,k);
        }
        return prev;
    }
};