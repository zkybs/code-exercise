#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/********************
 [ ]+[ ]-[9]=4
  +   -   -
 [ ]-[ ]*[ ]=4
  /   *   -
 [ ]+[ ]-[ ]=4
  ||  ||  ||
  4   4   4
*********************/
class nineGrid{
public:
    void match(){
        int vis[9]={0,0,0,0,0,0,0,0,1};
        int grid[9]={0};
        if(find(vis,result,0)){
            cout<<"sucess"<<endl;
            for(int i=0;i<9;i=i+3) {
                cout<<result[i]<<" "<<result[i+1]<< " "<<result[i+2]<<endl;
            }
        }
    }
    bool find(int*vis,int *grid,int size){
        switch(size){
            case 2: grid[2]=9;//fixed
                    size++;
            case 6:if(!check(size,grid)) return false;
                    break;
            case 9:if(!check(size,grid)) return false;
                    memcpy(result,grid,sizeof(int)*9);
                    return true;
        }
        for(int i=1;i<10;i++){
            if(vis[i-1])
                continue;
            int ngrid[9];
            int nvis[8];
            memcpy(ngrid,grid,sizeof(int)*9);
            memcpy(nvis,vis,sizeof(int)*8);
            nvis[i-1]=1;
            ngrid[size]=i;
            if(find(nvis,ngrid,size+1))
                return true;
        }
        return false;
    }
    bool check(int size,int *grid){
        switch(size/3){
            case 1: return (grid[0]+grid[1]-grid[2])==4;
            case 2: return ((grid[3]-grid[4])*grid[5])==4;
            case 3: return (grid[6]+grid[7]-grid[8])==4 &&\
                            ((grid[0]+grid[3])/grid[6])==4 &&\
                            ((grid[1]-grid[4])*grid[7])==4 &&\
                            (grid[2]-grid[5]-grid[8])==4;
        }
    }
private:
    int result[9];
};

int main(int arg, char *argv[]){
    nineGrid g;
    g.match();
}
