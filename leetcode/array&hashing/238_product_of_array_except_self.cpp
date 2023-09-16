#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                product *= nums[j];
            }

            ans.push_back(product);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums{1, 2, 3, 4};
    vector<int> ans = s.productExceptSelf(nums);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
