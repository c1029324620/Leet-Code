#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public: 
        int minSubArrayLength(int s, vector<int> &array) {
            int i = 0;
            int subLength = 0;
            int sum = 0;
            int result = INT32_MAX;
            for(int j = 0; j < array.size(); j++) {
                sum += array[j];
                while(sum >= s) {
                    subLength = j - i + 1;
                    result = subLength < result ? subLength : result;
                    sum = sum - array[i++];
                }
            }
            return result == INT32_MAX ? 0 : result;
        }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> array {2,3,1,2,4,3};
    cout << solution.minSubArrayLength(7, array) << endl;
    return 0;
}