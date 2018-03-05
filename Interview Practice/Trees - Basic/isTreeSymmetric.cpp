/*

Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.

Example

For

t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 3,
            "left": null,
            "right": null
        },
        "right": {
            "value": 4,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}
the output should be isTreeSymmetric(t) = true.

Here's what the tree in this example looks like:

    1
   / \
  2   2
 / \ / \
3  4 4  3
As you can see, it is symmetric.

For

t = {
    "value": 1,
    "left": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    },
    "right": {
        "value": 2,
        "left": null,
        "right": {
            "value": 3,
            "left": null,
            "right": null
        }
    }
}
the output should be isTreeSymmetric(t) = false.

Here's what the tree in this example looks like:

    1
   / \
  2   2
   \   \
   3    3
As you can see, it is not symmetric.

*/


//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isTreeSymmetric(Tree<int> * t) 
{

    int fCondition=0;
    int level=1;
    int elements,half_elements;
    std::vector<Tree<int>*> myvect;
    std::vector<int> valuesr,valuesl;
    bool retval=true;
    int i,j,init,half,len,lenv;
    
    myvect.push_back(t);
    if(t==nullptr || (t->left==nullptr && t->right == nullptr))
        retval=true;
    else 
        while  (fCondition==0)
        {
            elements=pow(2,level);
            half_elements=elements/2;
            
            for (j=pow(2,level-1)-1;j<pow(2,level)-1;j++)
                if(myvect.at(j)!=nullptr)
                {
                    myvect.push_back(myvect.at(j)->left);
                    myvect.push_back(myvect.at(j)->right);
                }   
                else
                {
                    myvect.push_back(nullptr);
                    myvect.push_back(nullptr);
                }

            len=myvect.size();
            init=myvect.size()-elements;
            half=myvect.size()-half_elements;
            valuesl.clear();
            valuesr.clear();

            for(i=init;i<half;i++)
            {
                if(myvect.at(i)!=nullptr)
                    valuesl.push_back(myvect.at(i)->value);
                else
                    valuesl.push_back(0);
            }
            for(i=half;i<len;i++)
            {
                if(myvect.at(i)!=nullptr)
                    valuesr.push_back(myvect.at(i)->value);
                else
                    valuesr.push_back(0);
            }    

            std::reverse(valuesr.begin(),valuesr.end());
            if(valuesl!=valuesr)
            {
                retval=false;
                break;
            }

            lenv=valuesl.size();
            fCondition=1;
            for(i=0;i<lenv;i++)
                if(valuesl.at(i)!=0 || valuesr.at(i)!=0)
                {
                    fCondition=0;
                    break;
                }    

            level++;
        }
    
    return retval;
    
}
