class DisJointSet
{

	vector<int> rank, parent, size; 
public:
	DisJointSet(int n){
		rank.resize(n+1, 0); 
		parent.resize(n+1); 
		size.resize(n+1); 

		for(int i = 0; i<n; i++){
			parent[i] = i; 
			size[i] = 1; 
		}
	}


	int findUPar(int node){
		if(parent[node] == node){
			return node; 
		}

		return parent[node] = findUPar(parent[node]); 
	}

	void unionByRank(int u, int v){
		int pu = findUPar(u); 
		int pv = findUPar(v);

		if(pu == pv) return ; 

		if(rank[pu] < rank[pv]){
			parent[pu] = pv; 
		} 
		else if(rank[pv] < rank[pu]){
			parent[pv] = pu; 
		}
		else{
			parent[pv] = pu; 
			rank[pu]++; 
		}
	}

	void unionBySize(int u, int v){
		int pu = findUPar(u); 
		int pv = findUPar(v);

		if(pu == pv) return ; 

		if(size[pu] < size[pv]){
			parent[pu] = pv; 
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu; 
			size[pu] += size[pv];
		}
	}
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n); 
        int cntExtra(0); 

        for(auto it : connections){
            int u = it[0]; 
            int v = it[1]; 

            if(ds.findUPar(u) == ds.findUPar(v)) cntExtra++; 
            else ds.unionBySize(u, v); 
        }

        int cntC(0); 

        for(int i = 0; i<n; i++){
            if(ds.findUPar(i) == i) cntC++; 
        }

        int ans = cntC - 1; 

        if(cntExtra >= ans) return ans; 
        return -1; 

    }
};
