bool check(Node* root,unordered_map<int,int> &mp){
    if(!root->left && !root->right){
        int value=root->data;
        mp[value]=1;
        if(mp.find(value-1)!=mp.end() && mp.find(value+1)!=mp.end()) return true;
        return false;
    }
    mp[root->data]=1;
    if(root->left){
        if(check(root->left,mp)) return true;
    }
    if(root->right){
        if(check(root->right,mp)) return true;
        return false;
    }
    return false;
}
bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_map<int,int> mp{{0,1}};
    return check(root,mp);
}