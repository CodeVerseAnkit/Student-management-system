#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/* Coder: Ankit
   Date: 29/8/2025
   Project: Student management                   system version 2.0
   Description: It is a student management tool made by using file handling
*/
// ---> Student class
class student
{
  public:
    // variables to store user data
    int rollno;
    string name;
    string course;
    double fees;
    long long mobileno;
    // function to get into user data
    void getdata()
    {
        cout << "  Enter Roll No. : ";
        cin >> rollno;
        cin.ignore();
        cout << "  Enter Name: ";
        getline(cin, name);
        cout << "  Enter Course name: ";
        getline(cin, course);
        cout << "  Enter fees: ";
        cin >> fees;
        cout << "  Enter contact no. : ";
        cin >> mobileno;
    }
    // function to print data
    void printdata()
    {
        cout << "  Roll no. : " << rollno << endl;
        cout << "  Name: " << name << endl;
        cout << "  Course name: " << course << endl;
        cout << "  Fees: " << fees << endl;
        cout << "  Contact no. : " << mobileno << endl;
    }
};

// ---> Back Button
void back_button()
{
    char ch;
    do
    {
        cout << "  Do you want to back(y/n): ";
        cin >> ch;
    } while (tolower(ch) != 'y');
}

// ---> Welcome message
void welcome_message()
{
    cout << "   🙏WELCOME TO STUDENT MANAGEMENT SYSTEM🙏\n   ••••••••••••••••••••••••••••••••••••••••\n"
         << endl;
}

// ---> csv line split
// this function split value separated by comma
vector<string> separateline(string line, char ch)
{
    vector<string> str;
    string templine;
    stringstream ss(line);
    while (getline(ss, templine, ch))
    {
        str.push_back(templine);
    }
    return str; // return line
}

// ---> UI
void menu()
{
    cout << "\n  -------- STUDENT MANAGEMENT SYSTEM --------\n           ➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
         << endl;
    welcome_message();
    cout << "   1. Add Student           2. View Student\n   3. Search Student        4. Edit student\n   5. Delete Student        6. About\n   7. Exit\n"
         << endl;
    cout << " _—_—_—_—_—_—_—_—_—_—_ * _—_—_—_—_—_—_—_—_—_—_\n"
         << endl;
}

// ---> 1. Add Students
void add_students()
{
    welcome_message(); // welcome message
    cout << "  To add students, enter the required \n  students details:-\n"
         << endl;
    char user;
    do
    {
        student s;
        ofstream write;
        write.open("/sdcard/Coding.cpp/PROJECT/student_management_system/studentdata.txt", ios::app); // file open (storage path)
        s.getdata();
        // writhing user data in file
        write << s.rollno << "|" << s.name << "|" << s.course << "|" << s.fees << "|" << s.mobileno << endl;
        // processing message
        cout << "\n   Saving... \n   Saving... \n   Saving... \n\n   student saved successfully.👍\n"
             << endl;
        write.close(); // file close
        do
        {
            // this loop avoid wrong input
            cout << "  Do you add more students (y/n): ";
            cin >> user;
        } while (tolower(user) != 'y' && tolower(user) != 'n');
    } while (tolower(user) != 'n');
    back_button(); // back button
}

// ---> 2. View Student
void view_students()
{
    welcome_message(); // welcome message
    cout << "   STUDENT DETAILS:-\n   ---------------\n"
         << endl;
    ifstream read("/sdcard/Coding.cpp/PROJECT/student_management_system/studentdata.txt"); // file open (storage path)
    if (read.peek() != ifstream::traits_type::eof())
    {
        cout << "  Roll no|Name|Course|Fees|Mobile no \n  ------- ---- ------ ---- ---------\n"
             << endl;
        string line;
        // print data on screen
        while (getline(read, line))
        {
            cout << "  " << line << endl;
        }
        cout << endl;
    }
    else
    { // if file is empty
        cout << "   Sorry😭 There is no data stored in file!! \n"
             << endl;
    }
    back_button(); // back button
}

// ---> 3. Search Student
void search_students()
{
    welcome_message(); // welcome message
    cout << "   Search Student's Details:-\n   —————————————————————————\n"
         << endl;
    char user;
    do
    {
        int rollno;
        string line;

        ifstream read("/sdcard/Coding.cpp/PROJECT/student_management_system/studentdata.txt"); // file open (storage path)
        bool found = false;
        cout << "  Enter Roll No. : ";
        cin >> rollno;
        cout << "\n  Searching🔍...\n  Searching🔍...\n  Searching🔍...\n"
             << endl;
        while (getline(read, line))
        {
            vector<string> templine = separateline(line, '|');
            if (stoi(templine[0]) == rollno)
            {
                // student found
                cout << "  Student founded" << endl;
                cout << "\n  rollno|name|course|fees|mobileno " << endl;
                cout << "  " << line << endl;
                found = true;
                break;
            }
        }
        if (!found)
        { // if student not found
            cout << "  Student not found" << endl;
        }
        read.close(); // close file

        do
        { // this loop ignore wrong input
            cout << "\n   Do you want to search more (y/n) : ";
            cin >> user;
        } while (tolower(user) != 'y' && tolower(user) != 'n');

    } while (tolower(user) != 'n');
    back_button(); // back button
}

// ---> 4. Edit Student
void edit_students()
{
    welcome_message();
    cout << "   Here you can edit students Details:-\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << endl;
    char user;
    do
    {
        student s;
        int rollno;
        string line;
        bool update = false;
        ifstream read("/sdcard/Coding.cpp/PROJECT/student_management_system/studentdata.txt"); // open file (storage path)
        ofstream write("/sdcard/Coding.cpp/PROJECT/student_management_system/tempdata.txt");   // open duplicate file (storage path)
        cout << "  Enter Roll No. : ";
        cin >> rollno;
        // processing message
        cout << "  Search🔍... \n  Searching🔍... \n  Searching🔍... " << endl;
        while (getline(read, line))
        {
            vector<string> templine = separateline(line, '|');
            if (stoi(templine[0]) == rollno)
            {
                // new details
                update = true;
                cout << "  Roll no founded😊\n"
                     << endl;
                cout << "  Enter new details:-" << endl;
                s.getdata();

                write << s.rollno << "|" << s.name << "|" << s.course << "|" << s.fees << "|" << s.mobileno << endl;
                // processing message
                cout << "  \n saving new details... \n  Saving new details... \n  New details saved successfully👍\n"
                     << endl;
                // remaining data copy then exit whole loop
                while (getline(read, line))
                {
                    write << line << endl;
                }
                break;
            }
            else
            { // old details
                write << line << endl;
            }
        }
        read.close();                              // close file
        write.close();                             // close file
        remove("studentdata.txt");                 // remove original file
        rename("tempdata.txt", "studentdata.txt"); // rename duplicate file
        if (!update)
        { // if roll no not found
            cout << "\n  Sorry 😭 Roll no not found" << endl;
        }
        do
        { // ignore wrong input
            cout << "\n  Do you want to edit more students(y/n): ";
            cin >> user;
        } while (tolower(user) != 'n' && tolower(user) != 'y');

    } while (tolower(user) != 'n');
    back_button();
}

// ---> 5. Delete student

void delete_students()
{
    welcome_message();
    cout << "   Here you can delete students :-\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << endl;
    char user;
    do
    {
        int rollno;
        string line;
        bool deleted = false;
        ifstream read("/sdcard/Coding.cpp/PROJECT/student_management_system/studentdata.txt"); // open file (storage path)
        ofstream write("/sdcard/Coding.cpp/PROJECT/student_management_system/tempdata.txt");   // open duplicate file (storage path)
        cout << "  Enter Roll No. : ";
        cin >> rollno;
        // processing message
        cout << "  Search🔍... \n  Searching🔍... \n  Searching🔍... " << endl;
        while (getline(read, line))
        {
            vector<string> templine = separateline(line, '|');
            if (stoi(templine[0]) == rollno)
            {
                // processing message
                cout << "\n  Deleting... \n  Deleting... \n  Deleting... \n   Deleted successfully \n"
                     << endl;
                deleted = true;
                continue; // skip this line
            }

            // old details
            write << line << endl;
        }
        read.close();                              // close file
        write.close();                             // close file
        remove("studentdata.txt");                 // remove original file
        rename("tempdata.txt", "studentdata.txt"); // rename duplicate file
        if (!deleted)
        { // if roll no not found
            cout << "\n  Sorry 😭 Roll no not found" << endl;
        }
        do
        { // ignore wrong input
            cout << "\n  Do you want to delete more students(y/n): ";
            cin >> user;
        } while (tolower(user) != 'n' && tolower(user) != 'y');

    } while (tolower(user) != 'n');
    back_button();
}

// ---> 6. About
void about()
{
    // about this project
    cout << "  -------- STUDENT MANAGEMENT SYSTEM --------\n           ➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
         << endl;
    welcome_message();
    cout << "     About this project:-\n     ^^^^^^^^^^^^^^^^^^^\n"
         << endl;
    cout << "   Coder: Ankit\n   Date: 29/8/2025\n   Project: Student management system\n   version: 2.0 \n   Description: It is a student management\n            tool made by using file handling.\n   Features: add student,delete student,\n            view all student,search student,\n            edit student details.\n"
         << endl;
    cout << "     ❤THANKS FOR USING THIS TOOL❤\n"
         << endl;

    cout << " _—_—_—_—_—_—_—_—_—_—_ * _—_—_—_—_—_—_—_—_—_—_\n"
         << endl;
    back_button();
}

// ---> Main function
int main()
{
    int input;
    do
    {
        menu();
        do
        { // ignore wrong input
            cout << "   INPUT: ";
            cin >> input;
            cout << endl;
        } while (input <= 0 || input >= 8);
        switch (input)
        {
        case 1:
            add_students();
            break;
        case 2:
            view_students();
            break;
        case 3:
            search_students();
            break;
        case 4:
            edit_students();
            break;
        case 5:
            delete_students();
            break;
        case 6:
            about();
            break;
        case 7:
            cout << "  Thanks for visit😘\n"
                 << endl;
            cout << "  Exiting... \n"
                 << endl;
            break;
        default:
            cout << "  Please enter valid input" << endl;
        }
    } while (input != 7);
    return 0;
}