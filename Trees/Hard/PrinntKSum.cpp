vector<vector<int>> ans;
void printSum(vector<int> &vec,int j){
    vector<int> temp;
    for(int i=j;i<vec.size();i++){
        temp.push_back(vec[i]);
    }
    ans.push_back(temp);
}
void findSum(Node* root,int k,vector<int> &vec){
    if(root==NULL) return;
    vec.push_back(root->data);
    findSum(root->left,k,vec);
    findSum(root->right,k,vec);
    int sum=0;
    for(int j=vec.size()-1;j>=0;j--){
        sum += vec[j];
        if(sum==k){
            printSum(vec,j);
        }
    }
    vec.pop_back();
}

Node* PrintKSUm(Node* root,int k){
    vector<int> vec;
    findSum(root,k,vec);
    return ans;
}