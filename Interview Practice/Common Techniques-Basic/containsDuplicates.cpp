/*

Given an array of integers, write a function that determines whether the array contains any duplicates. Your function should return true if any element appears at least twice in the array, and it should return false if every element is distinct.

Example

For a = [1, 2, 3, 1], the output should be
containsDuplicates(a) = true.

There are two 1s in the given array.

For a = [3, 1], the output should be
containsDuplicates(a) = false.

The given array contains no duplicates.

*/

bool containsDuplicates(std::vector<int> a) 
{
    int len=a.size();
    std::map<int,int> mymap;
    int i=0;
    std::pair<std::map<int,int>::iterator,bool> ret;
    bool retval=false;
    
    while(i<len && retval==false)
    {
        ret = mymap.insert (std::pair<int,int>(a[i],1));
        if (ret.second==false)
            retval=true;
        i++;
    }
    
    return retval;
    
}
