#include <stdio.h>

int main() {
    int n, res = 0; 
    scanf("%d", &n);

    for (int i = 2; i < n/2; i++)
        res += (n % i == 0 ? n/i + i : 0);

    if (n == res + 1) printf("Yes");
    else printf("No");
    return 0;
}