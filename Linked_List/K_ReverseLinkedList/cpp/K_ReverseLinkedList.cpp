/*
problem link :- https://www.interviewbit.com/problems/k-reverse-linked-list/

Given a singly linked list and an integer K, reverses the nodes of the
list K at a time and returns modified linked list and length of the list is divisible by K

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5 

*/

ListNode* Solution::reverseList(ListNode* A, int B) {
    int k = B;
    ListNode *prev = NULL, *cur = A, *nxt = A?A->next:NULL, *head,*tail=NULL;
    
    while(cur && B>1){
           k  = B;
         head = cur;
        while(cur && k>0){
            cur->next = prev;
            prev      = cur;
            cur       = nxt;
            nxt       = nxt?nxt->next:NULL;
            k--;
        }
        if(head==A){
            A = prev;
        }
        else{
            head->next = cur;
        }
        if(tail){
            tail->next = prev;
        }
        tail = head;
    }
    return A;
}