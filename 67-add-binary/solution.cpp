class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0") return "0";
        string result;
        bool carry = false;
        int aLen = a.length();
        int bLen = b.length();
        int i = 0;
        int highestSetBitInd = 0;
        while (i < aLen || i < bLen) {
            int sum = 0;
            if (carry) {
                sum++;
                carry = false;
            }
            if (i < aLen) {
                sum += a[aLen - i - 1] - '0';
            }
            if (i < bLen) {
                sum += b[bLen - i - 1] - '0';
            }

            if (sum == 3) {
                result.insert(result.begin(), '1');
                highestSetBitInd = i;
                carry = true;
            } else if (sum == 2) {
                result.insert(result.begin(), '0');
                carry = true;
            } else if (sum == 1) {
                result.insert(result.begin(), '1');
                highestSetBitInd = i;
            }
            else {
                result.insert(result.begin(), '0');
            }

            i++;
        }

        if (carry) {
            result.insert(result.begin(), '1');
            highestSetBitInd = i;
        }

        result.erase(result.begin(), result.begin() + (result.size() - highestSetBitInd - 1));

        return result;
}
};