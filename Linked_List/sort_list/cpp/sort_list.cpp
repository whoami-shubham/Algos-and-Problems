/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode * partition(ListNode **start,ListNode *end){
    ListNode *i = NULL ,*j = *start;
    while(j!=end){
        if(j->val<=end->val){
            i   = i?i->next:*start;
            int temp = i->val;
            i->val = j->val;
            j->val = temp;
        }
        j = j->next;
    }
    ListNode *prev = i;
    i = i?i->next:*start;
    int temp = end->val;
    end->val = i->val;
    i->val   = temp;
    return prev; // return previous of pivot node
}

 void  QuickSort(ListNode **start,ListNode *end){
    if(!start || *start==end || !end){
        return;
    }
    ListNode *pivot = partition(start,end);
    QuickSort(start,pivot);
    ListNode *start2 = pivot?pivot->next:(*start?((*start)->next):NULL); // when start node == pivote node then previous node == NULL
    QuickSort(&start2,end);
}
ListNode* Solution::sortList(ListNode* A) {
    ListNode *temp = A,*end = A, *ans = A;
    while(end && end->next){
        end = end->next;
    }
    QuickSort(&A,end);
    return ans;
}