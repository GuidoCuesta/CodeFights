/*

Given an absolute file path (Unix-style), shorten it to the format /<dir1>/<dir2>/<dir3>/....

Here is some info on Unix file system paths:

/ is the root directory; the path should always start with it even if it isn't there in the given path;
/ is also used as a directory separator; for example, /code/fights denotes a fights subfolder in the code folder in the root directory;
this also means that // stands for "change the current directory to the current directory"
. is used to mark the current directory;
.. is used to mark the parent directory; if the current directory is root already, .. does nothing.
Example

For path = "/home/a/./x/../b//c/", the output should be
simplifyPath(path) = "/home/a/b/c".

Here is how this path was simplified:
* /./ means "move to the current directory" and can be replaced with a single /;
* /x/../ means "move into directory x and then return back to the parent directory", so it can replaced with a single /;
* // means "move to the current directory" and can be replaced with a single /.

*/

std::string simplifyPath(std::string path) 
{
    std::string aux="";
    std::string retval="";
    std::vector<std::string> stack;
    int pos;
    int len;
    int i;
    
    stack.clear();
    
    do
    {

        len=path.size();
        pos=path.find('/');

        if(pos==0)
        {
            if(stack.size()==0 || (stack.size()>0 && stack.back()!="/"))
                stack.push_back("/");
                
            path=path.substr(1,len-1);
        }
        else if(pos!=0 && pos!=std::string::npos)
        {
            aux=path.substr(0,pos);   
            path=path.substr(pos,len-pos);
        }
        else if (pos==std::string::npos && len!=0)
        {
            aux=path.substr(0,len);
            path="";        
        }
        
        if (aux!="." && aux!=".." && aux!="")
        {    
            if(stack.size()==0)
                aux="/"+aux;
            stack.push_back(aux);
        }
        if (aux=="..")
            if(stack.size()>=3) // /last/..
            {
                stack.pop_back(); // get the / out
                stack.pop_back(); // get the last out
                stack.pop_back(); // get the / out 
            }
            else if (stack.size()==2) // last/..
            {
                stack.pop_back(); // get the last out
                stack.pop_back(); // get the / out 
            }
        aux="";

    }while(len);
    
    if(stack.size()>1 && stack.back()=="/")
        stack.pop_back();
    else if (stack.size()==0)
        stack.push_back("/");
    
    len=stack.size();
    for (i=0;i<len;i++)
        retval.append(stack.at(i));
    
    return retval;
    
}
