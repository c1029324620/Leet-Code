#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int k = nums.size() - 1;
            vector<int> result(nums.size(), 0);
            for(int i = 0, j = k; i <=j;) {
                if(nums[i] * nums[i] > nums[j] * nums[j]) {
                    result[k--] = nums[i] * nums[i];
                    i++;
                }
                else {
                    result[k--] = nums[j] * nums[j];
                    j--;
                }
            }
            return result;
        }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> array = {-4,-1,0,3,10};
    vector<int> result = solution.sortedSquares(array);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}