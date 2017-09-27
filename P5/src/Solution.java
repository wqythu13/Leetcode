public class Solution
{
    public static String longestPalindrome(String s) {
        String result = "";
        int start = 0, end = 0, i, max = 1, l, r;

        for (i = 0; i < s.length(); i++) {
            l = i;
            r = i;
            while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                    l--;
                r++;
            }
            if ((r-l-1) > max) {
                max = r - l - 1;
                start = l+1;
                end = r-1;
            }
            l = i;
            r = i+1;
            while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                l--;
                r++;
            }
            if ((r-l-1) > max) {
                max = r - l - 1;
                start = l+1;
                end = r-1;
            }
        }
        result = s.substring(start,end+1);
        return result;
    }

    public static void main(String[] args) {
        String str="babad";
        System.out.println(longestPalindrome(str));
    }
}
