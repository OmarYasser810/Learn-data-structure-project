#include <iostream>
#include <ctime>
using namespace std;

class studentInfo {
  private:
    string studentName;
    int dateOfBirth; // Year of birth
    string address;
    int phoneNumber;
    string email;
    string program;
    int studentID;
    int yearOfStudy;
    int studentAge;
    float cGPA;

  public:
    studentInfo* next;

    // Constructor
    studentInfo(string studentName, int dateOfBirth, string address, int phoneNumber, string program) {
        this->studentName = studentName;
        this->studentID = generateStudentID(); // Placeholder for generating a unique ID
        this->email = getFirstName() + to_string(studentID) + "@ksiu.edu.eg";
        this->program = program;
        this->dateOfBirth = dateOfBirth;
        this->address = address;
        this->phoneNumber = phoneNumber;
        
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        this->yearOfStudy = currentYear;
        this->studentAge = currentYear - this->dateOfBirth;
        this->cGPA = 0.0;
        next = nullptr;
    }

    // Getter and Setter for studentName
    string getStudentName() {
        return studentName;
    }
    void setStudentName(string studentName) {
        studentName = studentName;
    }

    // Getter and Setter for dateOfBirth
    int getDateOfBirth() {
        return dateOfBirth;
    }
    void setDateOfBirth(int dob) {
        dateOfBirth = dob;
        updateStudentAge();
    }

    // Getter and Setter for address
    string getAddress() {
        return address;
    }
    void setAddress(string addr) {
        address = addr;
    }

    // Getter and Setter for phoneNumber
    int getPhoneNumber() {
        return phoneNumber;
    }
    void setPhoneNumber(int phone) {
        phoneNumber = phone;
    }

    // Getter and Setter for email
    string getEmail() {
        return email;
    }
    void setEmail(string newEmail) {
        email = newEmail;
    }

    // Getter and Setter for program
    string getProgram() {
        return program;
    }
    void setProgram(string prog) {
        program = prog;
    }

    // Getter and Setter for studentID
    int getStudentID() {
        return studentID;
    }
    void setStudentID(int id) {
        studentID = id;
    }

    // Getter and Setter for yearOfStudy
    int getYearOfStudy() {
        return yearOfStudy;
    }
    void setYearOfStudy(int year) {
        yearOfStudy = year;
    }

    // Getter and Setter for studentAge
    int getStudentAge() {
        return studentAge;
    }
    void setStudentAge(int age) {
        studentAge = age;
    }

    // Getter and Setter for cGPA
    float getCGPA() {
        return cGPA;
    }
    void setCGPA(float gpa) {
        cGPA = gpa;
    }

    // Getter and Setter for courses
    /*LinkedListMaterial getCourses() {
        return courses;
    }
    void setCourses(LinkedListMaterial courseList) {
        courses = courseList;
    }*/

    // Utility Functions
    string getFirstName() {
        size_t firstSpace = studentName.find(' ');
        return (firstSpace != string::npos) ? studentName.substr(0, firstSpace) : studentName;
    }

    void updateStudentAge() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        studentAge = currentYear - dateOfBirth;
    }

    int generateStudentID() {
        static int idCounter = 1000; // Example starting ID
        return idCounter++;
    }
    
};

void shortcut(int studentCount, studentInfo* current){
    cout << "\nStudent #" << studentCount << ":\n";
    cout << "Name: " << current->getStudentName() << "\n";
    cout << "Student ID: " << current->getStudentID() << "\n";
    cout << "Email: " << current->getEmail() << "\n";
    cout << "Age: " << current->getStudentAge() << "\n";
    cout << "Address: " << current->getAddress() << "\n";
    cout << "Phone Number: " << current->getPhoneNumber() << "\n";
    cout << "Program: " << current->getProgram() << "\n";
    cout << "Year of Study: " << current->getYearOfStudy() << "\n";
    cout << "Cumulative GPA: " << current->getCGPA() << "\n";
    cout << "-----------------------------------\n";
}