#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

using namespace std;

class Solution
{
  public:
    vector< vector<int> > ThreeSum(int *arrays, int num, int target)
    {
        vector< vector<int> > results;
        for (size_t i = 0; i < num - 2; i++)
        {
            for (size_t j = i + 1; j < num-1; j++)
            {
                for (size_t k = j + 1; k < num; k++)
                {
                    if (target == arrays[i] + arrays[j] + arrays[k])
                    {
                        vector<int> temp;
                         cout << i << j << k <<'\n';
                        temp.push_back(arrays[i]);
                        temp.push_back(arrays[j]);
                        temp.push_back(arrays[k]);
                        results.push_back(temp);
                        // cout << results[0][0] << results[0][1] << results[0][2] <<'\n';
                        temp.clear();
                    }
                }
            }
        }
        cout << results[0].size() << results.size() <<'\n';
        cout << results[0][0] << results[0][1] << results[0][2];
        cout << results[1][0] << results[1][1] << results[1][2];
        vector<int> a;
        a.push_back(0);
        a.push_back(1);
        std::cout << "/* message */" << '\n';
        std::cout << a.size() << '\n';
        for (size_t i = 0; i < results.size(); i++)
        {
            
        }
        return results;
    }
};

int main()
{
    Solution s;
    int arrays[6] = {-1, 0, 1, 2, - 1, - 4};
    vector< vector<int> > results = s.ThreeSum(arrays, 6, 0);
    for (size_t i = 0; i < results.size(); i++)
    {
        for (size_t j = 0; j < results[i].size(); i++)
        {
            cout << results[i][j] << " ";
        }
        std::cout << endl;
    }
    system("pause");
    return 1;
}
