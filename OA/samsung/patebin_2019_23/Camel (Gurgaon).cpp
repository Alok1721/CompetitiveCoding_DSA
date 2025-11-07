/* 
written with simplicity by Ankit Mittal 
Note - the code can be further optimized but for n = 8 it wil work fine 

A man has some camels with him.He has to take these camels to the opposite end.Each camel has some cost to go from one end to other.
->While going to opposite end , he will take 2 camels along with him, the cost will be the maximum of the cost of both the camels.
->On reaching opposite end, he will take one camel from opposite end to go back to first end, the cost will be taken as the cost of that camel.
->At the end, he has to move all the camels to the opposite end.
Find the minimum cost to take camels to opposite end.
Example->
INPUT
2              //No of test cases
4              //No of camels in first test case
1 2 8 9        //Cost of camels
6
14 45 73 86 95 98
OUTPUT
16
434

SOLUTION->
1) First he will take camel 1 and camel 2 to opposite end , so the cost will be -max(1,2)=2
2) Next he will come from camel 1 , cost will be- 1.
3) Now he will take camel 3 and camel 4 to opposite end , cost will be - max(8,9)=9
4) Now he will come back using camel 2 which was already at opposite end ,cost- 2
5) Now only camel 1 and camel 2 are left, he will take them both.cost=max(1,2)=2

Total cost = 2+1+9+2+2=16
*/ 

#include<bits/stdc++.h> 
using namespace std; 

int globalAns = INT_MAX; 

void solve(int a[], int n, bool vis[], int LtoR, int ans, int visCnt){

    if(ans>globalAns) return;                                                       /* optimization */
    if(visCnt == n){                                                                 /*base case // all visited */
       // TO CHECK ALL THE ANSWERS SIMPLY PRINT THE ANS EVERYTIME 
       globalAns = min(ans, globalAns);   
    }
    
    if(LtoR == 1){
    
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
             
                if(vis[i] == false && vis[j] == false){
                    int bada = max(a[i],a[j]); 
           
                     /* backtracking logic */
                    vis[i] = true; vis[j] = true; 
                    solve(a,n,vis,1-LtoR, ans + bada, visCnt + 2); 
                    vis[i] = false; vis[j] = false; 
                }
            
            }
        }
        
    }
    else{

        for(int i = 0; i<n; i++){
            if(vis[i] == true){
               /* backtracking logic */
                vis[i] = false; 
                solve(a,n,vis,1-LtoR, ans + a[i], visCnt - 1); 
                vis[i] = true; 
            }
        }
       
    }
}


int main(){
    
    int t; 
    cin>>t; 
    // solution by Ankit Mittal 
    while(t--){
        int n; 
        cin>>n; 
        int a[n]; 
        bool vis[n]; 
        for(int i = 0; i<n; i++)cin>>a[i]; 
        for(int i = 0; i<n; i++)vis[i] = false;
       
        solve(a,n,vis,1,0,0); 
        cout<<globalAns<<endl; 
    }
    
}