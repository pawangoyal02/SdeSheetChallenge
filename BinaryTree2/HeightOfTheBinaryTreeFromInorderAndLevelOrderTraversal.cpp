// Solution 1

#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int N){
    queue<vector<int>> q;
   unordered_map<int,int> umap;
   for(int i=0;i<inorder.size();i++)
   {
       umap[inorder[i]]=i;
   }
   int k=0;
   if(umap.find(levelorder[0])!=umap.end())
   {
       if(umap[levelorder[0]]==inorder.size()-1)
           q.push({0,umap[levelorder[0]]-1,1});
       else if(umap[levelorder[0]]==0)
           q.push({1,(int)(inorder.size()-1),1});
       else {
           q.push({0,umap[levelorder[0]]-1,1});
           q.push({umap[levelorder[0]]+1,(int)(inorder.size()-1),1});
       }
   }
   k++;
   int ans=0;
   while(!q.empty())
   {
       vector<int> temp=q.front();
       q.pop();
       ans=max(ans,temp[2]);
       if(umap.find(levelorder[k])!=umap.end())
       {
           if(temp[1]==temp[0])
           {
              ans=max(ans,temp[2]+1);
             
           }
          else if(umap[levelorder[k]]==temp[1])
               q.push({temp[0],umap[levelorder[k]]-1,temp[2]+1});
           else if(umap[levelorder[k]]==temp[0])
               q.push({umap[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           else {
               q.push({temp[0],umap[levelorder[k]]-1,temp[2]+1});
     q.push({umap[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           }
       }
       k++;
   }
   return ans-1;
}

// Solution 2

#include<bits/stdc++.h>
typedef struct Node
{
    int height;
    int left;
    int right;
}
Node;
int heightOfTheTree(vector<int>& inorder, vector<int>& level, int N)
{
   queue<Node> q;
    Node it;
    
    it.height=0;
    it.left=0;
    it.right=N-1;
    
    q.push(it);
    int pos[N+1];
    for(int i=0;i<N;i++)
    {
        pos[inorder[i]]=i;
    }
    
    int mxheight=0;
    
    for(int i=0;i<N;i++)
    {
        int curr=level[i];
        
        Node now=q.front();
        q.pop();
        
        int currPos=pos[curr];
        
        //left child Present
        if(currPos>now.left)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=now.left;
            newNode.right=currPos-1;
            
            q.push(newNode);
        }
        if(currPos<now.right)
        {
            Node newNode;
            
            newNode.height=now.height+1;
            mxheight=max(mxheight,newNode.height);
            newNode.left=currPos+1;
            newNode.right=now.right;
            
            q.push(newNode);
        }
    }
   return mxheight;
}