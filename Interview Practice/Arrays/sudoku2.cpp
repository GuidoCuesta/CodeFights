/*

Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

*/

bool sudoku2(std::vector<std::vector<char>> grid) 
{
    int leni=grid.size();
    int lenj=grid.at(0).size();
    int i,j,ii,jj;
    
    std::map<char,int> mymapi;
    std::map<char,int> mymapj;
    std::map<char,int> mymap33[3][3];
    std::pair<std::map<char,int>::iterator,bool> ret;
    
    bool retval=true;
    
    for(i=0;i<leni && retval==true;i++)
    {
        mymapi.clear();
        mymapj.clear();
        for(j=0;j<lenj && retval==true;j++)
        {
            if(grid.at(i).at(j)!='.')
            {
                ii=i/3;
                jj=j/3;    
                
                ret = mymapi.insert (std::pair<char,int>(grid.at(i).at(j),0));
                if (ret.second==false) 
                    retval=false;
                
                ret = mymap33[ii][jj].insert (std::pair<char,int>(grid.at(i).at(j),0));
                if (ret.second==false) 
                    retval=false;
            }
            
            if(grid.at(j).at(i)!='.')
            {
                ret = mymapj.insert ( std::pair<char,int>(grid.at(j).at(i),0) );
                if (ret.second==false) 
                    retval=false;
            }
        }
    }
    
    
    return retval;
}
