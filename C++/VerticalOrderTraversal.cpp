void findMinMax(Node* root,int idx,int& minR,int& maxR){
        if(root==NULL){
            return;
        }
         minR = min(minR,idx);
         maxR = max(maxR,idx);
        if(root->left!=NULL){
            findMinMax(root->left,idx-1,minR,maxR);
        }
        if(root->right!=NULL){
            findMinMax(root->right,idx+1,minR,maxR);
        }
        
    }
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        //Node,index
        queue<pair<Node*,int>> q;
        int minR=INT_MAX,maxR=INT_MIN;
        
        findMinMax(root,0,minR,maxR);
        int range = (maxR -minR)+1;
        vector<vector<int>> storeV(range);
        q.push({root,abs(minR)});
        
        while(!q.empty()){
            int n = q.size();
            for(int i=1;i<=n;i++){
                pair<Node*,int> topNode = q.front();
                q.pop();
    
                storeV[topNode.second].push_back(topNode.first->data);
                if(topNode.first->left!=NULL){
                    q.push({topNode.first->left,topNode.second-1});
                }
                if(topNode.first->right!=NULL){
                    q.push({topNode.first->right,topNode.second+1});
                }
            }
        }
        
        for(int i=0;i<storeV.size();i++){
            int n = storeV[i].size();
            for(int j=0;j<n;j++){
                ans.push_back(storeV[i][j]);
            }
        }
        return ans;
        
      
    }
