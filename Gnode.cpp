#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int nodeNumber;
    int data;
    string nodeId;
    node* refnodeId;
    vector<node*> childRef;
    node* gennodeId;
    node(int nnum,int d,node* ref,node* gen){
        nodeNumber = nnum;
        data = d;
        nodeId = to_string(nodeNumber);
        refnodeId = ref;
        gennodeId = gen;
    }
    int getSumChild(){
        int val = 0;
        for(auto i = childRef.begin();i!=childRef.end();i++){
            val += (*i)->data;
        }
        return val;
    }
};

bool addnode(int data,node* p,int nnum,node* gen){
    node* r;
    if(data + p->getSumChild() < p->data){
        r = new node(nnum,data,p,gen);
        p->childRef.push_back(r);
        return true;
    }
    for(auto i = p->childRef.begin();i!=p->childRef.end();i++){
        bool flag = addnode(data,*i,nnum,gen);
        if(flag){
            return true;
        }
    }
    return false;
}

int main(){
    int nnum = 0;
    int data;
    cin>>data;
    node genesisnode(++nnum,data,NULL,NULL);
    while(true){
        cin>>data;
        addnode(data,&genesisnode,++nnum,&genesisnode);
    }
    return 0;
}