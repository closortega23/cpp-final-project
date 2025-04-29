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
float calculateGPA(const Student &s);
float calculateGPA(const Student &s, bool weighted);
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

void addStudent(Student students[], int &count) {
    if (count >= 100) {
        cout << "Student limit reached.\n";
        return;
    }

    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter student ID: ";
    cin >> s.id;

    cout << "Enter number of grades (max 5): ";
    cin >> s.numGrades;

    for (int i = 0; i < s.numGrades; ++i) {
        float g;
        do {
            cout << "Grade " << (i + 1) << ": ";
            cin >> g;
            if (!isValidGrade(g))
                cout << "Invalid grade. Must be between 0 and 100.\n";
        } while (!isValidGrade(g));
        s.grades[i] = g;
    }

    students[count++] = s;
    cout << "Student added successfully.\n";
}
void viewStudents(const Student students[], int count) {
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < count; ++i) {
        cout << "Name: " << students[i].name << ", ID: " << students[i].id << "\nGrades: ";
        for (int j = 0; j < students[i].numGrades; ++j)
            cout << students[i].grades[j] << " ";
        cout << "\nGPA: " << fixed << setprecision(2) << calculateGPA(students[i]) << "\n\n";
    }
}

void deleteStudent(Student students[], int &count, int id) {
    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; ++j)
                students[j] = students[j + 1];
            count--;
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student ID not found.\n";
}

float calculateGPA(const Student &s) {
    float total = 0;
    for (int i = 0; i < s.numGrades; ++i)
        total += s.grades[i];
    return total / s.numGrades / 25.0;
}

float calculateGPA(const Student &s, bool weighted) {
    if (!weighted)
        return calculateGPA(s);

    float total = 0;
    for (int i = 0; i < s.numGrades; ++i)
        total += (s.grades[i] > 90 ? s.grades[i] + 5 : s.grades[i]);
    return total / s.numGrades / 25.0;
}

void saveToFile(const Student students[], int count) {
    ofstream file("data.txt");
    for (int i = 0; i < count; ++i) {
        file << students[i].name << '\n';
        file << students[i].id << '\n';
        file << students[i].numGrades << '\n';
        for (int j = 0; j < students[i].numGrades; ++j)
            file << students[i].grades[j] << " ";
        file << '\n';
    }
    file.close();
    cout << "Data saved to data.txt\n";
}

void loadFromFile(Student students[], int &count) {
    ifstream file("data.txt");
    if (!file) {
        cout << "No file found.\n";
        return;
    }

    count = 0;
    while (file && count < 100) {
        Student s;
        getline(file, s.name);
        file >> s.id >> s.numGrades;
        for (int i = 0; i < s.numGrades; ++i)
            file >> s.grades[i];
        file.ignore();
        students[count++] = s;
    }

    file.close();
    cout << "Data loaded from file.\n";
}
