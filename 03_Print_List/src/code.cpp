struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x): val(x),next(NULL)
    {
    }
};

class Solution 
{
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> value_return;
        if(head != NULL)
        {
            value_return.insert(value_return.begin(),head->val);
            while ( head -> next != NULL)
            {
               value_return.insert(value_return.begin(),head->next->val);
               head = head->next;
            }
        }
        return value_return;
    }
};
