#include <iostream>
#include <string>

using namespace std;

// Define the structure Student
struct Student {
    string name;
    int rollNumber;
    float marks[3];
};

int main() {
    // Dynamically allocate memory for a Student structure
    Student* student = new Student;

    // Input the student's details
    cout << "Enter the student's name: ";
    cin >> student->name;

    cout << "Enter the roll number: ";
    cin >> student->rollNumber;

    cout << "Enter marks in 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> student->marks[i];
    }

    // Calculate the average of the three marks
    float average = 0.0f;
    for (int i = 0; i < 3; i++) {
        average += student->marks[i];
    }
    average /= 3.0f;

    // Print the student's details along with their average marks
    cout << "\nStudent Details:\n";
    cout << "Name: " << student->name << endl;
    cout << "Roll Number: " << student->rollNumber << endl;
    cout << "Marks: " << student->marks[0] << ", " << student->marks[1] << ", " << student->marks[2] << endl;
    cout << "Average Marks: " << average << endl;

    // Free the allocated memory
    delete student;

    return 0;
}
