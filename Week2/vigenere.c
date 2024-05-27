#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void vigenere_cipher(char *plaintext, char *key);

int main(int argc, char *argv[])
{
    if (argc != 2) // Kiểm tra nếu số lượng tham số dòng lệnh không bằng 2
    {
        printf("Usage: ./vigenere key\n"); // In ra "Usage: ./vigenere key" nếu không bằng 2
        return 1;
    }

    int key_length = strlen(argv[1]); // Lấy độ dài của chuỗi trong tham số dòng lệnh

    // Kiểm tra xem key có chỉ chứa các chữ cái không
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(argv[1][i])) // Nếu ký tự trong argv[1] không phải chữ cái
        {
            printf("Usage: ./vigenere key\n"); // In ra thông báo này
            return 1;
        }
    }

    char plaintext[256];
    printf("plaintext: "); // Lấy plaintext từ người dùng
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng

    printf("ciphertext: ");              // In ra văn bản mã hóa
    vigenere_cipher(plaintext, argv[1]); // Gọi hàm mã hóa Vigenère

    printf("\n"); // In ra dòng mới
    return 0;
}

void vigenere_cipher(char *plaintext, char *key)
{
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < plaintext_length; i++)
    {
        char c = plaintext[i];
        char k = tolower(key[key_index % key_length]) - 'a'; // Tính toán giá trị của khóa

        if (isupper(c)) // Nếu ký tự là chữ in hoa
        {
            printf("%c", ((c - 'A' + k) % 26) + 'A');
            key_index++;
        }
        else if (islower(c)) // Nếu ký tự là chữ thường
        {
            printf("%c", ((c - 'a' + k) % 26) + 'a');
            key_index++;
        }
        else // Nếu không phải là chữ cái, in ra ký tự đó
        {
            printf("%c", c);
        }
    }
}
