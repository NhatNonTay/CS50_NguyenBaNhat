// #include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
bool is_prime(long long number)
{
    if (number <= 1)
    {
        return false;
    }
    for (long long i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    long long number;

    // Nhập số từ người dùng
    do
    {
        printf("Vui lòng nhập một số nguyên dương: ");
        scanf("%lld", &number);
    } while (number <= 0);

    // Kiểm tra xem số có phải là số nguyên tố hay không
    if (is_prime(number))
    {
        printf("%lld là số nguyên tố\n", number);
    }
    else
    {
        printf("%lld không phải là số nguyên tố\n", number);
    }

    // Phân loại số
    if (number % 2 == 0)
    {
        printf("%lld là số chẵn\n", number);
    }
    else
    {
        printf("%lld là số lẻ\n", number);
    }

    return 0;
}