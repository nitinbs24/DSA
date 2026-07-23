#include<iostream>
#include<vector>
using namespace std;

vector<int> pascalTriangleRow(int n){
    vector<int> row;
    long long var = 1;
    row.push_back(var);
    
    for(int i = 1; i < n; i++){
        var = var * (n - i) / i;
        row.push_back(var);
    }
    return row;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> row = pascalTriangleRow(n);
    for(auto& c : row){
        cout << c << " ";
    }
    cout << "\n";
}
