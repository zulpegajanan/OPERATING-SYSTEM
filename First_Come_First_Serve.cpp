#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ct,at,pi,tat,wt;
	int tk,temp;
	cout<<"ENTER TOTAL NUMBER OF PROCESSES :";
	cin>>tk;
	cout<<"ENTER CPU TIME FOR EACH :\n";
	for(int i=0;i<tk;i++){
	    cout<<"P"<<i<<" : ";
	    cin>>temp;
	    ct.push_back(temp);
	    pi.push_back(i);
	}
	
	cout<<"if arrival time is given then enter 1 either 0 :";
	int ch;
	cin>>ch;
	if(ch==1){
	    for(int i=0;i<tk;i++){
	        cout<<"P"<<i<<" : ";
    	    cin>>temp;
    	    at.push_back(temp);
	    }
	}
	else{
	     for(int i=0;i<tk;i++){
    	    temp=0;
    	    at.push_back(temp);
	    }
	}
	for(int i=0;i<tk;i++){
	    for(int j=i+1;j<tk;j++){
	        if(at[i]>at[j]){
	            temp=at[i];
	            at[i]=at[j];
	            at[j]=temp;
	            
	            temp=ct[i];
	            ct[i]=ct[j];
	            ct[j]=temp;
	            
	            temp=pi[i];
	            pi[i]=pi[j];
	            pi[j]=temp;
	        }
	    }
	}
	
	
	cout<<"\nprocess  arr_time  cpu_time\n";
	for(int i=0;i<tk;i++){
	 cout<<pi[i]<<"\t"<<at[i]<<"\t"<<ct[i]<<"\n"; 
	}
	
	vector<int> ans;
	int sum=0,a,b;
	for(int i=0;i<tk;i++){
	     if(sum<at[i]){
	          ans.push_back(-1);
	          sum=at[i];
	     }
	     sum=sum+ct[i];
	     a=sum-at[i];
	     tat.push_back(a);
	     b=a-ct[i];
	     wt.push_back(b);
	     
	     ans.push_back(pi[i]);
	}
	cout<<"\nans\n\n";
	
// 	for(int i=0;i<ans.size();i++){
// 	     if(ans[i]==-1){
// 	          cout<<"...\t"<<"...\t"<<"...\n";
// 	     }
// 	     else{
// 	          cout<<"P"<<ans[i]<<"...\t"<<tat[i]<<"\t"<<wt[i]<<"\t";
// 	     }
// 	}
     
     cout<<"ORDER OF PROCESSES ARE RUNING :";
	
	for(int i=0;i<ans.size();i++){
	     cout<<"P"<<ans[i];
	     if(i!=ans.size()-1){
	          cout<<" ==> ";
	     }
	}
	
	cout<<"\n..........................(p-1 indicates for there ids no process runing )\n";
	
	
float ttat=0,twt=0;
     cout<<"TAT"<<"\tWT\n";
     for(int i=0;i<tk;i++){
	 cout<<tat[i]<<"\t"<<wt[i]<<"\n"; 
	 ttat=ttat+tat[i];
	 twt=twt+wt[i];
	}
	
	cout<<"\n\n\tAverage Turn Around Time (TAT) : "<<ttat/tk;
	cout<<"\n\tAverage Wait Time (WT) : "<<twt/tk;
	
	return 0;
}
