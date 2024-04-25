#include "Class_Environment.h"

void Student::view_marks() { cout << "   Your marks : " << marks << '\n'; }
void Student::update(int marks) { this->marks = marks; }

void Teacher::change_marks(Student &S) // Changing marks ... Can access private functions of Student
{
    cout << "   Enter marks : ";
    int marks;
    cin >> marks;
    S.update(marks);
}
void Teacher::view_marks() // Viewing marks
{
    for (int i = 0; i < CLASS_SIZE; i++)
        cout << '(' << i + 1 << ',' << classroom[i]->marks << ')' << ' ';
    cout << '\n';
}
void Teacher::get_roll() // For getting roll number of the students whose marks are to be updated
{
    cout << "   Enter roll number : ";
    int roll;
    cin >> roll;
    if (roll > 0 && roll <= CLASS_SIZE)
        change_marks(*classroom[roll - 1]);
    else
        cout << "   INVALID_ROLL\n";
}

void student_queries() // Queries for student
{
    int roll;
    cout << "   Enter your roll : ";
    cin >> roll;
    if (roll <= CLASS_SIZE && roll > 0)
    {
        classroom[roll - 1]->view_marks();
    }
    else
    {
        cout << "   INVALID ROLL NUMBER\n";
    }
}

void teacher_queries() // Queries for teacher
{
    cout << "   1. View Marks\n";
    cout << "   2. Change Marks\n";
    cout << "   ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        Teacher T;
        T.view_marks();
    }
    else if (choice == 2)
    {
        int roll;
        if (roll <= CLASS_SIZE && roll > 0)
        {
            Teacher T;
            T.get_roll();
        }
        else
        {
            cout << "   INVALID ROLL NUMBER\n";
        }
    }
    else
        cout << "   INVALID CHOICE\n";
}
int main()
{
    for (int i = 0; i < CLASS_SIZE; i++)
    {
        Student *S = (Student *)malloc(sizeof(Student)); // Dynamically allocating Student structs
        S->roll = i + 1;
        classroom.push_back(S);
    }
    while (true)
    {
        cout << "---------------\n";
        cout << "1. Student\n";
        cout << "2. Teacher\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1)
            student_queries();
        else if (choice == 2)
            teacher_queries();
        else if (choice == 3)
            break;
        else
            cout << "INVALID CHOICE\n";
    }
    for (int i = 0; i < CLASS_SIZE; i++) // Freeing dynamically allocated Student objects
        free(classroom[i]);
    classroom.clear();
}
