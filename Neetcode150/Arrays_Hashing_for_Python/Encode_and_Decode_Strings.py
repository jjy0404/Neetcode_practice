# Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

# Machine 1 (sender) has the function:

# string encode(vector<string> strs) {
#     // ... your code
#     return encoded_string;
# }
# Machine 2 (receiver) has the function:

# vector<string> decode(string s) {
#     //... your code
#     return strs;
# }
# So Machine 1 does:

# string encoded_string = encode(strs);
# and Machine 2 does:

# vector<string> strs2 = decode(encoded_string);
# strs2 in Machine 2 should be the same as strs in Machine 1.

# Implement the encode and decode methods.

class Solution:

    def encode(self, strs: List[str]) -> str:
        result = "";
        for ind in strs:
            result = result + str(len(ind)) + '#' + ind;
        return result;


    def decode(self, s: str) -> List[str]:
        result = [];
        i = 0;

        while i < len(s):
            j = i;
            while s[j] != '#':
                j += 1;
            length = int(s[i:j]);
            i = j + 1;
            j = i + length;
            result.append(str(s[i:j]));
            i = j;

        return result;
