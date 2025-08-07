#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int initial = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - initial)) {
                    initial = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return initial;
    }
};

int main() {
    cout << "=== Testing Three Sum Closest (LeetCode 16) ===" << endl;
    
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    int result1 = solution.threeSumClosest(nums1, target1);
    
    cout << "Test 1:" << endl;
    cout << "Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Target: " << target1 << endl;
    cout << "Closest Sum: " << result1 << endl;
    cout << "Difference: " << abs(target1 - result1) << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    int result2 = solution.threeSumClosest(nums2, target2);
    
    cout << "Test 2:" << endl;
    cout << "Array: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Target: " << target2 << endl;
    cout << "Closest Sum: " << result2 << endl;
    cout << "Difference: " << abs(target2 - result2) << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target3 = -2;
    int result3 = solution.threeSumClosest(nums3, target3);
    
    cout << "Test 3:" << endl;
    cout << "Array: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Target: " << target3 << endl;
    cout << "Closest Sum: " << result3 << endl;
    cout << "Difference: " << abs(target3 - result3) << endl;
    
    return 0;
}
