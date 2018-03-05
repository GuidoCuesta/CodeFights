/*

You have an array of integers nums and an array queries, where queries[i] is a pair of indices (0-based). Find the sum of the elements in nums from the indices at queries[i][0] to queries[i][1] (inclusive) for each query, then add all of the sums for all the queries together. Return that number modulo 109 + 7.

Example

For nums = [3, 0, -2, 6, -3, 2] and queries = [[0, 2], [2, 5], [0, 5]], the output should be
sumInRange(nums, queries) = 10.

The array of results for queries is [1, 3, 6], so the answer is 1 + 3 + 6 = 10.

*/

int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) 
{
    std::unordered_set<int> sums;
    int i,leni=queries.size(),lenn=nums.size(),ind_sup,ind_inf;
    long int num=0;
    long int retval=0;
    
    std::vector<int> prefixRow;
    
    num=0;
    for(i=0;i<lenn;i++)
    {
        num=num+nums[i];
        prefixRow.push_back(num);
    }    

    for (i=0;i<leni;i++)
    {
        ind_sup=queries[i][1];
        ind_inf=queries[i][0];
        num=prefixRow[ind_sup];
        if(ind_inf>0)
            num=num-prefixRow[ind_inf-1];

        retval=(retval+num)%1000000007;
    }

    return (retval+1000000007)%1000000007;
    
    
}
