# Problem: Sort Characters by Frequency

## Problem Statement
Given a string `str`, sort its characters in decreasing order based on the frequency of the characters.

**Link:** https://leetcode.com/problems/sort-characters-by-frequency/  
**Difficulty:** Medium  
**Topic:** Hash Table, String, Sorting

---

## Approach
**Approach 1: Frequency Array & Custom Sort**
We use an array of pairs (`pair<int, char> freq[256]`) to keep track of the frequency of each ASCII character.
1. Initialize the array such that each pair contains `0` for frequency and the respective character.
2. Iterate through the string `str` to calculate the frequencies of each character.
3. Sort the `freq` array using a custom `comparator` function (descending by frequency).
4. Iterate through the sorted `freq` array and append characters multiplied by their frequency to the result string.

**Approach 2: Hash Map & Vector Sort**
We use an `unordered_map` to map each character to its frequency.
1. Iterate through the string and count character frequencies in the map.
2. Transfer these key-value pairs into a `vector<pair<int, char>>` where the frequency is the first element of the pair.
3. Sort the vector using `.rbegin()` and `.rend()` which automatically sorts pairs in descending order based on their first element (the frequency).
4. Iterate through the sorted vector and append characters multiplied by their frequency to the result string.

---

## Code
### Approach 1 (Frequency Array)
```cpp
#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(pair<int,char> p1,pair<int,char> p2){
    if(p1.first>p2.first) return true;
    if(p1.first<p2.first) return false;
    return p1.second<p2.second;
}

string frequencySort(string& str){
    pair<int,char> freq[256];
    for(int i=0;i<256;i++){
        freq[i]={0,i};
    }

    for(char ch:str){
        freq[ch].first++;
    }
    
    sort(freq,freq+256,comparator);

    string ans = "";
    for(int i=0;i<256;i++) {
        if(freq[i].first>0) {
            ans.append(freq[i].first, freq[i].second);
        }
    }

    return ans;
}

int main(){
    string str="tree";
    string res=frequencySort(str);
    cout<<res<<endl;
}
```

### Approach 2 (Hash Map)
```cpp
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

string frequencySort(string& str){
    unordered_map<char,int> mp;
    for(auto ch:str){
        mp[ch]++;
    }
    vector<pair<int,char>> arr;
    for(auto it:mp){
        arr.push_back({it.second,it.first});
    }
    sort(arr.rbegin(),arr.rend());
    string ans="";
    for(int i=0;i<arr.size();i++) ans+=string(arr[i].first,arr[i].second);

    return ans;
}

int main(){
    string str="nitin";
    string res=frequencySort(str);
    cout<<res<<endl;
}
```

---

## Output
```
Input: str = "nitin"
Output: nniit 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Frequency Array) | `O(N)` | `O(1)` |
| Approach 2 (Hash Map) | `O(N)` | `O(1)` |

*(Where N is the length of the string. Sorting takes `O(1)` time because the number of unique characters is strictly bounded by 256 for standard ASCII)*

---

## Key Takeaway
Using `unordered_map` is often more readable and idiomatic for counting frequencies in C++, while arrays can offer slightly faster access times and memory predictability. The trick of storing pairs as `{frequency, character}` and reverse sorting is an elegant way to avoid custom comparators.
