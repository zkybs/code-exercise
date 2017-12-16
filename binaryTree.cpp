#include <vector>
#include<memory>
#include<iostream>
struct node{
    int val;
    node* leftChild=NULL;
    node* rightChild=NULL;
};
class Tree{
public:
    Tree() = default;
    Tree(std::vector<int>& data){
        root = new node;
        root->val=-1;
        for(auto &element:data){
            if(root->val<0){
                root->val=element;
                continue;
            }
            insert(element);
        }
    }
    void insert(int x){
        node* temp=root;
        while(1){
            if(temp->val>x){
                if(temp->leftChild==NULL){
                    temp->leftChild=new node;
                    (temp->leftChild)->val=x;
                    return;
                }else{
                    temp=temp->leftChild;
                    continue;
                }
            }
            if(temp->val<x){
                if(temp->rightChild==NULL){
                    temp->rightChild=new node;
                    (temp->rightChild)->val=x;
                    return;
                }else{
                    temp=temp->rightChild;
                    continue;
                }
            }
            return;
        }
    }
    void preOrder(){
        pre(root);
    }
    void pre(node *temp){
        if(temp!=NULL){
            std::cout<<temp->val<<" ";
            pre(temp->leftChild);
            pre(temp->rightChild);
        }
    }
private:
    node *root;
};
int main(int argc, char*argv[]){
    std::vector<int> data=std::vector<int>{12,1,2,3,4,7,6,5,8,15,14,13,16,17};
    Tree tree(data);
    tree.preOrder();
}