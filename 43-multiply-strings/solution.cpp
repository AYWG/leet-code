class Solution {
public:
    /*
 * Use similar algorithm to multiplication by hand.
 *  num1: on top
 *  num2: on bot
 *
 *  Let P = vector holding prelim products, each rep by a string
 *
 *  for every digit in num2, starting from ones:
 *      multiply with every digit in num1 to produce a preliminary product
 *      add prelim product to P
 *      append a 0 to every prelim product based on current num2 digit's distance from ones place (tens place -> add one 0)
 *
 *  add together all prelim products in P to get final product.
 * */
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    vector<string> P;

    for (int num2Ind = num2.size() - 1; num2Ind >= 0; num2Ind--) {
        int carry = 0;
        string prelimProduct;

        // Add any zeroes first.
        for (int numZeroes = num2.size() - num2Ind - 1; numZeroes > 0; numZeroes--) {
            prelimProduct += '0';
        }

        for (int num1Ind = num1.size() - 1; num1Ind >= 0; num1Ind--) {
            // Compute prelim product
            int prod = (num2[num2Ind] - '0') * (num1[num1Ind] - '0') + carry;
            carry = prod / 10;

            prelimProduct.insert(prelimProduct.begin(), (prod % 10) + '0');
        }
        if (carry) {
            prelimProduct.insert(prelimProduct.begin(),  carry + '0');
        }
        // Add prelim product to P
        P.push_back(prelimProduct);
    }

    string product = P[0];

    auto it = P.begin() + 1;
    while (it != P.end()) {
        product = addStrings(product, *it);
        it++;
    }
    return product;
}
    
    // num are non-negative
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

        carry = sum / 10;
        result.insert(result.begin(), (sum % 10) + '0');
        i++;
    }

    if (carry) {
        result.insert(result.begin(),  carry + '0');
    }

    return result;

}


};