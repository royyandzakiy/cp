#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring_MoreVerbose(string input_str) {
    unordered_map<char, int> char_substr_idx_map;
    string curr_substr = "";
    int maxlen = 0;

    for (char ch : input_str) {
        auto it = char_substr_idx_map.find(ch);

        // if the char being searched is never added to the map, it doesnt exist
        bool char_exist_in_substr = it != char_substr_idx_map.end();
        if (char_exist_in_substr) {
            // create new substr
            int new_substr_start_idx = curr_substr.find(ch);
            curr_substr = curr_substr.substr(new_substr_start_idx + 1); // cut off last found char in substr
        }

        curr_substr += ch;
        char_substr_idx_map[ch] = curr_substr.size() - 1; // added to end of substr

        maxlen = max(maxlen, (int)curr_substr.size());
    }

    return maxlen;
}

int lengthOfLongestSubstring(string input_str) {
    unordered_map<char, int> char_substr_idx_map;
    string curr_substr = "";
    int maxlen = 0;

    for (char ch : input_str) {
        if (auto it = char_substr_idx_map.find(ch); it != char_substr_idx_map.end()) {
            int new_substr_start_idx = curr_substr.find(ch);
            curr_substr = curr_substr.substr(new_substr_start_idx + 1); // cut off last found char in substr
        } else {
            // if the char being searched was never added to the map, it doesnt exist, hence reaching .end
        }

        curr_substr += ch;
        char_substr_idx_map[ch] = curr_substr.size() - 1; // added to end of substr

        maxlen = max(maxlen, (int)curr_substr.size());
    }

    return maxlen;
}

/*
iteration:
    abcabcbb
        abc bca cab abc cb
    bbbbb
        b
    pwwkew
        pw wke kew

pseudocode
    for (char in input_str)
        if (exist_idx = find_idx; !exist)
            substr.add(char)
            if (maxlen < substr.size) maxlen = substr.size
        else
            substr = substr[find_idx:]
            substr.add
            if (maxlen < substr.size) maxlen = substr.size

    return maxlen
*/

auto main() -> int {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}