#include <iostream>
using namespace std;

class studentInfo {
  private:
    string studentName;
    string email;
    int studentID;
    float cGPA;

  public:
    studentInfo* next;

    // Constructor
    studentInfo(string studentName) {
        this->studentName = studentName;
        this->studentID = generateStudentID(); // Placeholder for generating a unique ID
        this->email = getFirstName() + to_string(studentID) + "@organization.edu.eg";
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

    // Getter and Setter for email
    string getEmail() {
        return email;
    }
    void setEmail(string newEmail) {
        email = newEmail;
    }

    // Getter and Setter for studentID
    int getStudentID() {
        return studentID;
    }
    void setStudentID(int id) {
        studentID = id;
    }

    // Getter and Setter for cGPA
    float getCGPA() {
        return cGPA;
    }
    void setCGPA(float gpa) {
        cGPA = gpa;
    }

    // Utility Functions
    string getFirstName() {
        size_t firstSpace = studentName.find(' ');
        return (firstSpace != string::npos) ? studentName.substr(0, firstSpace) : studentName;
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
    cout << "Cumulative GPA: " << current->getCGPA() << "\n";
    cout << "-----------------------------------\n";
}

class Students {
  private:
    studentInfo *head;
    int counter;
    
  public:
    Students() {
        counter = 0;
        head = nullptr;
    }

    //check if empty (done)
    bool isEmpty(){return head == nullptr;}

    //add student (done)
    void add_student(string studentName){
        studentInfo *newStudent;
        newStudent = new studentInfo(studentName);
        counter++;
        if (isEmpty()){
            head = newStudent;
            return;
        }

        studentInfo *current = head;
        for (; current->next != nullptr; current = current->next);
        current->next = newStudent;
    }

    //delete student using id (done)
    void delete_student (int id){
        studentInfo *current = head;
        if (isEmpty()){
            cout<< "No students have been added yet.";
            return;
        }
        if (current->getStudentID() == id){
            head = current->next;
            delete current;
            counter--;
            return;
        }
        for (; current->next != nullptr; current = current->next) {
            if (current->next->getStudentID() == id){
                studentInfo* temp = current->next;
                current->next = current->next->next;
                delete temp;
                counter--;
                return;
            }
        }
        cout<< "No student found with ID: "<< id;
    }
    
    //display all students (done)
    void display_students (){
        if (isEmpty()) {
        cout << "No students have been added yet.";
        return;
        }
        studentInfo* current = head;
        int studentCount = 1;
        while (current != nullptr) {
            shortcut(studentCount ,current);
            studentCount++;
            current = current->next;
        }
    }

    //search by name or id or age (done)
    void search_student(string query) {
        if (isEmpty()) {
            cout << "No students have been added yet.\n";
            return;
        }

        studentInfo* current = head;
        bool found = false;
        int studentCount = 1;

        while (current != nullptr) {
            if (current->getStudentName() == query || to_string(current->getStudentID()) == query) {
                found = true;
                shortcut(studentCount ,current);
                studentCount++;
            }

            current = current->next;
        }
        if (!found) {
            cout << "No students found matching the \"" << query << "\".";
        }
    }
      
    void freeMemory() {
        while (head) {
            studentInfo* temp = head;
            head = head->next;
            delete temp;
        }
    }
};