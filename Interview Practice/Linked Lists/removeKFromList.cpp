/*

Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in the list, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers l and an integer k, remove all elements from list l that have a value equal to k.

Example

For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
removeKFromList(l, k) = [1, 2, 4, 5];
For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].

*/

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) 
{
    ListNode<int> *prev=nullptr;
    ListNode<int> *Init=l;    
    
    while(l!=nullptr)
    {
        if(l->value==k)
        {
            if(prev!=nullptr)
            {
                prev->next=l->next;
                delete l;
                l=prev;
            }   
            else
            {
                Init=l->next;
                delete l;
                l=Init;
                continue;
            }
        }
        prev=l;
        l=l->next;
    }
    
    return Init;
}
