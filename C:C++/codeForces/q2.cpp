#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        int m = brr.size();
        long long cnt = 0;
        for(int i = 0; i<m; i++){
            int mini = 0;
            if(brr[i]!=arr[i]){
                for(int j = i+1; j<n; j++){
                    mini = min(mini, abs(brr[i]-arr[j]));
                }
                int x = abs(arr[i]-brr[i]);
                if(x<=(k+mini)) cnt+=x;
                else cnt+=k+mini;
            }
        }
        return cnt;
}
int main() {
		vector<int> arr = {-7, 9, 5};
		vector<int> brr = {7, -2, -5};
		cout<<minCost(arr, brr, 2);
		return 0;
}