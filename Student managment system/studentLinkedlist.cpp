#include <iostream>
#include "studentInfo.cpp"
#include "helper.cpp"
using namespace std;

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
    void add_student(string studentName, int dateOfBirth, string address, int phoneNumber, string program){
        studentInfo *newStudent;
        newStudent = new studentInfo(studentName, dateOfBirth, address, phoneNumber, program);
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

    //sort students
    void sortStudents(int sortChoice) {
        if (head == nullptr || head->next == nullptr) {
        return;
        }

        bool swapped;
        studentInfo* current = head;

        do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            bool Result;

            if (sortChoice == 1) {
            Result = current->getStudentID() > current->next->getStudentID();
            } else if (sortChoice == 2) {
            Result = current->getStudentName() > current->next->getStudentName();
            } else if (sortChoice == 3) {
            Result = current->getCGPA() > current->next->getCGPA();
            } else {
            cout << "Error: Incorrect sorting choice.\n";
            return;
            }

            if (Result) {
            swap(current->getStudentID(), current->next->getStudentID());
            swap(current->getStudentName(), current->next->getStudentName());
            swap(current->getCGPA(), current->next->getCGPA());
            swapped = true;
            }
            current = current->next;
        }
        } while (swapped);
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
            if (current->getStudentName() == query || 
                to_string(current->getStudentID()) == query || 
                to_string(current->getStudentAge()) == query) {
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
    
    //filter by name (done)
    void filterByName(string filter) {   
        if (isEmpty()) {
            cout << "No students have been added yet.\n";
            return;
        }

        studentInfo* current = head;
        bool found = false;
        int studentCount = 1;

        while (current != nullptr) {
            bool match = false;
            match = (current->getStudentName().find(filter) != string::npos); // Match substring

            if (match) {
                shortcut(studentCount ,current);
                studentCount++;
                found = true;
            }
            current = current->next;
        }
        if (!found){cout << "No students found matching the \"" << filter << "\".";}
    }

    //filter by IDs (done)
    void filterByIDRange(int minID, int maxID) {
        studentInfo* current = head;
        bool found = false;
        int studentCount = 1;

        while (current != nullptr) {
            if (current->getStudentID() >= minID && current->getStudentID() <= maxID) {
                shortcut(studentCount ,current);
                studentCount++;
                found = true;
            }
            current = current->next;
        }
        if (!found){cout << "No students found in ID range \"" << minID << "\":\"" << maxID << "\".";}
    }

    //filter by ages (done)
    void filterByAgeRange(int minAge, int maxAge) {
        studentInfo* current = head;
        bool found = false;
        int studentCount = 1;

        while (current != nullptr) {
            if (current->getStudentAge() >= minAge && current->getStudentAge() <= maxAge) {
                shortcut(studentCount ,current);
                studentCount++;
                found = true;
            }
            current = current->next;
        }
        if (!found){cout << "No students found in age range \"" << minAge << "\":\"" << maxAge << "\".";}
    }

    //filter by GPA (not tried)
    void filterByGPARange(float minGPA, float maxGPA) {
        studentInfo* current = head;
        bool found = false;
        int studentCount = 1;

        while (current != nullptr) {
            if (current->getCGPA() >= minGPA && current->getCGPA() <= maxGPA) {
                shortcut(studentCount ,current);
                studentCount++;
                found = true;
            }
            current = current->next;
        }
        if (!found){cout << "No students found in GPA range \"" << minGPA << "\":\"" << maxGPA << "\".";}
    }
    
    void freeMemory() {
        while (head) {
            studentInfo* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
};