class Compare
{
  public:
  bool operator()(pair<int,string> a, pair<int,string>b){
            return a.first>b.first;
  }
};
class Solution
{
public:
 void helper(map<char,string>&mp,string str,string ch){
        for(char c:str){
            mp[c]=ch+mp[c];
        }
        return;
 }
    
vector<string> huffmanCodes(string S,vector<int> f,int N)
{
    vector<string>result;
    if(N==0)return result;
    //To store huffman code per character
    map<char,string>mp;
    //Custom comparator for priority queue
    priority_queue<pair<int,string>,
                    vector<pair<int,string>>,
                    Compare>pq;
    for(int i=0;i<N;i++){
        pq.push({f[i],string(1,S[i])});
        mp[S[i]]="";
    }
 
    while(pq.size()!=1){
        pair<int,string>p1=pq.top();
        pq.pop();
        pair<int,string>p2=pq.top();
        pq.pop();
        pq.push({p1.first+p2.first,p1.second+p2.second});
        helper(mp,p1.second,"0");
        helper(mp,p2.second,"1");
        
    }
    for(char c:pq.top().second){
        result.push_back(mp[c]);
    }
    return result;
}
};