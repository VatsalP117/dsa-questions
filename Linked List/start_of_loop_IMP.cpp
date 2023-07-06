ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        ListNode* entry=head;
        while(slow!=NULL && entry!=NULL){
            if(slow==entry) return slow;
            slow=slow->next;
            entry=entry->next;
            
        }
        return NULL;
    }