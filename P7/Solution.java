class Solution {
    public int reverse(int x) {
        long abs = (long)Math.abs(x);
        long result = 0;
        
        while (abs > 0) {
            result = result * 10 + abs % 10;
            abs /= 10;
        }
        if (x < 0) result = -1 * result;
        if (result > 2147483647 || result < -2147483648) result = 0;
        return (int)result;
    }
}
