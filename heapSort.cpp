
#include <iostream>
#include <string>
#include <vector>

using namespace std;
  
// 打印序列
void printPart(vector<int>& list) {
    for (int i = 0; i <list.size(); i++) {
        cout<<list[i]<<' ';
    }
    cout<<endl;
}
void heapAdjust(vector<int>& array,int i, int size){//大顶堆
    int tmp=array[i];
    int child=i*2+1;
    while(child<size){
        if(child+1<size && array[child]>array[child+1]){
            child++;
        }
        if(tmp<=array[child])
            break;
        array[i]=array[child];
        array[child]=tmp;
        i=child;
        child=i*2+1;
    }
}
void heapSort(vector<int> &array){
    int n=array.size();
    for(int i=(n-1)/2;i>=0;i--)
        heapAdjust(array,i,n);
    for(int i=n-1;i>0;i--){
        int tmp=array[0];
        array[0]=array[i];
        array[i]=tmp;
        heapAdjust(array,0,i);
    }
}
void quicksort(vector<int>& array,int left,int right){
    if(left>=right) return;
    int tmp=array[left];
    int cur=left;
    int i=left,j=right;
    while(left<right){
        while(left<right){
            if(array[right]<tmp){
                array[left]=array[right];
                left++;
                break;
            }
            right--;
        }
        while(left<right){
            if(array[left]>tmp){
                array[right]=array[left];
                right--;
                break;
            }
            left++;
        }
    }
    array[left]=tmp;
    quicksort(array,i,left-1);
    quicksort(array,right+1,j);
}
static void merge(int[] unsorted, int first, int mid, int last, int[] sorted)
{
    int i = first, j = mid;
    int k = 0;
    while (i < mid && j < last)
        if (unsorted[i] < unsorted[j])
            sorted[k++] = unsorted[i++];
        else
            sorted[k++] = unsorted[j++];

    while (i < mid)
        sorted[k++] = unsorted[i++];
    while (j < last)
        sorted[k++] = unsorted[j++];

    for (int v = 0; v < k; v++)
        unsorted[first + v] = sorted[v];
}
static void merge_sort(int[] unsorted, int first, int last, int[] sorted)
{
    if (first + 1 < last){
        int mid = (first + last) / 2;
        merge_sort(unsorted, first, mid, sorted);
        merge_sort(unsorted, mid, last, sorted);
        merge(unsorted, first, mid, last, sorted);
    }
}
int main()
{
	vector<int> array = {
                1, 3, 4, 5, 2, 6, 9, 7, 8, 10, 15,22, 17,0
    };
    int n=0;
    while(true){
        while(cin>>n){
            if(n<0) break;
            array.push_back(n);
        }
        quicksort(array,0,array.size()-1);
        printPart(array);
    }
}


