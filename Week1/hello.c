#include <stdio.h>

int main(void)
{
    char name[100];

    // Nhập tên từ người dùng
    printf("What is your name? ");
    scanf("%99s", name); // Đọc vào tên, tối đa 99 ký tự để đảm bảo an toàn bộ nhớ

    // In lời chào
    printf("Hello, %s\n", name);

    return 0;
}
