class dsu{
    public:

    vector<int>parent,size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }

    int findparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
    }

    void unionbysize(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]++;
        }
        else{
            parent[pv]=pu;
            size[pu]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        dsu dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isconnected[i][j]==1){
                    dsu.unionbysize(i,j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<n;i++){
            if(dsu.findparent(i)==i) provinces++;
        }
        return provinces;
    }
};