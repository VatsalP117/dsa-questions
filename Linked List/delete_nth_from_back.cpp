ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        //move the fast pointer n steps ahead of slow when fast reaches NULL
        //slow is at the node we have to delete
        for(int i=0;i<n;i++){
            if(fast!=NULL){
                fast=fast->next;
            }
        }
        //edge case: if fast reaches NULL means LL completed so node to delete is the head itself
        if(fast==NULL) return head->next;


        //normal case
        //now move the nodes ahead till fast reaches NULL
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;

        
    }