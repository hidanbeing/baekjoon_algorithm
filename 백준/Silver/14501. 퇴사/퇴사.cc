#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[16], p[16];
int res =-1;
void dfs(int day,int sum){
    if (day>=n){
        // cout<<day<<","<<sum<<endl;
        res = max(res, sum);
        return;
    }

    // 오늘 상담 하기
    if (day+t[day]<=n){
        dfs(day+t[day], sum+p[day]);
    }


    // 오늘 상담 안하기
    dfs(day+1, sum);

}

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t[i]>>p[i];
    }

    dfs(0,0);

    cout<<res;
}