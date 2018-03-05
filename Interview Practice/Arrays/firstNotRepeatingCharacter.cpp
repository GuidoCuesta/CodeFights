/*

Note: Write a solution that only iterates over the string once and uses O(1) additional memory, since this is what you would be asked to do during a real interview.

Given a string s, find and return the first instance of a non-repeating character in it. If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.

*/

char firstNotRepeatingCharacter(std::string s) 
{
    int lens=s.size();
    int i;
    int retindex=999999;
    char retval='_';
    std::map<char,int> mymap;
    std::pair<std::map<char,int>::iterator,bool> ret;
    std::map<char,int>::iterator it;
    
    for (i = 0; i < lens; i++)
    {  
        ret = mymap.insert ( std::pair<char,int>(s.at(i),i) );        

        if (ret.second==false)
            mymap.at(s.at(i))=-i;
    }

    for (auto& x: mymap)
        if(x.second>=0 && retindex>x.second)
                retindex=x.second;
    
    if(retindex==999999)
        retval='_';
    else
        retval=s.at(retindex);
    
    return retval;  
    
    
}
