#include <iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    bool exist[128];
    int size = s.length();
    int i = 0, j = 0, k = 0, result = 1;

    for (i = 0; i < 128; i++) exist[i] = false;
    if (size == 0) return 0;
    i = 0;
    while (j < size) {
        if (exist[s[j]]) {
            if (k > result) result = k;
            while (s[i] != s[j]) {
                exist[s[i]] = false;
                i++;
                k--;
            }
            i++;
            j++;
        }
        else {
            exist[s[j]] = true;
            k++;
            j++;
        }
    }
    return result > k ? result : k;
}

int main() {
    //int aaa[128] = {10};
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;
    //cout << aaa['a'-97] << endl;
    return 0;
}