#include <iostream>
#include "gradeLinkedlist.cpp"
#include "prerequisiteLinkedlist.cpp"
using namespace std;

class matrielInfo{
private:
    int courseID;
    string courseName;
    string courseCode;
    float creditHours;
    bool coursePass;
    grades grade;
    string finalMark;
    prerequisites preCourses;

public:
    matrielInfo *next;

    matrielInfo (string courseCode){
        this->courseCode = courseCode;
        this->finalMark = this->getMark();

        if (getMark() != "F"){
            this->coursePass = true;
        }
        else{this->coursePass = false;}
        next = nullptr;
    }

    matrielInfo (string CourseName , string courseCode, float creditHour){
        this->courseID = generateCourseID();
        this->courseName = courseName;
        this->courseCode = courseCode;
        this->creditHours = creditHour;
        this->coursePass = false;
        next = nullptr;
    }

    int getCourseID() {return courseID;}

    string getCourseName() {return courseName;}

    string getCourseCode() {return courseCode;}

    float getCreditHours() {return creditHours;}

    bool isCoursePass() {return coursePass;}

    string getFinalMark(){
        this->finalMark;
    }

    void setCourseID(int id) {
        courseID = id;
    }

    void setCourseName(string courseName){
        this->courseName = courseName;
    }

    void setCourseCode(string code) {
        courseCode = code;
    }

    void setCreditHours(float hours) {
            creditHours = hours;
    }

    void setCoursePass(bool passStatus) {
        coursePass = passStatus;
    }

    void setGrades(grades newGrades) {
        grade = newGrades;
    }

    void setPreCourses(prerequisites newPreCourses) {
        preCourses = newPreCourses;
    }

    int generateCourseID() {
        static int idCounter = 1;
        return idCounter++;
    }

    void addPreCourses (string courseCode){
        preCourses.addPreCourse(courseCode);
    }

    string getPreCourses() {
        string courses = preCourses.getPreCourses();
        return courses;
    }

    void addGrade(string gradeName, float gradeGrade){
        grade.addGrade(gradeName, gradeGrade);
    }

    // Update a grade
    void updateGrade(int gradeID, float gradeValue) {
        grade.updateGrade(gradeID, gradeValue);
    }

    // Delete a specific grade
    void deleteGrade(int gradeID) {
        grade.deleteGrade(gradeID);
    }

    // Display grades
    void displayGrades() {
        grade.displayGrades();
    }

    // Calculate and return the course mark
    string getMark() {
        return grade.getMark();
    }

    // Calculate total grades
    float calculateTotalGrades() {
        return grade.calculateTotal();
    }

    // Display course details
    /*void displayCourseDetails() {
        cout << "Course ID: " << courseID << "\n";
        cout << "Course Name: " << courseName << "\n";
        cout << "Course Code: " << courseCode << "\n";
        cout << "Credit Hours: " << creditHours << "\n";
        cout << "Course Pass: " << (coursePass ? "Yes" : "No") << "\n";
        cout << "Prerequisites: " << getPreCourses() << "\n";
        cout << "Grades: \n"; displayGrades();
        cout << "Total Grades: " << calculateTotalGrades() << "\n";
        cout << "Mark: " << getMark() << "\n";
        cout << "-------------------------\n";
    }*/
};