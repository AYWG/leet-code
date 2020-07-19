// Time: 13m 43s
class Solution {
public:
    string addStrings(string num1, string num2) {
    int i = 0;
    int carry = 0;

    int num1Len = num1.length();
    int num2Len = num2.length();

    string result;

    while (i < num1Len || i < num2Len) {
        int sum = 0;
        sum += carry;

        if (i < num1Len) {
            sum += num1[num1Len - i - 1] - '0';
        }
        if (i < num2Len) {
            sum += num2[num2Len - i - 1] - '0';
        }

        if (sum >= 20) {
            carry = 2;
        }
        else if (sum >= 10) {
            carry = 1;
        }
        else {
            carry = 0;
        }

        result.insert(result.begin(), (sum % 10) + '0');
        i++;
    }

    if (carry) {
        result.insert(result.begin(),  carry + '0');
    }

    return result;

}
};