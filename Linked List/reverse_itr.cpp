ListNode* reverseList(ListNode* head) {
       ListNode* dummy=NULL;
       ListNode* x=head;
       while(x!=NULL){
           //do this before so we dont lose track of the LL
           ListNode* nextNode=x->next;
           x->next=dummy;
           dummy=x;
           x=nextNode;
           
       }
       return dummy;
};