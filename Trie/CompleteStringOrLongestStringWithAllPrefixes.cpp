struct Node{
      Node* links[26];
      bool flag;
      bool containKey(char ch){
        return (links[ch-'a']!=NULL);
      }
      
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag =true;
    }
    
};


string completeString(int n, vector<string> &a){
    // Write your code here.
    Node* root= new Node();
    
    for(auto word: a){
        Node* node= root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    string ans="";
    
    for(auto word: a){
        Node* node= root;
        string temp="";
        int boool =0;
        for(int i=0; i<word.size(); i++){
            if(node->containKey(word[i]) ){
                node = node->get(word[i]);
                if(node->flag!= true){
                    boool = 1;
                }
            }
        }
        if(!boool) temp=word;
        
        if(temp.length() > ans.length()){
            ans=temp;
        }else if(temp.length() == ans.length() and temp < ans){
            ans= temp;
        }
    }
    
    
    if(ans=="") return "None";
    return ans;
}