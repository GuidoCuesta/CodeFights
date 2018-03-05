/*

Consider a special family of Engineers and Doctors. This family has the following rules:

Everybody has two children.
The first child of an Engineer is an Engineer and the second child is a Doctor.
The first child of a Doctor is a Doctor and the second child is an Engineer.
All generations of Doctors and Engineers start with an Engineer.
We can represent the situation using this diagram:

                E
           /         \
          E           D
        /   \        /  \
       E     D      D    E
      / \   / \    / \   / \
     E   D D   E  D   E E   D
Given the level and position of a person in the ancestor tree above, find the profession of the person.
Note: in this tree first child is considered as left child, second - as right.

Example

For level = 3 and pos = 3, the output should be
findProfession(level, pos) = "Doctor".

*/

std::string findProfession(int level, int pos) 
{
    string retval;
    int mylevel,max_pos,half_pos,mypos;
    char ans='E';
    
    mylevel=level;
    mypos=pos;
    while(mylevel>0)
    {
        max_pos=pow(2,mylevel);
        half_pos=max_pos/2;
        if(mypos>half_pos)
        {
            //MAKE A RIGHT (for left turn, no value change)
            if(ans=='E')
                ans='D';
            else //ans=='D'
                ans='E';
            mypos=mypos-half_pos;   
        }   

     mylevel=mylevel-1;
    }
    
    if(ans=='E')
        retval="Engineer";
    else if(ans=='D')
        retval="Doctor";
    else
        retval="Error!";
    
    return retval;
}
