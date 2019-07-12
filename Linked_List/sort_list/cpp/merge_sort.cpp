/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* left , ListNode* right){
    ListNode* head;
    if(left->val>right->val){
        head = right;
        right= right->next;
    }
    else{
        head = left;
        left = left->next;
    }
    ListNode *cur_head = head;
    while(left && right){
        if(left->val>right->val){
            cur_head->next=right;
            cur_head = cur_head->next;
            right = right->next;
        }
        else{
            cur_head->next = left;
            cur_head = cur_head->next;
            left = left->next;
        }
        
    }
    if(left){
        cur_head->next = left;
    }
    if(right){
        cur_head->next = right;
    }
    return head;
}
 
ListNode* Solution::sortList(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    
    ListNode *slow=A,*fast=A->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
    }
    
    fast = slow->next;
    slow->next = NULL; // break list into two parts

    return merge(sortList(A),sortList(fast));
    
    
   
}
