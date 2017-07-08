
#include <iostream>
#include <string>
#include <vector>

using namespace std;

  
class HeapSort {
public:
	void HeapAdjust(vector<int> &array, int parent, int length) {
	int temp = array[parent]; // temp保存当前父节点
	int child = 2 * parent + 1; // 先获得左孩子
  
	while (child < length) {
		// 如果有右孩子结点，并且右孩子结点的值大于左孩子结点，则选取右孩子结点
		if (child + 1 < length && array[child] < array[child + 1]) {
			 child++;
		}
		// 如果父结点的值已经大于孩子结点的值，则直接结束
		if (temp >= array[child])
			break;
  
		// 把孩子结点的值赋给父结点
		array[parent] = array[child];
  
		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * child + 1;
        }
  
        array[parent] = temp;
    }
    void heapSort(vector<int> &list) {
		// 循环建立初始堆
		for (int i = list.size() / 2; i >= 0; i--) {
             HeapAdjust(list, i, list.size() - 1);
        }
  
        // 进行n-1次循环，完成排序
        for (int i = list.size() - 1; i > 0; i--) {
             // 最后一个元素和第一元素进行交换
             int temp = list[i];
             list[i] = list[0];
             list[0] = temp;
  
             // 筛选 R[0] 结点，得到i-1个结点的堆
             HeapAdjust(list, 0, i);
        }
    }
  
    // 打印序列
    void printPart(vector<int>& list) {
         for (int i = 0; i <list.size(); i++) {
             cout<<list[i]<<' ';
         }
		 cout<<endl;
     }
};
int main()
{
	vector<int> array = {
                1, 3, 4, 5, 2, 6, 9, 7, 8, 0,10,15,17,22
        };

	// 调用快速排序方法
	HeapSort heap;
	heap.heapSort(array);
	heap.printPart(array);
}


