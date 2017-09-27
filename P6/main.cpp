#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    string result = "";
    int length = s.size();
    int rows = 1, isOdd = 0, colomn = 0, pattern = 2 * numRows - 2;

    if (numRows == 1) return s;

    while (result.size() < length) {
        if (rows == 1) {
            if (colomn * pattern < length) {
                result += s[colomn*pattern];
                ++colomn;
            }
            else {
                ++rows;
                colomn = 0;
                isOdd = 0;
            }
        }
        if (rows > 1 && rows < numRows) {
            if (!isOdd) {
                if (colomn * pattern + rows - 1 < length) {
                    result += s[colomn*pattern+rows-1];
                    isOdd = 1 - isOdd;
                }
                else {
                    ++rows;
                    colomn = 0;
                    isOdd = 0;
                    continue;
                }
            }
            else {
                if (colomn * pattern + pattern - rows + 1 < length) {
                    result += s[colomn*pattern+pattern-rows+1];
                    isOdd = 1 - isOdd;
                    ++colomn;
                }
                else {
                    ++rows;
                    colomn = 0;
                    isOdd = 0;
                    continue;
                }
            }
        }
        if (rows == numRows) {
            if (colomn * pattern + numRows - 1 < length) {
                result += s[colomn*pattern+numRows-1];
                ++colomn;
            }
        }
    }
    return result;
}

int main(){
    string str="PAYPALISHIRING";
    cout << convert(str, 3) << endl;
    return 0;
}