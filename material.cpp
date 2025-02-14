#include <iostream>
#include <fstream>
#include <sstream>
#include "materialGrade.cpp"
using namespace std;

class matrielInfo{
  private:
    int courseID;
    string courseName;
    string courseCode;
    float creditHours;
    grades grade;

  public:
    matrielInfo *next;

    matrielInfo (string courseCode){
        this->courseCode = courseCode;
    }

    matrielInfo (string courseName , string courseCode, float creditHour){
        this->courseID = generateCourseID();
        this->courseName = courseName;
        this->courseCode = courseCode;
        this->creditHours = creditHour;
        next = nullptr;
    }

    int getCourseID() {return courseID;}

    string getCourseName() {return courseName;}

    string getCourseCode() {return courseCode;}

    float getCreditHours() {return creditHours;}

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

    void setGrades(grades newGrades) {
        grade = newGrades;
    }

    int generateCourseID() {
        static int idCounter = 1;
        return idCounter++;
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

    // Calculate total grades
    float calculateTotalGrades() {
        return grade.calculateTotal();
    }

    // Display course details
    void displayCourseDetails() {
        cout << "Course ID: " << courseID << "\n";
        cout << "Course Name: " << courseName << "\n";
        cout << "Course Code: " << courseCode << "\n";
        cout << "Credit Hours: " << creditHours << "\n";
        cout << "Grades: \n"; displayGrades();
        cout << "Total Grades: " << calculateTotalGrades() << "\n";
        cout << "-------------------------\n";
    }
};

class existingMatriels{
  private: 
    matrielInfo *head;

  public:
    existingMatriels (){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void loadMatrielsFromCSV() {
        ifstream file("materials.csv");
        if (!file.is_open()) {
            cout << "Error Could not open the file " << "materials.csv" << endl;
            return;
        }

        string line, courseName, courseCode;
        float creditHours;

        // Skip the header line
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string creditHoursStr;

            // Read course details from CSV
            getline(ss, courseName, ',');
            getline(ss, courseCode, ',');
            getline(ss, creditHoursStr, ',');

            // Convert credit hours to float
            creditHours = stof(creditHoursStr);

            // Add material to the list
            addExistingMatriel(courseName, courseCode, creditHours);
        }

        file.close();
        cout << "Materials loaded successfully from " << "materials.csv" << endl;
    }

    void addExistingMatriel (string courseName, string courseCode, float creditHour){
        matrielInfo *newMatriel = new matrielInfo(courseName, courseCode, creditHour);
        if (isEmpty()){
            head = newMatriel;
            return;
        }

        matrielInfo *current = head;

        for(; current->next != nullptr; current = current->next);
        current->next = newMatriel;
    }

    void updateExistingMatriel(int matrielID, string courseName, string courseCode, float creditHour){
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

    void deleteExistingMatriel(int matrielID) {
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
        for (; current->next != nullptr && current->next->getCourseID() != matrielID; current = current->next);

        if (current->next == nullptr) {
            cout << "Material with ID " << matrielID << " not found." << endl;
            return;
        }

        matrielInfo *temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Material with ID " << matrielID << " deleted." << endl;
    }

    matrielInfo* searchExistingMatriel(string courseCode) {
        if (isEmpty()) {
            cout << "No materials available." << endl;
            return nullptr;
        }

        matrielInfo *current = head;
        for (; current != nullptr; current = current->next) {
            if (current->getCourseCode() == courseCode) {
                return current;
            }
        }

        cout << "Material not found." << endl;
        return nullptr;
    }

    void displayExistingMateriels() {
        if (isEmpty()) {
            cout << "No materials available." << endl;
            return;
        }

        matrielInfo *current = head;
        for (; current != nullptr; current = current->next) {
            cout<< current->getCourseID()<< "- "<< endl;
            cout<< current->getCourseName()<< endl;
            cout<< current->getCourseCode()<< endl;
            cout<< current->getCreditHours()<< "\n\n";
        }
    }
};

class matriels{
  private:
    matrielInfo *head;
    existingMatriels exist;

  public:
    matriels (){
        head = nullptr;
        exist.loadMatrielsFromCSV();
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addMatriel(string courseCode){
        matrielInfo *newMatriel = exist.searchExistingMatriel(courseCode);

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
};