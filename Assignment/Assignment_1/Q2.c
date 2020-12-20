
#include<stdio.h>
#include<stdlib.h>

typedef struct _student {

    char stud_name[32];

    int rollno;

    int age;

} student_t;

int main(int argc, char *argv[]){
    
    student_t Arr_student_t[10];

    printf("Create an ArrayList of student_t which total are %ld \n", sizeof(Arr_student_t) / sizeof(student_t));

    return 0;
}