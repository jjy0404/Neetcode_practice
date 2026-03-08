// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//     // ... your code
//     return encoded_string;
// }
// Machine 2 (receiver) has the function:

// vector<string> decode(string s) {
//     //... your code
//     return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

// Example 1:

// Input: dummy_input = ["Hello","World"]

// Output: ["Hello","World"]

// Explanation:
// Machine 1:
// Codec encoder = new Codec();
// String msg = encoder.encode(strs);
// Machine 1 ---msg---> Machine 2

// Machine 2:
// Codec decoder = new Codec();
// String[] strs = decoder.decode(msg);
// Example 2:

// Input: dummy_input = [""]

// Output: [""]

class Solution {
public:

    string encode(vector<string>& strs) {
        string sumString;
        for (const auto& i : strs) {
            sumString = sumString + to_string(i.size()) + '#' + i;
        }
        return sumString;
    }

    vector<string> decode(string s) {
        vector<string> indString;
        string temString;
        string temNum;
        int num;
        
        for (char i : s) {
           
            if (num > 0) { //activate after '#' occur. adding char base on num
                temString = temString + i;
                num--;
                if (num == 0) { //if num == 0, new indvidual string will start
                    indString.push_back(temString);
                    temString = "";
                }
                continue;
            }
             if (i == '#') { //changing string to int
                num = stoi(temNum);
                temNum ="";
                if (num == 0) {
                    indString.push_back("");
                }
                continue;
            }
            temNum = temNum + i;  //checking how many char in next string
        }
        return indString;
    }
};