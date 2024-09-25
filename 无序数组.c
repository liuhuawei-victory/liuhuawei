#include <stdio.h>  
  
// 交换数组中的两个元素  
void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
// 快速排序的分区函数  
int partition(int arr[], int low, int high) {  
    int pivot = arr[high];    // 选择最后一个元素作为基准  
    int i = (low - 1);        // 较小元素的索引  
  
    for (int j = low; j <= high- 1; j++) {  
        // 如果当前元素小于或等于pivot  
        if (arr[j] <= pivot) {  
            i++;    // 增加较小元素的索引  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
// 快速排序的主函数  
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        // pi 是分区后基准的索引  
        int pi = partition(arr, low, high);  
  
        // 分别对基准的左右两侧进行快速排序  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
// 用于打印数组的函数  
void printArray(int arr[], int size) {  
    int i;  
    for (i=0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
// 测试快速排序  
int main() {  
    int arr[] = {58, 17, 35, 29, 11, 5};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    quickSort(arr, 0, n-1);  
    printf("Sorted array: \n");  
    printArray(arr, n);  
    return 0;  
}