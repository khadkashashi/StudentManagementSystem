#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib> // For exit()

using namespace std;

const string filename = "studentrecord.txt"; // Change the file extension to .txt

struct Student {
    string roll_no;
    string first_name;
    string last_name;
    int age;
    string Class;
    string phone_number;
    string address;
    string admission_year;
    string email;
    string father_name;
    string mother_name;
};

class StudentManagementSystem {
private:
    static const string password;

public:
    static void run() {
        if (login()) {
            displayMainMenu();
        } else {
            cout << "\nLogin Failed. Exiting...\n";
            exit(1);
        }
    }

    static bool login() {
        string enteredPassword;

        cout << "\n||=============================================================================================||";
        cout << "\n||                                                                                             ||";
        cout << "\n||           *************** Student Management System ***************                        ||";
        cout << "\n||                                                                                             ||";
        cout << "\n||=============================================================================================||\n\n";

        cout << "Enter your password: ";
        cin >> enteredPassword;

        if (enteredPassword == password) {
            cout << "Login successful\n";
            clearScreen();
            return true;
        } else {
            cout << "\nWrong Password\n";
            return false;
        }
    }

    static void displayMainMenu() {
        int choice;

        while (true) {
            cout << "\n\n";
            cout << "======================================\n";
            cout << "        Student Management System      \n";
            cout << "======================================\n";
            cout << "  1. Add New Student Record           \n";
            cout << "  2. Display Student Records         \n";
            cout << "  3. Search for a Student Record     \n";
            cout << "  4. Update Student Record           \n";
            cout << "  5. Delete Student Record           \n";
            cout << "  6. Exit                            \n";
            cout << "======================================\n";
            cout << "Please Enter Your Choice: ";

            cin >> choice;

            switch (choice) {
                case 1:
                    clearScreen();
                    addNewStudentRecord();
                    break;

                case 2:
                    clearScreen();
                    displayStudentRecords();
                    break;

                case 3:
                    clearScreen();
                    searchRecord();
                    break;

                case 4:
                    clearScreen();
                    updateRecord();
                    break;

                case 5:
                    clearScreen();
                    deleteRecord();
                    break;

                case 6:
                    clearScreen();
                    cout << "Thank You! Visit Again!\n\n";
                    exitProgram();
                    break;

                default:
                    cout << "\nInvalid choice! Please enter a valid option.\n";
                    break;
            }
        }
    }

    static void addNewStudentRecord() {
        int ch = 0;
        cout << "How many students do you want to enter? ";
        cin >> ch;

        ofstream file(filename.c_str(), ios::app); // Use filename variable
        if (file.is_open()) {
            for (int i = 0; i < ch; ++i) {
                Student student;
                cout << "Enter Roll Number: ";
                cin >> student.roll_no;
                cout << "Enter First Name: ";
                cin >> student.first_name;
                cout << "Enter Last Name: ";
                cin >> student.last_name;
                cout << "Enter Age: ";
                cin >> student.age;
                cout << "Enter Class: ";
                cin >> student.Class;
                cout << "Enter Phone Number: ";
                cin >> student.phone_number;
                cout << "Enter Address: ";
                cin >> student.address;
                cout << "Enter Admission Year: ";
                cin >> student.admission_year;
                cout << "Enter Email: ";
                cin >> student.email;
                cout << "Enter Father's Name: ";
                cin >> student.father_name;
                cout << "Enter Mother's Name: ";
                cin >> student.mother_name;

                file << student.roll_no << "," << student.first_name << "," << student.last_name << "," << student.age << ","
                    << student.Class << "," << student.phone_number << "," << student.address << "," << student.admission_year
                    << "," << student.email << "," << student.father_name << "," << student.mother_name << endl;

                cout << "Record Added Successfully!\n";
            }
            file.close();
        } else {
            cout << "Unable to open file for writing.\n";
        }
    }

    static void displayStudentRecord(const Student& student) {
        cout << "Roll Number: " << student.roll_no << endl;
        cout << "First Name: " << student.first_name << endl;
        cout << "Last Name: " << student.last_name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Class: " << student.Class << endl;
        cout << "Phone Number: " << student.phone_number << endl;
        cout << "Address: " << student.address << endl;
        cout << "Admission Year: " << student.admission_year << endl;
        cout << "Email: " << student.email << endl;
        cout << "Father's Name: " << student.father_name << endl;
        cout << "Mother's Name: " << student.mother_name << endl;
    }

    static void displayStudentRecords() {
        ifstream file(filename.c_str());
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Student student;
                stringstream ss(line);
                getline(ss, student.roll_no, ',');
                getline(ss, student.first_name, ',');
                getline(ss, student.last_name, ',');
                ss >> student.age;
                ss.ignore(); // Ignore the comma
                getline(ss, student.Class, ',');
                getline(ss, student.phone_number, ',');
                getline(ss, student.address, ',');
                getline(ss, student.admission_year, ',');
                getline(ss, student.email, ',');
                getline(ss, student.father_name, ',');
                getline(ss, student.mother_name);

                displayStudentRecord(student);
                cout << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file for reading.\n";
        }
    }

   static void searchRecord() {
    ifstream file(filename.c_str());
    if (file.is_open()) {
        string roll;
        cout << "Enter Roll Number to Search: ";
        cin >> roll;

        string line;
        bool found = false;
        while (getline(file, line)) {
            Student student;
            stringstream ss(line);
            getline(ss, student.roll_no, ',');
            if (student.roll_no == roll) {
                getline(ss, student.first_name, ',');
                getline(ss, student.last_name, ',');
                ss >> student.age;
                ss.ignore(); // Ignore the comma
                getline(ss, student.Class, ',');
                getline(ss, student.phone_number, ',');
                getline(ss, student.address, ',');
                getline(ss, student.admission_year, ',');
                getline(ss, student.email, ',');
                getline(ss, student.father_name, ',');
                getline(ss, student.mother_name);

                displayStudentRecord(student);
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record not found\n";
        }
        file.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }
}

static void updateRecord() {
    string roll_no;
    cout << "Enter Roll Number to Update: ";
    cin >> roll_no;

    ifstream file_in(filename.c_str());
    ofstream file_out("temp.txt"); // Temporary file to store updated records

    if (file_in.is_open() && file_out.is_open()) {
        string line;
        bool found = false;

        while (getline(file_in, line)) {
            stringstream ss(line);
            string token;

            getline(ss, token, ','); // Extracting Roll Number

            if (token == roll_no) {
                found = true;

                Student updatedStudent;
                updatedStudent.roll_no = token;
                getline(ss, updatedStudent.first_name, ',');
                getline(ss, updatedStudent.last_name, ',');
                ss >> updatedStudent.age;
                ss.ignore(); // Ignore the comma
                getline(ss, updatedStudent.Class, ',');
                getline(ss, updatedStudent.phone_number, ',');
                getline(ss, updatedStudent.address, ',');
                getline(ss, updatedStudent.admission_year, ',');
                getline(ss, updatedStudent.email, ',');
                getline(ss, updatedStudent.father_name, ',');
                getline(ss, updatedStudent.mother_name);

                cout << "Current Student Record:" << endl;
                displayStudentRecord(updatedStudent);

                char choice;
                cout << "Do you want to update this record? (y/n): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    cout << "Enter New Student First Name: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, updatedStudent.first_name);

                    cout << "Enter New Student Last Name: ";
                    getline(cin, updatedStudent.last_name);

                    cout << "Enter New Age: ";
                    cin >> updatedStudent.age;

                    cout << "Enter New Class: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, updatedStudent.Class);

                    cout << "Enter New Phone Number: ";
                    getline(cin, updatedStudent.phone_number);

                    cout << "Enter New Address: ";
                    getline(cin, updatedStudent.address);

                    cout << "Enter New Admission Year: ";
                    getline(cin, updatedStudent.admission_year);

                    cout << "Enter New Email: ";
                    getline(cin, updatedStudent.email);

                    cout << "Enter New Father's Name: ";
                    getline(cin, updatedStudent.father_name);

                    cout << "Enter New Mother's Name: ";
                    getline(cin, updatedStudent.mother_name);

                    file_out << updatedStudent.roll_no << "," << updatedStudent.first_name << "," << updatedStudent.last_name << "," << updatedStudent.age << ","
                        << updatedStudent.Class << "," << updatedStudent.phone_number << "," << updatedStudent.address << ","
                        << updatedStudent.admission_year << "," << updatedStudent.email << "," << updatedStudent.father_name << "," << updatedStudent.mother_name << endl;
                    cout << "Record Updated Successfully!\n";
                } else {
                    file_out << line << endl; // Write the unchanged line
                    cout << "Record not updated.\n";
                }
            } else {
                file_out << line << endl; // Write the unchanged line
            }
        }

        file_in.close();
        file_out.close();

        // Remove the old file and rename the temporary file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (!found) {
            cout << "Record not found for Roll Number: " << roll_no << endl;
        }
    } else {
        cout << "Error: Unable to open files for reading/writing.\n";
    }
}


    static void deleteRecord() {
        string roll;
        cout << "Enter Roll Number to Delete: ";
        cin >> roll;

        vector<string> lines;
        ifstream file(filename.c_str());
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file, line)) {
                stringstream ss(line);
                string token;
                getline(ss, token, ','); // Read the first token (roll number)
                if (token != roll) {
                    lines.push_back(line);
                } else {
                    found = true;
                }
            }
            file.close();

            if (found) {
                ofstream outFile(filename.c_str());
                if (outFile.is_open()) {
                    for (size_t i = 0; i < lines.size(); ++i) {
                        outFile << lines[i] << endl;
                    }
                    outFile.close();
                    cout << "Record Deleted Successfully!\n";
                } else {
                    cout << "Unable to open file for writing.\n";
                }
            } else {
                cout << "Record not found for Roll Number: " << roll << endl;
            }
        } else {
            cout << "Unable to open file for reading.\n";
        }
    }

    static void clearScreen() {
        cout << "\033[2J\033[1;1H"; // ANSI Escape Code to clear screen
    }

    static void exitProgram() {
        exit(0);
    }
};

const string StudentManagementSystem::password = "shashi12";

int main() {
    StudentManagementSystem::run();
    return 0;
}

