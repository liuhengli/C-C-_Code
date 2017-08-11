#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std; //vector 需要使用namespace

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //于2016.6.10徒手重写
        map<int, int> mapping;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapping.find(target - nums[i]) != mapping.end())
            {
                result.push_back(mapping[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            mapping[nums[i]] = i;
        }
        return result;
    }

    int *twoSum(int arrays[], int num, int target)
    {
        //使用数组遍历
        // int r[2] = {0};//warning: address of local variable
        //It is because you declare buffer on the stack
        int *r = new int[2];
        for (size_t i = 0; i < num; i++)
        {
            int temp = target - arrays[i];
            for (size_t j = i + 1; j < num; j++)
            {
                if (temp == arrays[j])
                {
                    r[0] = i;
                    r[1] = j;
                }
            }
        }
        return r;
    }

    vector<int> twoSum3(int arrays[], int num, int target)
    {
        //使用数组遍历
        // int r[2] = {0};//warning: address of local variable
        //It is because you declare buffer on the stack
        vector<int> r;
        for (size_t i = 0; i < num; i++)
        {
            int temp = target - arrays[i];
            for (size_t j = i + 1; j < num; j++)
            {
                if (temp == arrays[j])
                {
                    r.push_back(i);
                    r.push_back(j);
                }
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    int target = 9;
    int arrays[4] = {2, 7, 11, 15};
    vector<int> nums(arrays, arrays + 4);
    // nums.push_back[2];
    // nums.push_back[7];
    // nums.push_back[11];
    // nums.push_back[15];
    //方法1
    vector<int> result = s.twoSum(nums, target);
    cout << result[0] << result[1] << endl;

    //方法2
    int *result2;
    result2 = s.twoSum(arrays, 4, target);
    cout << result2[0] << " " << result2[1] << endl;
    delete[] result2;

    //方法3
    vector<int> result3;
    result3 = s.twoSum3(arrays, 4, target);
    cout << result3[0] << " " << result3[1] << endl;
    system("pause");
    return 0;
}