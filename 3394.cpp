#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
  bool checkValidCuts(int n, vector<vector<int>> &rectangles)
  {
    int nn = rectangles.size();
    vector<vector<int>> xaxis;
    vector<vector<int>> yaxis;

    for (auto &rec : rectangles)
    {
      xaxis.push_back({rec[0], rec[2]});
      yaxis.push_back({rec[1], rec[3]});
    }
    sort(xaxis.begin(), xaxis.end());
    sort(yaxis.begin(), yaxis.end());

    vector<vector<int>> px;
    vector<vector<int>> py;
    px.push_back(xaxis[0]);
    py.push_back(yaxis[0]);

    for (int i = 1; i < nn; i++){
      if (xaxis[i][0] < px.back()[1]){
        px.back()[1] = max(px.back()[1], xaxis[i][1]);
      }
      else{
        px.push_back(xaxis[i]);
      }
    }
    for (int i = 1; i < nn; i++){
      if (yaxis[i][0] < py.back()[1]){
        py.back()[1] = max(py.back()[1], yaxis[i][1]);
      }
      else{
        py.push_back(yaxis[i]);
      }
    }
    for (auto xx: px){
      cout << xx[0] << " " << xx[1] << endl;
    }
    return px.size() >= 3 || py.size() >= 3;
  }
  
};
int main(int argc, char **argv)
{
  Solution sol;

  vector<vector<int>> input = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
  bool ret = sol.checkValidCuts(5, input);
  cout << ret << endl;
  return 0;
}