/*5.4  �鲢����

		a.	�鲢����
			void MergeSort(T Data[], int start, int end)
			void Merge(T Data[], int start, int mid, int end)
*/

#include <iostream>
using namespace std;

template <class T>
void merge(T arr[], int l, int mid, int r){
	T help[r-l+1];//��������
	int i = 0;
	int lIndex = l;
	int rIndex = mid+1;
	while(lIndex <= mid && rIndex <= r){
		help[i++] = arr[lIndex] < arr[rIndex] ? arr[lIndex++]:arr[rIndex++];	
	}
    //��ߺ��ұ߿϶���һ�ߵ�ͷ�ˣ�������ͬʱ����Ϊÿ��ֻ�ƶ�һ��
	while(lIndex <= mid){
		help[i++] = arr[lIndex++];
	} 
	while(rIndex <= r){
		help[i++] = arr[rIndex++];
	}
    //���ź���ĸ������鸳ֵ��ԭʼ���飬����Ҫ����ֵ
	for(i = 0; i < r-l+1; i++){
		arr[l+i] = help[i];
	}
}
 
//�ݹ�
template <class T>
static void mergeSort(T arr[], int l, int r){
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
    //��벿�ֹ鲢����
	mergeSort(arr, l, mid);
    //�Ұ벿�ֹ鲢����
	mergeSort(arr, mid+1, r);
    //���Ҳ��ֹ鲢
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
    mergeSort<int>(a, 0, n - 1); //aΪ����������飬0Ϊ����ĵ�һ��λ�ã�n-1Ϊ��������һ��λ��
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;

