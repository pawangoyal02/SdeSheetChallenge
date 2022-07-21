class Solution {
public:
    
    struct cmpr {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,cmpr> q;
     for(int i=0;i<lists.size();i++)
    {
        ListNode* head=lists[i];
       
        while(head!=NULL)
        {  q.push(head);
           head=head->next;
            
        }
    }
    ListNode* head=new ListNode(0);
    ListNode* temp=head;
    while(!q.empty())
    {
        head->next=q.top();
        q.pop();
        head=head->next;
    }
    head->next=NULL;
    return temp->next;
    }
};