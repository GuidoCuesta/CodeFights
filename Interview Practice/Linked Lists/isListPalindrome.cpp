/*

Note: Try to solve this task in O(n) time using O(1) additional space, where n is the number of elements in l, since this is what you'll be asked to do during an interview.

Given a singly linked list of integers, determine whether or not it's a palindrome.

Example

For l = [0, 1, 0], the output should be
isListPalindrome(l) = true;
For l = [1, 2, 2, 3], the output should be
isListPalindrome(l) = false.

*/

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) 
{
    ListNode<int> *init;
    int size=0,count,half;
    std::vector <int> half1,half2;
    bool retval;
    
    init=l;
    size=0;
    //get the size
    for(;l!=nullptr;)
    {
        l=l->next;
        size++;
    }
    if(size == 0)
        retval=true;
    else
    {
        half=size/2;
        count=0;
        l=init;
        //get the first half
        for(;count<half;)
        {
            half1.push_back(l->value);
            l=l->next;
            count++;
        }    
        if(size%2!=0) //if size is odd, leave the middle character out
        {
            count++;
            l=l->next;
        }
        //get the second half
        for(;count<size;)
        {
            half2.push_back(l->value);
            l=l->next;
            count++;
        }
        //reverse and compare
        std::reverse(half2.begin(),half2.end());

        if(half1==half2)
            retval=true;
        else
            retval=false;

    }
    
    return retval;
    
    
}
