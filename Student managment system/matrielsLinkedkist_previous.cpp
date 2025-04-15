#include <iostream>
#include <string.h>
#include "helper.cpp"
#include "matrielInfo.cpp"
using namespace std;

class previousMatriels{
private:
    matrielInfo *head;

public:
    previousMatriels (){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addMatriel(string courseCode, string mark){
        matrielInfo *newMatriel = new matrielInfo(courseCode);

        if (isEmpty()){
            head = newMatriel;
            return;
        }

        matrielInfo *current = head;
        for (; current->next != nullptr; current = current->next);
        current->next = newMatriel;
    }

    void display (){
        if (isEmpty()){
            cout<< "No Matriels";
            return;
        }

        matrielInfo *current = head;
        for (; current != nullptr; current = current->next){
            cout <<current->getCourseCode()<< ": "<< current->getFinalMark();
        }
    }

    bool checkCourse(string preCourse){
        bool check = false;

        //My bro chatGPT
        char str[preCourse.length() + 1];
        strcpy(str, preCourse.c_str());

        // Use ',' as the delimiter
        char *token = strtok(str, ",");
        
        // Loop through the tokens
        matrielInfo *current = head;
        bool pre = false;
        while (token != NULL) {
            for (; current != nullptr; current = current->next){
                if (token == current->getCourseCode()){
                    if (current->isCoursePass()){
                        check = true;
                        break;
                    }
                }
            }
            if (!check){return false;}
            token = strtok(NULL, ",");
        }
    }

    float calculateCGPA() {
        if (isEmpty()) {
            cout << "No materials available to calculate CGPA.\n";
            return 0.0;
        }

        float totalGradePoints = 0.0;
        float totalCreditHours = 0.0;

        matrielInfo *current = head;
        while (current != nullptr) {
            if (current->isCoursePass()) {
                float gradePoint = gradeToPoint(current->getMark());
                totalGradePoints += gradePoint * current->getCreditHours();
                totalCreditHours += current->getCreditHours();
            }
            current = current->next;
        }

        if (totalCreditHours == 0.0) {
            cout << "No valid courses to calculate CGPA.\n";
            return 0.0;
        }

        float cgpa = totalGradePoints / totalCreditHours;
        return cgpa;
    }

};