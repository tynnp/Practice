// Sắp xếp nổi bọt
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    return;
}

// Sắp xếp chèn
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) 
            swap(arr[j-1], arr[j]), j--;
    }
    return;
}