#include <iostream>
#include "matrielLinkedlist_existing.cpp"
#include "matrielsLinkedkist_previous.cpp"
using namespace std;

class matriels{
private:
    matrielInfo *head;
    previousMatriels prev;
    existingMatriels exist;

public:
    matriels (){
        head = nullptr;
        exist.matriels();
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addMatriel(string courseCode){
        matrielInfo *newMatriel = exist.searchMatriel(courseCode);
        string preCourse = newMatriel->getPreCourses();
        if (preCourse == "No courses");
        else {
            if (!prev.checkCourse(preCourse)){
                cout<< "Subject not available";
            }
        }

        if (newMatriel == nullptr){
            cout<< "No matriel found with this course code";
            return;
        }

        if (isEmpty()){
            head = newMatriel;
            return;
        }

        matrielInfo *current = head;
        for (; current->next != nullptr; current = current->next);
        current->next = newMatriel;
    }

    void updateMatriel(int matrielID, string courseName, string courseCode, float creditHour){
        if (isEmpty()){
            cout<< "No matriels";
            return;
        }

        if (matrielID == head->getCourseID()){
            head->setCourseName(courseName);
            head->setCourseCode(courseCode);
            head->setCreditHours(creditHour);
        }
        matrielInfo *current = head;

        for (; current != nullptr; current = current->next){
            if (current->getCourseID() == matrielID){
                current->setCourseName(courseName);
                current->setCourseCode(courseCode);
                current->setCreditHours(creditHour);
            }
        }
    }

    void deleteMatriel(int matrielID) {
        if (isEmpty()) {
            cout << "No materials to delete." << endl;
            return;
        }

        if (head->getCourseID() == matrielID) {
            matrielInfo *temp = head;
            head = head->next;
            delete temp;
            cout << "Material with ID " << matrielID << " deleted." << endl;
            return;
        }

        matrielInfo *current = head;
        for (; current->next != nullptr && current->next->getCourseID() != matrielID; current = current->next){
            if (current->next->getCourseID() == matrielID){
                matrielInfo *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
        }

        if (current->next == nullptr) {
            cout << "Material with ID " << matrielID << " not found." << endl;
        }
    }

    void addGrade(string courseCode, string gradeName, float gradeValue) {
        if (isEmpty()) {
            cout << "No materials available to add grades.\n";
            return;
        }

        matrielInfo *current = head;
        while (current != nullptr) {
            if (current->getCourseCode() == courseCode) {
                current->addGrade(gradeName, gradeValue);
                return;
            }
            current = current->next;
        }
    }

    void updateGrade(string courseCode, int gradeId, float gradeValue) {
        if (isEmpty()) {
            cout << "No materials available.\n";
            return;
        }

        matrielInfo *current = head;
        while (current != nullptr) {
            if (current->getCourseCode() == courseCode) {
                current->updateGrade(gradeId, gradeValue);
                return;
            }
            current = current->next;
        }

        cout << "Material with course code " << courseCode << " not found in the current materials.\n";
    }

    void deleteGrade(string courseCode, int gradeID) {
        if (isEmpty()) {
            cout << "No materials available.\n";
            return;
        }

        matrielInfo *current = head;
        while (current != nullptr) {
            if (current->getCourseCode() == courseCode) {
                current->deleteGrade(gradeID);
                return;
            }
            current = current->next;
        }

        cout << "Material with course code " << courseCode << " not found in the current materials.\n";
    }

    void updateMatriel(string courseCode, string newCourseName, string newCourseCode, float newCreditHours) {
        if (isEmpty()) {
            cout << "No materials available to update.\n";
            return;
        }

        matrielInfo *current = head;
        while (current != nullptr) {
            if (current->getCourseCode() == courseCode) {
                current->setCourseName(newCourseName);
                current->setCourseCode(newCourseCode);
                current->setCreditHours(newCreditHours);
                cout << "Material with course code " << courseCode << " has been updated.\n";
                return;
            }
            current = current->next;
        }

        cout << "Material with course code " << courseCode << " not found in the current materials.\n";
    }

    void deleteMatriel(int matrielID){
        if (isEmpty()) {
            cout << "No materials to delete.\n";
            return;
        }

        matrielInfo *current = head;
        matrielInfo *previous = nullptr;

        while (current != nullptr && current->getCourseID() != matrielID) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Material with ID " << matrielID << " not found.\n";
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } 
        else {
            previous->next = current->next;
        }

        delete current;
    }

    void deleteMatrielAndPrevIt(int matrielID) {
        if (isEmpty()) {
            cout << "No materials to delete.\n";
            return;
        }

        matrielInfo *current = head;
        matrielInfo *previous = nullptr;

        while (current != nullptr && current->getCourseID() != matrielID) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Material with ID " << matrielID << " not found.\n";
            return;
        }

        prev.addMatriel(current->getCourseCode(), current->getMark());
        cout << "Material with ID " << matrielID << " moved to previous materials.\n";

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
    }

};
