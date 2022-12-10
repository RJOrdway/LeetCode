/*
 * RJOrdway
 * 1st Solution, LeetCode 151: Reverse Words in a String
 * 
 * Method:  loops and control bit
 * 
 * Concern: Probably not space efficient
 * 
 * Result: Awful RT and memory use
 * 
 * Started:     11/13/22
 * Submitted:   11/13/22
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string reverseWords(string s);

int main() {
    string test1 = "the sky is blue";
    string answer1 = "blue is sky the";

    string test2 = "  hello world  ";
    string answer2 = "world hello";

    string test3 = "a good   example";
    string answer3 = "example good a";

    string test4 = "a";
    string answer4 = "a";

    string result1 = reverseWords(test1);
    string result2 = reverseWords(test2);
    string result3 = reverseWords(test3);
    string result4 = reverseWords(test4);

    cout << "test1: " << test1 << "\n";
    cout << "result1: " << result1 << "\n";
    cout << "answer1: " << answer1 << "\n";

    cout << "test2: " << test2 << "\n";
    cout << "result2: " << result2 << "\n";
    cout << "answer2: " << answer2 << "\n";

    cout << "test3: " << test3 << "\n";
    cout << "result3: " << result3 << "\n";
    cout << "answer3: " << answer3 << "\n";

    cout << "test4: " << test4 << "\n";
    cout << "result4: " << result4 << "\n";
    cout << "answer4: " << answer4 << "\n";
}

string reverseWords(string s) {
    vector<string> wordStack;
    int wordStartIndex;
    bool wordLoaded = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && wordLoaded) {
            wordStack.push_back(s.substr(wordStartIndex, (i-wordStartIndex)));
            wordLoaded = false;
        }
        else if (s[i] != ' ' && !wordLoaded) {
            wordStartIndex = i;
            wordLoaded = true;
        }
    }
    // catch final word
    if (wordLoaded) {
        wordStack.push_back(s.substr(wordStartIndex, (s.length() - wordStartIndex)));
    }

    s = "";
    for (int k = wordStack.size()-1; k >= 0; k--) {
        s = s + wordStack[k] + " ";
    }
    s.pop_back();
    return s;
}