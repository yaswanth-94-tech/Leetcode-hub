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
    int makeConnected(int n, vector<vector<int>>& edges) {
        dsu ds(n);
        int extra=0;
        for(auto it:edges){
            int first=it[0];
            int second=it[1];
            if(ds.findparent(first)==ds.findparent(second)) extra++;
            else{
                ds.unionbysize(first,second);

            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i) components++;
        }
        int ans=components-1;
        if(extra>=ans) return ans;
        else return -1;
    }
};