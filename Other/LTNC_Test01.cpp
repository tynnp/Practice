#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Cấp phát động cho mảng A và mảng B
    int *A = (int *)malloc(m * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));

    // Nhập dãy A
    for (int i = 0; i < m; i++) {
        scanf("%d", &A[i]);
    }

    // Nhập dãy B
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    // Đếm số lượng phần tử của B không có mặt trong A
    int count = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            count++;
        }
    }

    // In ra kết quả
    printf("%d\n", count);

    // Giải phóng bộ nhớ
    free(A);
    free(B);

    return 0;
}
