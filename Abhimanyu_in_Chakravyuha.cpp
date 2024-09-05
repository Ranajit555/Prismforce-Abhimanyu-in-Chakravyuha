#include <bits/stdc++.h>
using namespace std;

//suppose the maximun power is 200
int dp[14][200][14][14];
int regenerate_power;

bool is_lose(int ind,int power,int skip,int reg,vector<int>vc){
    if(power<0){return false;}
    if(ind==vc.size()){
        if(power>=0){return true; }
        else{ 
            return false;
        }
    }
    bool possibility=false;
    if(power>=vc[ind]){
        possibility=possibility || is_lose(ind+1,power-vc[ind],skip,reg,vc);
    }
    if(ind==2 || ind==6){
        vc[ind+1]+=vc[ind]/2;
    }
    if(skip>0){
        possibility=possibility || is_lose(ind+1,power,skip-1,reg,vc);
    }
    if(reg>0){
        possibility=possibility || is_lose(ind,regenerate_power,skip,reg-1,vc);
    }
    return dp[ind][power][skip][reg]=possibility;
}

void solved(){
    memset(dp,-1,sizeof(dp));
    vector<int>vc(11);
    for(int i=0;i<11;i++){
        cin>>vc[i];
    }
    int p,s,r;
    cin>>p>>s>>r;
    regenerate_power=p;
    if(is_lose(0,p,s,r,vc)){
        cout<<"Success"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        solved();
    }
	return 0;
}
