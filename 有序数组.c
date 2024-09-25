#include <stdio.h>

// 函数用于插入元素并保持数组有序
void insertAndSort(int arr[], int *size, int value) {
    int i = *size - 1;
    // 如果数组不是空的，并且新值小于最后一个元素
    if (*size > 0 && value < arr[i]) {
        // 找到新值应该插入的位置
        while (i >= 0 && arr[i] > value) {
            arr[i + 1] = arr[i]; // 将大于新值的元素后移
            i--;
        }
    }
    arr[i + 1] = value; // 插入新值
    (*size)++; // 更新数组大小
}

int main() {
    int arr[100] = {2, 4, 6, 8, 10}; // 初始化有序数组
    int size = 5; // 数组当前大小

    // 插入新元素并保持有序
    insertAndSort(arr, &size, 5); // 5应该插入在4和6之间
    insertAndSort(arr, &size, 3); // 3应该插入在2和4之间

    // 打印排序后的数组
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}