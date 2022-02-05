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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        if(k==0) return head;
        temp=head;
        int count=0;
        while(count<cnt-k-1){
            count++;
            temp=temp->next;
        }
        ListNode* last=temp->next;
        temp->next=NULL;
        
        ListNode *dummy=last;
        while(dummy->next!=NULL){
            dummy=dummy->next;
        }
        dummy->next=head;
        return last;
    }
};