#include<bits/stdc++.h>
using namespace std;
pair<string,string> findHighest(vector<string> arr){
    unordered_map<string,int> mp={
        {"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},
        {"jack",10},{"queen",10},{"king",10},{"ace",11}
    };

    unordered_map<string,int>rank={{"",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},
        {"jack",11},{"queen",12},{"king",13},{"ace",14}};
    string highest_card="",second_highest_card="";
    int total_sum=0,ace_count=0;
    for(int i=0;i<arr.size();i++){
        if(rank[arr[i]]>rank[highest_card]){
            second_highest_card=highest_card;
            highest_card=arr[i];
        }
        else if(rank[arr[i]]>rank[second_highest_card]){
            second_highest_card=arr[i];
        }
        if(arr[i]=="ace"){
            ace_count++;
        }
        total_sum+=mp[arr[i]];
    }
    while(total_sum>21 && ace_count>0){
        total_sum-=10;
        ace_count--;
        if(ace_count==0){
            highest_card=second_highest_card;
        }
    }
    
    

    if(total_sum==21)
    {
        return {"blackjack",highest_card};
    }
    else if(total_sum>21)
    {
        return {"above",highest_card};
    }
    else
    {
        return {"below",highest_card};
    }
}
int main() {
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<string,string> result=findHighest(arr);
    cout<<result.first<<" "<<result.second<<endl;
    return 0;
    
}


// #include<bits/stdc++.h>
// using namespace std;

// pair<string,string> findHighest(vector<string> arr){
//     unordered_map<string,int> mp={
//         {"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},
//         {"jack",10},{"queen",10},{"king",10},{"ace",11}
//     };

//     unordered_map<string,int> rank={
//         {"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},
//         {"jack",11},{"queen",12},{"king",13},{"ace",14}
//     };
    
//     int total_sum = 0;
//     int ace_count = 0;
    
//     // Calculate initial sum and count aces
//     for(string card : arr){
//         total_sum += mp[card];
//         if(card == "ace"){
//             ace_count++;
//         }
//     }
    
//     // Reduce aces from 11 to 1 if total > 21
//     int aces_used_as_1 = 0;
//     while(total_sum > 21 && aces_used_as_1 < ace_count){
//         total_sum -= 10;  // Change ace from 11 to 1
//         aces_used_as_1++;
//     }
    
//     // Find highest card considering which aces are reduced
//     string highest_card = "";
//     int highest_rank = 0;
//     int aces_seen = 0;
    
//     for(string card : arr){
//         int effective_rank;
        
//         if(card == "ace"){
//             aces_seen++;
//             if(aces_seen <= aces_used_as_1){
//                 // This ace is counted as 1, so lowest rank
//                 effective_rank = 0; // Lower than rank 1
//             } else {
//                 // This ace is counted as 11, keep high rank
//                 effective_rank = rank[card];
//             }
//         } else {
//             effective_rank = rank[card];
//         }
        
//         if(effective_rank > highest_rank){
//             highest_rank = effective_rank;
//             highest_card = card;
//         }
//     }
    
//     // Return result based on total sum
//     if(total_sum == 21){
//         return {"blackjack", highest_card};
//     }
//     else if(total_sum > 21){
//         return {"above", highest_card};
//     }
//     else{
//         return {"below", highest_card};
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<string> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     pair<string,string> result = findHighest(arr);
//     cout << result.first << " " << result.second << endl;
//     return 0;
// }