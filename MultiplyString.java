/**
 * Created by st0001 on 2017/3/11.
 */
public class MultiplyStr {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        String shortNum;
        String longNum;
        if (num1.length() < num2.length()) {
            shortNum = num1;
            longNum = num2;
        } else {
            shortNum = num2;
            longNum = num1;
        }
        int len = shortNum.length() + longNum.length();
        int[][] temp = new int[shortNum.length()][len];
        for (int k = 0; k < shortNum.length(); k++) {
            for (int l = 0; l < len; l++) {
                temp[k][l] = 0;
            }
        }
        int carry1;
        for (int i = shortNum.length() - 1; i >= 0; i--) {
            int x = shortNum.charAt(i) - '0';
            carry1 = 0;
            for (int j = longNum.length() - 1; j >= 0; j--) {
                int y = longNum.charAt(j) - '0';
                int mul = x * y + carry1;
                temp[i][len - longNum.length() + j - (shortNum.length() - i) + 1] = mul % 10;
                carry1 = mul / 10;
            }
            if (carry1 != 0) {
                temp[i][len - longNum.length() - (shortNum.length() - i)] = carry1;
            }
        }
        String result = "";
        int carry = 0;
        for (int i = len - 1; i >= 0; i--) {
            int num = 0;
            for (int j = shortNum.length() - 1; j >= 0; j--) {
                System.out.print(temp[j][i]);
                num += temp[j][i];
            }
            System.out.println();
            int bit = (num + carry) % 10;
            carry = (num + carry) / 10;
            char c = (char) (bit + '0');
            result = c + result;
        }
        int i = 0;
        while (result.charAt(i) == '0') {
            result = result.substring(i + 1);
        }
        return result;
    }

    public static void main(String[] args) {

    }
}
