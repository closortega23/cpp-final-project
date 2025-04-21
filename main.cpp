#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    float grades[5];
    int numGrades;
};

void introScreen();
void displayMenu();
void addStudent(Student students[], int &count);
void viewStudents(const Student students[], int count);
void deleteStudent(Student students[], int &count, int id);
float calculateGPA(const Student &s); // Overloaded function 1
float calculateGPA(const Student &s, bool weighted); // Overloaded function 2
void saveToFile(const Student students[], int count);
void loadFromFile(Student students[], int &count);
bool isValidGrade(float g);

void introScreen() {
    cout << "===========================\n";
    cout << "📘 Student GPA Calculator 📘\n";
    cout << "===========================\n\n";
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Delete Student\n";
    cout << "4. Save to File\n";
    cout << "5. Load from File\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

bool isValidGrade(float g) {
    return g >= 0 && g <= 100;
}
