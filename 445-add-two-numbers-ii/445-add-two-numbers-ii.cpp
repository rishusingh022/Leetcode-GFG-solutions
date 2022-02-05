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
    ListNode* reverse(ListNode *head){
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int count(ListNode *head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int sum=0;
        int carry=0;
        if(count(l1)<count(l2)){
            swap(l1,l2);
        }
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* prev=NULL;
        while(l2!=NULL){
            sum=l1->val+l2->val+carry;
            l1->val=sum%10;
            carry=sum/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            sum=l1->val+carry;
            l1->val=sum%10;
            carry=sum/10;
            prev=l1;
            l1=l1->next;
        
        }
        if(carry>0){
            prev->next=new ListNode(carry);
        }
        return reverse(temp1);
    }
};