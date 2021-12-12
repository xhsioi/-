/*5.2   ��������

		b.	��������
			void QuickSort(T Data[], int left, int right)
			int Partition1(T Data[], int left, int right)
*/
#include <iostream>
using namespace std;

/*
TODO:ʵ�ֶ�data[left]��data[right]�ķָ�����������ػ��ֺ���Ԫ�ض�Ӧ��λ��,������Ԫ�ص���λ�ã�ʵ�ַ���
*/
template <class T>
int Partition1(T Data[], int left, int right)
{
    T p=Data[left];
    int start=left;
    int end = right; 
    while(right>=left){
    	while(right>=left && Data[left]<=p){
            left++;
        }
        while(right>=left && Data[right]>p) {
            right--;
        }
        if(left<right){
            swap(Data[right],Data[left]);
            left++;
            right--;
        }
    }
    swap(Data[start],Data[right]);
    return right;
}

/*
TODO:�÷��η�ʵ�ֿ��������㷨,�����Data��Ԫ�ذ���������
 */
template <class T>
void QuickSort(T Data[], int left, int right)
{
	if(left>=right){
        return ;
    }
    else if(left<right){
        int p=Partition1(Data,left,right);
        QuickSort(Data,left,p-1);
        QuickSort(Data,p+1,right);
    }
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
    QuickSort<int>(a, 0, n - 1); //aΪ����������飬0Ϊ����ĵ�һ��λ�ã�n-1Ϊ��������һ��λ��
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
