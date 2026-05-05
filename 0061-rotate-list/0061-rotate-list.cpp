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
        if(head==NULL || head->next==NULL)return head;
        int n=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0)return head;

        temp->next=head;
         temp=head;
        int step=n-k-1;
        for(int i=0;i<step;i++){
           temp=temp->next;
        }

        head=temp->next;
        temp->next=NULL;
        return head;
    }
};