/*

Given an encoded string, return its corresponding decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times. Note: k is guaranteed to be a positive integer.

Note that your solution should have linear complexity because this is what you will be asked during an interview.

Example

For s = "4[ab]", the output should be

decodeString(s) = "abababab";

For s = "2[b3[a]]", the output should be

decodeString(s) = "baaabaaa";

For s = "z1[y]zzz2[abc]", the output should be

decodeString(s) = "zyzzzabcabc".

*/ 

std::string decodeString(std::string s) 
{
    int pos,posc;
    int multiplier;
    int i;
    int number;
    std::string pattern,head,tail;
    
    pos=s.find_last_of('[');    
    while(pos!=std::string::npos)
    {
        i=1;
        multiplier=0;
        number=s.at(pos-i)-'0';
        while (number>=0 && number <=9)
        {
            multiplier=multiplier+(number*pow(10,i-1));
            i++;
            if(pos-i>=0)
                number=s.at(pos-i)-'0';
            else
                break;
        }
        
        posc=s.find_first_of(']',pos);

        pattern=s.substr(pos+1,posc-(pos+1));
        head=s.substr(0,pos-(i-1));
        tail=s.substr(posc+1,s.size()-(posc+1));

        s=head;
        for(i=0;i<multiplier;i++)
            s.append(pattern);
        s.append(tail);
            
        pos=s.find_last_of('[');
    }

    return s;
}
