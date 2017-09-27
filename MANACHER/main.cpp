//MANACHDR ALGORITHM
#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    // Insert '#'
    string str = "$#";
    for (int i = 0; i < s.size(); i++) {
        str += s[i];
        str += "#";
    }
    // process Palindrome
    vector<int> p(str.size(), 0);
    int mx = 0, id = 0, location = 0, length = 0;
    for (int i = 1; i < str.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (str[i+p[i]] == str[i-p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (length < p[i]) {
            length = p[i];
            location = i;
        }
    }
    return s.substr((location-length) / 2, length-1);
}

int main(){
    string str;
    cin >> str;
    cout<<longestPalindrome(str)<<endl;
    return 0;
}