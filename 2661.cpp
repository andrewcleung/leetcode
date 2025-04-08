#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int numRows = mat.size();
        int numCols = mat[0].size();
        vector<pair<int,int>> positionMap(numRows * numCols);
        vector<int> rowCount(numRows, 0);
        vector<int> colCount(numCols, 0);

        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++)
            {
                positionMap[mat[i][j] - 1] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++){
            auto& [row, col] = positionMap[arr[i] - 1];
            
            if ( ++rowCount[row] == numCols || ++colCount[col] == numRows )
                return i;
        }
        return -1;
    }
};

int main(int argc, char **argv)
{

    return 0;
}