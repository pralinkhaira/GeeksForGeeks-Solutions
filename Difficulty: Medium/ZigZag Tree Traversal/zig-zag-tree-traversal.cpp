//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	deque<Node*>q;
    	vector<int>ans;
    	
    	q.push_back(root);
    	int conventional = 1;
    	while(!q.empty()){
    	    if(conventional==1){
    	        int siz = q.size();
    	        for(int i=0;i<siz;i++){
    	            ans.push_back(q.front()->data);
    	            if(q.front()->left){
    	                q.push_back(q.front()->left);
    	            }
    	            if(q.front()->right){
    	                q.push_back(q.front()->right);
    	            }
    	            q.pop_front();
    	        }
    	        conventional = 0;
    	    }
    	    else{
    	        vector<int>x;
    	        int siz = q.size();
    	        for(int i=0;i<siz;i++){
    	            x.push_back(q.front()->data);
    	            if(q.front()->left){
    	                q.push_back(q.front()->left);
    	            }
    	            if(q.front()->right){
    	                q.push_back(q.front()->right);
    	            }
    	            q.pop_front();
    	        }
    	        for(int t = x.size()-1;t>=0;t--){
    	            ans.push_back(x[t]);
    	        }
    	        conventional = 1;
    	    }
    	}
    	
    	return ans;
    }
};
