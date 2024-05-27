#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Điểm được gán cho mỗi chữ cái trong bảng chữ cái theo trò chơi Scrabble
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    char word1[100];
    char word2[100];

    // Nhập từ của người chơi 1
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng

    // Nhập từ của người chơi 2
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng

    // Tính điểm của cả hai từ
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // In ra người chiến thắng
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }

    return 0;
}

int compute_score(char *word)
{
    int score = 0;

    // Tính và trả về điểm cho chuỗi
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            int index = tolower(word[i]) - 'a'; // Chuyển ký tự thành chữ thường và lấy chỉ số
            score += POINTS[index];             // Thêm điểm tương ứng
        }
    }

    return score;
}
