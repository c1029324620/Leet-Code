#include <iostream>

using namespace std;

int binarySearch(int [], int, int);

int main(int argc, char* argv[]) {
    int nums[] = {0,1,3,5,8,9,12,15,16};
    int location = binarySearch(nums, 9, 9);
    cout << location << endl;
    return 0;
}

//[left, right]
/*int binarySearch(int array[], int size, int target) {
    int left = 0, middle = 0;
    int right = size - 1;
    while(left <= right) {
        middle = (left + right) /2;
        if(array[middle] > target) {
            right = middle - 1;
        }
        else if(array[middle] < target) {
            left = middle + 1;
        }
        else if(array[middle] == target) {
            return middle;
        }
    }
    return -1;
}*/

// [left, right)
int binarySearch(int array[], int size, int target) {
    int left =0, middle = 0;
    int right = size;
    while(left < right) {
        middle = (left + right) / 2;
        if(array[middle] > target) {
            right = middle;
        }
        else if(array[middle] < target) {
            left = middle + 1;
        }
        else if(array[middle] == target) {
            return middle;
        }
    }
    return -1;
}