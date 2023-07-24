class Solution {
public:
vector<vector<int> > threeSum(vector<int> &num) {
    //vector<vector<int>> c;
    //unordered_map<int,int> mp;
    // for(int i=0;i<num.size();i++){
    //     mp[num[i]]++;
    // }
    // for(int i=0;i<num.size();i++){
    //     for(int j=i+1;j<num.size();j++){
    //         int x = num[i]+num[j];
    //         int y = -x;
    //         if(mp.find(y)!=mp.end()){
    //             c.push_back({num[i],num[j],y});
    //         }
    //     }
    // }
    // return c;
    vector<vector<int>> v;
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        int front = i+1;
        int back = num.size()-1;
        int y = -num[i];
        
        while(front<back){
            int target = num[front]+num[back];
            if(target>y)
                back--;
            else if(target<y)
                front++;
            else{
                v.push_back({num[i],num[front],num[back]});
                break;
            }
                
        }
    }
    return v;
    
//     vector<vector<int> > res;

//     std::sort(num.begin(), num.end());

//     for (int i = 0; i < num.size(); i++) {
        
//         int target = -num[i];
//         int front = i + 1;
//         int back = num.size() - 1;

//         while (front < back) {

//             int sum = num[front] + num[back];
            
//             // Finding answer which start from number num[i]
//             if (sum < target)
//                 front++;

//             else if (sum > target)
//                 back--;

//             else {
//                 vector<int> triplet = {num[i], num[front], num[back]};
//                 res.push_back(triplet);
                
//                 // Processing duplicates of Number 2
//                 // Rolling the front pointer to the next different number forwards
//                 while (front < back && num[front] == triplet[1]) front++;

//                 // Processing duplicates of Number 3
//                 // Rolling the back pointer to the next different number backwards
//                 while (front < back && num[back] == triplet[2]) back--;
//             }
            
//         }

//         // Processing duplicates of Number 1
//         while (i + 1 < num.size() && num[i + 1] == num[i]) 
//             i++;

//     }
    
//     return res;
    
}
};