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
        ListNode* temp=head;
        if(!head || !head->next){
            return head;
        }
        while(temp->next!=NULL){
            if(temp->next->val==temp->val){
                ListNode* dptr=temp->next;
                temp->next=temp->next->next;
                //dptr->next=NULL;
                delete(dptr);
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};