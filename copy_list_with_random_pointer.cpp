
// Mast problem hai...

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
      if(head==NULL)
      {
          return NULL;
      }  
        unordered_map<Node*,Node*>m;
        Node* cur=head;
        while(cur!=NULL)
        {
            Node* copy=new Node(cur->val);
            m.insert({cur,copy});
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL)
        {
            m[cur]->next=m[cur->next];
            m[cur]->random=m[cur->random];
            cur=cur->next;
        }
   return m[head];
    }
};
//tc o(n)+o(n)~o(n)

//sc o(n)

// https://youtu.be/VNf6VynfpdM


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            else if(iter->random == NULL)
            {
                iter->next->random = NULL;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};
//tc o(n)+o(n)+o(n)~o(n)

//sc o(1)

// https://youtu.be/VNf6VynfpdM
