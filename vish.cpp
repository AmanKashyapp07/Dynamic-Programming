#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int threeSum(std::vector<int> &nums1, std::vector<int> &nums2, unordered_map<int, int> &hash, int target = 0)
{
    int count = 0;
    std::sort(nums1.begin(), nums1.end());

    for (size_t i = 0; i < nums1.size(); ++i)
    {
        int left = i + 1, right = nums1.size() - 1;
        while (left < right)
        {
            int sum = nums1[i] + nums1[left] + nums1[right];

            if (sum == target)
            {
                int count1 = hash[nums1[i]] == 8 ? nums1[i] : 0;
                int count2 = hash[nums1[left]] == 8 ? nums1[left] : 0;
                int count3 = hash[nums1[right]] == 8 ? nums1[right] : 0;
                count = max(count, count1 + count2 + count3);

                ++left;
                --right;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
    }

    return count;
}

int main()
{
    std::vector<int> nums1 = {3, 5, 2, 6, 1, 4};
    std::vector<int> nums2 = {8, 8, 3, 2, 8, 1};
    int target = 10;
    unordered_map<int, int> hash;

    for (size_t i = 0; i < nums1.size(); i++)
    {
        hash[nums1[i]] = nums2[i];
    }

    cout << threeSum(nums1, nums2, hash, target) << endl;

    return 0;
}
