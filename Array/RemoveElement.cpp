#include <iostream>

using namespace std;

int removeElement(int array[], int size, int target);
int removeElement2(int [], int, int);
int removeElement3(int [], int, int);

int main(int argc, char* argv[]) {
    int nums[] = {0,1,2,2,3,0,4,2};
    int result = removeElement3(nums, 8, 3);
    for(int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
//two for loop statment, O(n^2) for time complexity, O(1) for space complexity.
int removeElement(int array[], int size, int target) {
    int result = size;
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            for(int j = i + 1; j < size; j++) {
                array[j - 1] = array[j];
            }
            result--;
            i--;
        }
    }
    return result;
}

//double pointers method
int removeElement2(int array[], int size, int target) {
    int slowPtr = 0;
    for(int fastPtr = 0; fastPtr < size; fastPtr++) {
        if(array[fastPtr] != target) {
            array[slowPtr++] = array[fastPtr];
        }
    }
    return slowPtr;
}

//
int removeElement3(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        while(left <=right && array[left] != target) {
            left++;
        }
        while(left <= right && array[right] == target) {
            right--;
        }
        if(left < right) {
            array[left++] = array[right--];
        }
    }
    return left;
}




