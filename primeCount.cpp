#include <iostream>
#include <cstring>
#include <time.h>
#include <math.h>
//give n (2<n<100000)
//calcute all prime factor from 2 to n
//给定输入n
//计算从2到n所有数字的质数因子个数和，质数因子可以重复
class primeCount{
public:
    primeCount(int in){pfCount=new int[in+1];n=in;}
    ~primeCount(){delete pfCount;}
    void count();
private:
    int *pfCount;
    int n;
};
void primeCount::count(){
    int count=0;
    for(int i=2;i<=n;i++){
        pfCount[i]=1;
        int max=sqrt(i)+1;
        for(int j=2;j<max;j++){
            if(!(i%j)){
                pfCount[i]=pfCount[j]+pfCount[i/j];
                break;
            }
        }
        count += pfCount[i];
    }
    std::cout<<count<<std::endl;
}
int main(int argc, char *argv[]){
    clock_t start,finish;
    double totaltime;

    while(true){
        int num;
        std::cout<<"please input num.."<<std::endl;
        std::cin>>num;

        start=clock();

        primeCount pc(num);
        pc.count();
        
        finish=clock();
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
        std::cout<<"\nusing time "<<totaltime<<"s!"<<std::endl;
    }
}