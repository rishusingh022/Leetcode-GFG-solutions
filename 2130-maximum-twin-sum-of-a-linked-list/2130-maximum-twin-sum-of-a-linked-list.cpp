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
    int pairSum(ListNode* head) {
        int n=0;
        ListNode *temp=head;
        vector<int>arr;
        while(temp!=NULL){
            n++;
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int mx=INT_MIN;
        for(int i=0;i<=(n/2)-1;i++){
            int sum=arr[i]+arr[n-1-i];
            if(sum>mx){
                mx=sum;
            }
        }
        return mx;
    }
};