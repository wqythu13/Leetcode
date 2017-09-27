class Solution {
    public static int myAtoi(String str) {
        if (str == "") return 0;
        if (str.length() == 0) return 0;
        int i = 0;
        int length = str.length();
        long result = 0;
        int sign = 1;
        long INT_MIN = 2147483647;

        if (str == "-2147483648") return -2147483648;
        while (str.charAt(i) == ' ' || str.charAt(i) == '\t' || str.charAt(i) == '\n') i++;
        if (str.charAt(i) == '-') {
            i++;
            sign = -1;
        }
        else if (str.charAt(i) == '+') {
            i++;
        }
        while (i < length) {
            if (str.charAt(i) > '9' || str.charAt(i) < '0') break;
            result = result * 10 + str.charAt(i) - '0';
            i++;
            if ((result > 2147483647) && (sign == 1)) return 2147483647;
            if ((result > 2147483647) && (sign == -1)) return -2147483648;
        }
        //if (str.charAt(0) == '-') result = -1 * result;
        if (sign == -1) result = -1 * result;
        return (int)result;
    }

    public static void main(String[] args) {
        String str = "";
        System.out.println(myAtoi(str));
    }
}
