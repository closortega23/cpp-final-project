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

// Function declarations
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