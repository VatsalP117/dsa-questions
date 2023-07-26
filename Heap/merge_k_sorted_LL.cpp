//here i am using extra space to create completly new LL
//we are stpring value of current node and the NEXT POINTER

typedef pair<int,ListNode*> pin;//current value and nextpointer
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head;
        ListNode* prev;
        int n=lists.size();
        priority_queue<pin,vector<pin>,greater<pin>> pq;
        for(auto it:lists){
            if(it!=NULL){
                pq.push({it->val,it->next});
            }
            
        }
        //create head noe
        if(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            head=new ListNode(it.first,NULL);
            prev=head;
            if(it.second!=NULL){
                pq.push({it.second->val,it.second->next});
            }
        }

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ListNode* x=new ListNode(it.first,NULL);
            prev->next=x;
            prev=x;
            if(it.second!=NULL){
                pq.push({it.second->val,it.second->next});
            }
        }
        return head;
        
    }
};