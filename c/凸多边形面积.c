#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int x[15], y[15];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    // 应用鞋带公式计算面积
    double area = 0.0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;  // 下一个顶点的索引，循环处理
        area += (x[i] * y[j] - x[j] * y[i]);
    }
    area = area / 2.0;
    if (area < 0) {
        area = -area;  
    }
    printf("%.2f\n", area);
    return 0;
}