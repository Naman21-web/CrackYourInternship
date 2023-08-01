#include <bits/stdc++.h>
using namespace std;

int minCost(priority_queue<pair<int,int>> pq){
	int hor=0;//No of cuts in hor direc
	int ver=0;//No of cuts in ver direc
	/*
	//If pq.top().second == 1 -> cost += pq.top().second*(hor+1),ver++;
	//if we have to make cut in ver direc then we need to make hor+1 cuts as this many peices are present 
	//and also we need to increase ver as one new cut has been made in ver direc
	// similalry,If pq.top().second == 2 -> cost += pq.top().second*(ver+1),hor++;
	*/
	int totcost=0;
	while(!pq.empty()){
		if(pq.top().second==1){
			int curcost = pq.top().first;
			pq.pop();
			totcost += curcost*(hor+1);
			ver++;
		}
		else{
			int curcost = pq.top().first;
			pq.pop();
			totcost += curcost*(ver+1);
			hor++;
		}
	}
	return totcost;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	int n,m;
	cin>>n>>m;
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<n-1;i++){
		int input;
		cin>>input;
		pq.push({input,1});//vertical cut lagane ki cost
	}
	for(int i=0;i<m-1;i++){
		int input;
		cin>>input;
		pq.push({input,2});//horizontal cut lagane ki cost
	}
	int ans = minCost(pq);
    cout<<ans<<" ";
	return 0;
}