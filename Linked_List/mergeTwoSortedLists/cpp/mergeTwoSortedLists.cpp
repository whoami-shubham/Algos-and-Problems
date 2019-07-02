/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head = NULL,*temp;
    if(!A || !B){
        return !B?A:B;
    }
    while(A && B){
        ListNode* node;
        if(A->val>B->val){
            node = B;
            B = B->next;
        }
        else{
            node = A;
            A = A->next;
        }
        if(head){
            temp->next = node;
            temp = temp->next;
        }
        else{
            head = node;
            temp = head;
        }
    }
    if(A){
        temp->next = A;
    }
    if(B){
        temp->next = B;
    }
    return head;
    
}
