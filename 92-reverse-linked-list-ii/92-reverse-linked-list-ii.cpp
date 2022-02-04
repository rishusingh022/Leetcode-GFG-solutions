class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *next=NULL;
        ListNode* last=head;
        ListNode *curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return {head,last};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        ListNode* res=temp;
        ListNode* f=NULL;
        ListNode* last=NULL;
        
        while(temp!=NULL){
            cnt++;
            if(cnt==left-1){
                f=temp;
            }
            
            if(cnt==right){
                last=temp;
            }
            
            temp=temp->next;
        }
        if(left==1){
            ListNode *lt=last->next;
            last->next=NULL;
            pair<ListNode*,ListNode*> yo=reverse(head);
            ListNode* new_first=yo.first;
            ListNode* new_last=yo.second;
            new_last->next=lt;
            return yo.first;
        }
        ListNode *lt=last->next;
        last->next=NULL;
        pair<ListNode*,ListNode*> yo=reverse(f->next);
        ListNode* new_first=yo.first;
        ListNode* new_last=yo.second;
        f->next=new_first;
        new_last->next=lt;
        return res;
    }
};