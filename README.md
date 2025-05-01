# Student GPA Calculator

Overview
The **Student GPA Calculator** is a C++ utility application that allows users to manage student records, input grades, and calculate GPAs. It includes features to add, view, delete, save, and load student data. The GPA calculation supports both standard and weighted grading systems.

Features
- Add new student records (name, ID, up to 5 grades)
- Calculate GPA with two overloaded functions (standard and weighted)
- Display all student records with their GPAs
- Delete a student record by ID
- Save student data to a file (`data.txt`)
- Load student data from a file
- Input validation to ensure data accuracy

How to Compile and Run
1. Open your Codespace terminal.
2. Compile the program using the `g++` compiler:
```bash
g++ main.cpp -o main 
3. Run the executable:
bash
./main