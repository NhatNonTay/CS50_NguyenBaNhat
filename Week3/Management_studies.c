#include <stdio.h>
#include <string.h>

// Max number of students
#define MAX 100

// Students have name and score
typedef struct
{
    char name[100];
    int score;
} student;

// Array of students
student students[MAX];

// Number of students
int student_count;

// Function prototypes
void add_student(char *name, int score);
void print_top_student(void);

int main(void)
{
    printf("Enter the number of students: ");
    scanf("%d", &student_count);

    if (student_count > MAX)
    {
        printf("Maximum number of students is %d\n", MAX);
        return 1;
    }

    // Populate array of students
    for (int i = 0; i < student_count; i++)
    {
        char name[100];
        int score;
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter score of student %d: ", i + 1);
        scanf("%d", &score);
        add_student(name, score);
    }

    // Display student with highest score
    print_top_student();

    return 0;
}

// Add a new student to the list
void add_student(char *name, int score)
{
    strcpy(students[student_count].name, name);
    students[student_count].score = score;
    student_count++;
}

// Print the student with the highest score
void print_top_student(void)
{
    int max_score = -1;
    char top_student[100];

    // Find the student with the highest score
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].score > max_score)
        {
            max_score = students[i].score;
            strcpy(top_student, students[i].name);
        }
    }

    // Print the top student
    printf("Top student: %s with score %d\n", top_student, max_score);
}
