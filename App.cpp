#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // pointers
        int array_one_pointer = m - 1;
        int array_two_pointer = n - 1;
        int current_index = m + n - 1;

        // starting from the back of each array and working towards front
        while (array_one_pointer >= 0 && array_two_pointer >= 0) {

            // if the element in array one is greater than or equal to the element in array two
            if (nums1[array_one_pointer] >= nums2[array_two_pointer]) {

                // at the current index, assign element from array one
                nums1[current_index] = nums1[array_one_pointer];

                // decremenet for next iteration
                current_index--;
                array_one_pointer--;
            }

            // the element in array 2 is greater than the element in array one
            else {
                nums1[current_index] = nums2[array_two_pointer];

                // decremenet for next iteration
                current_index--;
                array_two_pointer--;
            }
        }

        // if there are still elements remaining in array two
        while (array_two_pointer >= 0) {
            nums1[current_index] = nums2[array_two_pointer];

            // decremenet for next iteration
            current_index--;
            array_two_pointer--;
        }
    }
};

int main()
{
    Solution solution;

    // example one
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2{2, 5, 6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);

    // print 
    cout << "Example One : ";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << " " << endl;

    // example two
    vector<int> nums3{1};
    m = 1;
    vector<int> nums4{};
    n = 0;
    solution.merge(nums3, m, nums4, n);

    // print
    cout << "Example Two : ";
    for (int i = 0; i < nums3.size(); i++) {
        cout << nums3[i] << " ";
    }
    cout << " " << endl;

	return 0;
}
