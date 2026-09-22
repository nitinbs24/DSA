#include <climits>
#include<iostream>
#include <numeric>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxScore(vector<int>& cardPoints, int k){

        int n=cardPoints.size();
        if(k<0 || k>n) return -1;
        if(k==0) return 0;
        if(k==n) accumulate(cardPoints.begin(),cardPoints.end(),0);

        int maxScore=INT_MIN;

        for(int leftCount=0;leftCount<=k;leftCount++){

            int rightCount=k-leftCount;

            int score=0;

            for(int i=0;i<leftCount;i++) score+=cardPoints[i];

            for(int i=0;i<rightCount;i++) score+=cardPoints[n-i-1];

            maxScore=max(maxScore,score);
        }
        return maxScore;
    }
};
int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution solution;
    cout << solution.maxScore(cardPoints, k) << endl;

    return 0;
}