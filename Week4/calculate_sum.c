#include <stdio.h>

// Function prototype
int calculate_sum(int n);

int main()
{
    int n;

    // Nhập số nguyên dương từ người dùng
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Gọi hàm để tính tổng từ 1 đến n
    int sum = calculate_sum(n);

    // In ra tổng đã tính được
    printf("Tổng của các số từ 1 đến %d là: %d\n", n, sum);

    return 0;
}

// Hàm tính tổng của các số từ 1 đến n
int calculate_sum(int n)
{
    int sum = 0;

    // Duyệt qua các số từ 1 đến n và cộng dồn vào biến sum
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}
