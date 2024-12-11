#include <iostream>
#include <fstream>
#include <string>
uning namespace std; 

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent(const string& filename) {
    Student student;

    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore(); // Ignore trailing newline
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    ofstream outFile('student.txt', ios::app);
    if (outFile) {
        outFile << student.rollNumber << "|" << student.name << "|" << student.division << "|" << student.address << "\n";
        outFile.close();
        cout << "Student added successfully!\n";
    } else {
        cerr << "Error opening file!\n";
    }
}

void displayStudent(const string& filename, int rollNumber) {

    ifstream inFile("student.txt"); // Open the file
    string line;


    if (inFile) { 
     while (getline(inFile, line)) { 
        cout << line << endl; 
         inFile.close(); 
    }
       
    }
    else {
         cerr << "Error opening file!" << endl;
    }

   
}

int main() {
    const string filename = "students.txt";
    int choice;

    do {
        cout << "\nStudent Database Management\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number to display: ";
                cin >> rollNumber;
                displayStudent(filename, rollNumber);
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
