# Problem: Reverse Words in a String

## Problem Statement
Given an input string `s`, reverse the order of the **words**.
A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Link:** [LeetCode 151](https://leetcode.com/problems/reverse-words-in-a-string/)  
**Difficulty:** Medium  
**Topic:** String, Two Pointers

---

## Approach

### Approach 1 (Using Extra Array/Vector)
1. Iterate over the string `s` from left to right.
2. Build words character by character. When a space is encountered, push the completed word into a `vector<string>` and reset the word variable.
3. Handle the last word if the string doesn't end with a space.
4. Reverse the `vector<string>`.
5. Iterate through the reversed vector and build the final result string, appending a single space between words.

### Approach 2 (Optimal - Traversing from the end)
1. Iterate over the string `s` from right to left using a pointer `i`.
2. Skip any trailing spaces by decrementing `i`.
3. Once a non-space character is found, mark its position as `end`.
4. Continue decrementing `i` until a space is found. The substring from `i+1` to `end` is a word.
5. Append this word to the `result` string. If the `result` string is not empty (meaning it's not the first word), append a space before the word.
6. This avoids the need for an extra vector and directly builds the result.

---

## Code

### Solution 1 (Vector)
```cpp
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

string reverseWord(string s){
    vector<string> words;
    string word="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        else if(!word.empty()){
            words.push_back(word);
            word="";
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }
    reverse(words.begin(),words.end());

    string result="";
    for(int w=0;w<words.size();w++){
        result+=words[w];
        if(w<words.size()-1){
            result+=" ";
        }
    }
    return result;
}

int main(){
    string s="Hello World";
    cout<<reverseWord(s)<<endl;
}
```

### Solution 2 (Optimal / Right-to-Left)
```cpp
#include<iostream>
using namespace std;

string reverseWords(string s){
    int i=s.size()-1;
    string result="";
    while(i>=0){
        // skip spaces
        while(i>=0 && s[i]==' ') i--;

        if(i<0) break;
        int end=i;

        // find the start of the word
        while(i>=0 && s[i]!=' ') i--;

        string word=s.substr(i+1,end-i);

        if(!result.empty()) result+=" ";
        result+=word;
    }
    return result;
}

int main(){
    string s="Hello World";
    cout<<reverseWords(s)<<endl;
}
```

---

## Output
```text
Input: "Hello World"
Output: "World Hello"

Input: "  hello world  "
Output: "world hello"

Input: "a good   example"
Output: "example good a"
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Vector) | O(N) | O(N) |
| Approach 2 (Right-to-Left) | O(N) | O(N) |

*(Note: In C++, strings are mutable, so Space Complexity is O(N) mainly due to the result string being built. In some languages, or if manipulating the string strictly in-place with `std::reverse`, space can be optimized to O(1).)*

---

## Key Takeaway
Traversing the string backwards is a powerful technique for string-reversal problems, allowing us to naturally extract and append words in the desired reverse order without extra data structures like a Stack or Array.
