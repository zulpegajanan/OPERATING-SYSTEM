#include<bits/stdc++.h>
using namespace std;
int main()
{
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
	

	
	for(int i=0;i<tk;i++){
	     for(int j=i+1;j<tk;j++){
	          if(ct[i]>ct[j]){
	               temp=ct[i];
	               ct[i]=ct[j];
	               ct[j]=temp;
	               
	               temp=pi[i];
	               pi[i]=pi[j];
	               pi[j]=temp;
	               
	          }
	     }
	}
	int sum=0;
	cout<<"process\t    cpu_time\tTAT\tWT\n";
	for(int i=0;i<tk;i++){
	     sum=sum+ct[i];
	     cout<<"P"<<pi[i]<<"\t\t"<<ct[i]<<"\t"<<sum<<"\t"<<sum-ct[i]<<"\n";
	}

    return 0;
}
