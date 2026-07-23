#include<iostream>
#include<vector>
using namespace std;

void pascalTriangle(int n){
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i) row.push_back(1);
            else{
                row.push_back(nums[i-1][j-1]+nums[i-1][j]);
            }
            cout<<row.back()<<" ";
        }
        nums.push_back(row);
        cout<<"\n";
    }

}
int main(){
    int n;
    cin>>n;

    pascalTriangle(n);
}