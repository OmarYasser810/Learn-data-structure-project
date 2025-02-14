#include <iostream>
using namespace std;

class prerequisitesInfo{
  private:
    string courseCode;

  public:
    prerequisitesInfo *next;

    prerequisitesInfo (string courseCode){
        this->courseCode = courseCode;
        next = nullptr;
    }

    string getCourseCode(){
        return courseCode;
    }

    void setCourseCode(string courseCode){
        this->courseCode = courseCode;
    }
};

class prerequisites{
  private:
    prerequisitesInfo *head;

  public:
    prerequisites(){head = nullptr;}

    bool isEmpty(){
        return head == nullptr;
    }

    void addPreCourse(string courseCode) {
        prerequisitesInfo *newCourse = new prerequisitesInfo(courseCode);
        if (isEmpty()) {
            head = newCourse;
            return;
        }
        prerequisitesInfo *current = head;
        for (; current->next != nullptr; current = current->next);
        current->next = newCourse;
    }

    void deleteCourse(string courseCode) {
        if (isEmpty()) {
            cout << "No prerequisites to delete." << endl;
            return;
        }

        if (head->getCourseCode() == courseCode) {
            prerequisitesInfo *temp = head;
            head = head->next;
            delete temp;
            cout << "Course " << courseCode << " deleted." << endl;
            return;
        }

        prerequisitesInfo *current = head;
        for (; current->next != nullptr && current->next->getCourseCode() != courseCode; 
            current = current->next);

        if (current->next == nullptr) {
            cout << "Course " << courseCode << " not found." << endl;
            return;
        }

        prerequisitesInfo *temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Course " << courseCode << " deleted." << endl;
    }    

    string getPreCourses() {
        if (isEmpty()) {
            return "No courses";
        }

        prerequisitesInfo *current = head;
        string Courses = "";
        for (; current != nullptr; current = current->next) {
            Courses += current->getCourseCode();
            if (current->next != nullptr){Courses += ",";}
        }
        return Courses;
    }
};