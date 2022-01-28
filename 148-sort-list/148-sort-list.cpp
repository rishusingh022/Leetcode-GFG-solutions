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
    ListNode* midNode(ListNode* head,ListNode* tail){
        ListNode* f=head;
        ListNode* s=head;
        while(f!=tail && f->next!=tail){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
    ListNode* Merge(ListNode* head1,ListNode* head2){
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        ListNode* head3;
        if(head1->val<=head2->val){
            head3=head1;
            head3->next=Merge(head1->next,head2);
        }
        else{
            head3=head2;
            head3->next=Merge(head1,head2->next);
        }
        return head3;
    }
    ListNode* MergeSort(ListNode* head,ListNode* tail){
        if(head==tail){
            ListNode *br=new ListNode(head->val);
            return br;
        }
        ListNode* mid=midNode(head,tail);
        ListNode* fsh=MergeSort(head,mid);
        ListNode* ssh=MergeSort(mid->next,tail);
        ListNode* ans=Merge(fsh,ssh);
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* tail=head;
        if(!tail){
            return tail;
        }
        while(tail->next){
            tail=tail->next;
        }
        ListNode* res=MergeSort(head,tail);
        return res;
    }
};