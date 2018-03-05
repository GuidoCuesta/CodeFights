/*

Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]

*/

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) 
{
    std::vector<std::vector<int>> rota;
    int i,roti;
    int j,rotj;
    int colsa, rowsa;
    rota=a;
    colsa=a.size();
    rowsa=a.at(0).size();
    
    for(i=0;i<colsa ;i++)
        for(j=0,roti=colsa-1;j<rowsa && roti>=0;j++,roti--)
            rota.at(i).at(roti)=a.at(j).at(i);
        
    return rota;
}
