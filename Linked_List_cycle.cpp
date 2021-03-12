// Brute force approach is to make a hashmap and we any node value repeats ,it means that there exists a cyce , otherwise not
// tc o(N)
// sc o(N)

// OR

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head == NULL || head->next == NULL)  // linked list with no node or just 1 node 
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)  // if cycle does not exists then we have to come out of the loop to avoid infinite loop , so this is the condition for coming out when no cycle exists 
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)  // means cycle exists 
            {
                return true;
            }
        }
        return false;
    }
};
// tc o(N)
// sc o(1)
