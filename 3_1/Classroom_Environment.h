#include <iostream>
#include <vector>
using namespace std;
#define CLASS_SIZE 10
class Student
{
public:
    int roll;
    friend class Teacher; // Teacher can access update function
    void view_marks();

private:
    int marks;
    void update(int marks);
};

vector<Student *> classroom; // Stores all Student* pointers

class Teacher
{
public:
    void change_marks(Student &S);
    void view_marks();
    void get_roll();
};

void student_queries();
void teacher_queries();
