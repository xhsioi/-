/*5.4  归并排序

		a.	归并排序
			void MergeSort(T Data[], int start, int end)
			void Merge(T Data[], int start, int mid, int end)
*/

#include <iostream>
using namespace std;

template <class T>
void merge(T arr[], int l, int mid, int r){
	T help[r-l+1];//辅助数组
	int i = 0;
	int lIndex = l;
	int rIndex = mid+1;
	while(lIndex <= mid && rIndex <= r){
		help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++]:arr[rIndex++];	
	}
    //左边和右边肯定有一边到头了，不可能同时，因为每次只移动一边
	while(lIndex <= mid){
		help[i++] = arr[lIndex++];
	} 
	while(rIndex <= r){
		help[i++] = arr[rIndex++];
	}
    //将排好序的辅助数组赋值给原始数组，不需要返回值
	for(i = 0; i < r-l+1; i++){
		arr[l+i] = help[i];
	}
}
 
//递归
template <class T>
static void mergeSort(T arr[], int l, int r){
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
    //左半部分归并排序
	mergeSort(arr, l, mid);
    //右半部分归并排序
	mergeSort(arr, mid+1, r);
    //左右部分归并
	merge(arr, l, mid, r);
}

int main()
{
    int n, num;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    mergeSort<int>(a, 0, n - 1); //a为待排序的数组，0为数组的第一个位置，n-1为数组的最后一个位置
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;

