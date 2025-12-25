/*

A classic queue problem is the "First Unique Character in a String." The Problem: Given a string, find the first
character that does not repeat. If all characters repeat, return a specific indicator.

The Logic: Use a frequency array to count occurrences and a Queue to maintain the order of characters as they appeared.

*/

#include <bits/stdc++.h>
using namespace std;

char findFirstUnique(const string &str) {
    // queue to store urutan keduluan "first unique"
    // while to iterate through all letters, add to count
    // if count > 1, pop
    // if queue empty, return `\0`

    queue<char> queue_of_unique_chars;
    // char count[256];
    unordered_map<char, int> count;

    for (auto letter : str) {
        count[letter]++; // by default, value is 0, so using ++ is safe

        if (count[letter] == 1)
            queue_of_unique_chars.push(letter);
        else if (count[letter] > 1)
            queue_of_unique_chars.pop();
    }

    return queue_of_unique_chars.empty() ? '\0' : queue_of_unique_chars.front();
}

auto main() -> int {
    vector<string> testCases = {"embedded", "zephyr", "aabbcc"};

    for (const string &str : testCases) {
        char result = findFirstUnique(str);

        cout << "Input: " << str << " -> First Unique: ";
        if (result == '\0')
            cout << "None";
        else
            cout << result;
        cout << endl;
    }

    return 0;
}