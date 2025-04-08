#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; i++){
            array<int, 9> ht = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (ht[board[i][j] - '1']++ == 1) return false;
            }
        }
        // column
        for (int i = 0; i < 9; i++){
            array<int, 9> ht = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (ht[board[j][i] - '1']++ == 1) return false;
            }
        }

        // 3x3
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                array<int, 9> ht = {0};
                for (int ii = 0; ii < 3; ii++)
                {
                    for (int jj = 0; jj < 3; jj++)
                    {
                        if (board[3 * i + ii][3 * j + jj] == '.')
                            continue;
                        if (ht[board[3 * i + ii][3 * j + jj] - '1']++ == 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv){

  return 0;
}