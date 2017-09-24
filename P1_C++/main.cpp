#include <iostream>
#include <vector>
using namespace std;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        cout << nums.size() << endl;
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target) {
                    result.clear();
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        result.clear();
        //result.push_back(i);
        //result.push_back(j);
        return result;
    }

int main() {
    vector<int> i;
    i.clear();
    i.push_back(3);
    i.push_back(2);
    i.push_back(4);
    vector<int> res = twoSum(i, 6);
    //cout << res.size() << endl;
    cout << res[0] << " " << res[1] << endl;
    //cout << "Hello, World!" << std::endl;
    return 0;
}