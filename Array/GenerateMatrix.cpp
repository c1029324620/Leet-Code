#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n, vector<int>(n,0));
            int startx = 0, starty = 0, offset = 1, count = 1, loop = n / 2, mid = n / 2, i, j;
            while(loop--) {
                j = starty;
                i = startx;
                //left to right(top side) [start, end)
                for(j = starty; j < n - offset; j++) {
                    res[i][j] = count++;
                }
                //top to bottom(right side) [start, end)
                for(i = startx; i < n - offset; i++) {
                    res[i][j] = count++;
                }
                //right to left(bottom side) [start, end)
                for(;j > starty; j--) {
                    res[i][j] = count++;
                }
                //bottom to top(left side) [start, end]
                for(;i > startx; i--) {
                    res[i][j] = count++;
                }
                startx++;
                starty++;
                offset += 1;
            }
            //if n is an odd number
            if( n % 2 == 1) {
                res[mid][mid] = count;
            }
            return res;
        }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> test = solution.generateMatrix(5);
    for(int i = 0; i < test.size(); i++) {
        for(int j= 0; j < test.size(); j++) {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}