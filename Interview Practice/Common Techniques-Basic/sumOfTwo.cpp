/*

You have two integer arrays, a and b, and an integer target value v. Determine whether there is a pair of numbers, where one number is taken from a and the other from b, that can be added together to get a sum of v. Return true if such a pair exists, otherwise return false.

Example

For a = [1, 2, 3], b = [10, 20, 30, 40], and v = 42, the output should be
sumOfTwo(a, b, v) = true.

*/

bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) 
{
    int j;
    int lenj=b.size();
    bool retval=false;
    
    std::unordered_set<int> myset(a.begin(), a.end());
    
    for(j=0;j<lenj && retval==false;j++)
        if(myset.find(v-b[j])!=myset.end())
            retval=true;

    return retval;
    
}
