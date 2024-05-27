#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int letter_counts[26] = {0}; // Mảng để đếm số lần xuất hiện của mỗi chữ cái
    char text[1000];             // Khai báo mảng ký tự để lưu trữ chuỗi đầu vào

    // Nhập chuỗi từ người dùng
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng

    // Đếm số lần xuất hiện của mỗi chữ cái
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            char lowercase_char = tolower(text[i]); // Chuyển đổi ký tự thành chữ thường
            letter_counts[lowercase_char - 'a']++;  // Tăng số đếm cho chữ cái tương ứng
        }
    }

    // In ra số lần xuất hiện của mỗi chữ cái
    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++)
    {
        if (letter_counts[i] > 0)
        {
            printf("%c: %d\n", 'a' + i, letter_counts[i]);
        }
    }

    return 0;
}
