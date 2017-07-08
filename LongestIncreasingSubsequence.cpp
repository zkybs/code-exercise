#include <vector>
#include <string>
#include <iostream>
using namespace std;
    int longestIncresingSubsequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n<1 || m<1)
            return max(m,n);
        vector<vector<int>> record(n,vector<int>(m,0));
        
        record[0][0]=word1[0]==word2[0];
        for(int i=1;i<m;i++){
            if(word1[0]==word2[i])
                record[0][i]=1;
            else
                record[0][i]=record[0][i-1];
        }
        for(int i=1;i<n;i++){
            record[i][0]=word1[i]==word2[0]?1:record[i-1][0];
            for(int j=1;j<m;j++){
                if(word1[i]==word2[j]){
                    record[i][j]=record[i-1][j-1]+1;
                }else{
                    record[i][j]=max(record[i-1][j],record[i][j-1]);
                }
            }
        }

        return record[n-1][m-1];
    }
int main(int argc, char *argv[]){
    string word1="afasdfa";
    string word2="afasd3opsadf";
    while(true){
        cout<<"please input string 1"<<endl;
        cin>>word1;
        cout<<"please input string 2"<<endl;
        cin>>word2;
        cout<<"longest incresing subsequence is  "<<\
            longestIncresingSubsequence(word1,word2)<<endl;
        cout<<"\n"<<endl;
    }
}