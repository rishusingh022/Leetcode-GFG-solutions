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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        unordered_map<int,int> mp;
        ListNode *temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        while(temp->next!=NULL){
            if(mp[temp->next->val]>1){
                ListNode* dptr=temp->next;
                temp->next=temp->next->next;
                dptr->next=NULL;
                delete(dptr);
            }
            else{
                temp=temp->next;
            }
        }
        if(mp[head->next->val]>1){
            return head->next->next;
        }
        return head->next;
    }
};