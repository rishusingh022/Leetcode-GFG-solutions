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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        ListNode* head3;
        if(head1->val<=head2->val){
            head3=head1;
            head3->next=merge(head1->next,head2);
        }
        else{
            head3=head2;
            head3->next=merge(head1,head2->next);
        }
        return head3;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ans=merge(ans,lists[i]);
        }
        return ans;
    }
};