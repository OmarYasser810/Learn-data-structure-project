#include <iostream>
#include "matrielInfo.cpp"
using namespace std;

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

    void addMatriel (string courseName, string courseCode, float creditHour){
        matrielInfo *newMatriel = new matrielInfo(courseName, courseCode, creditHour);

        if (isEmpty()){
            head = newMatriel;
            return;
        }

        matrielInfo *current = head;

        for(; current->next != nullptr; current = current->next);
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

    matrielInfo* searchMatriel(string courseCode) {
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

        void addPreCourse(string searchCode, string courseCode) {
        matrielInfo *course = searchMatriel(searchCode);
        if (course == nullptr) {
            cout << "Material ID not found." << endl;
            return;
        }

        course->addPreCourses(courseCode);
    }

    void displayMateriels() {
        if (isEmpty()) {
            cout << "No materials available." << endl;
            return;
        }

        matrielInfo *current = head;
        for (; current != nullptr; current = current->next) {
            cout<< current->getCourseName()<< endl;
            cout<< current->getCourseCode()<< endl;
            cout<< current->getCourseID()<< endl;
            cout<< current->getCreditHours()<< endl;
            cout<< current->getPreCourses()<< endl;
        }
    }

    // Did not include csv in the project so i just put it here.
    void matriels() {
        addMatriel("Object Oriented Programming", "CSE015", 3);
        addPreCourse("CSE015", "CSE014");

        addMatriel("Computer Skills", "CSE011", 0);

        addMatriel("Scientific Applications of Computers", "CSE012", 2);

        addMatriel("Introduction to Information systems & technology", "CSE013", 2);

        addMatriel("Structured Programming", "CSE014", 3);

        addMatriel("Digital Branding", "CSE081", 3);

        addMatriel("Data Structures", "CSE111", 3);
        addPreCourse("CSE111", "CSE015");

        addMatriel("Design & Analysis of Algorithms", "CSE112", 4);
        addPreCourse("CSE112", "CSE111");

        addMatriel("Electric &Electronic Circuits", "CSE113", 3);
        addPreCourse("CSE113", "PHY212");

        addMatriel("Logic Design", "CSE131", 3);

        addMatriel("Computer Architecture &Organization", "CSE132", 3);
        addPreCourse("CSE132", "CSE131");

        addMatriel("Field Training 1 in Computer Science", "CSE191", 2);

        addMatriel("Field Training 2 in Computer Science", "CSE192", 2);

        addMatriel("Web Programming", "CSE211", 3);
        addPreCourse("CSE211", "CSE015");

        addMatriel("Database Systems", "CSE221", 3);
        addPreCourse("CSE221", "CSE111");

        addMatriel("Operating Systems Administration", "CSE232", 3);
        addPreCourse("CSE232", "CSE014");

        addMatriel("Operating Systems", "CSE233", 3);
        addPreCourse("CSE233", "CSE111");

        addMatriel("Embedded Systems", "CSE234", 3);
        addPreCourse("CSE234", "CSE132");

        addMatriel("Security of Information Systems", "CSE241", 3);

        addMatriel("Cryptography", "CSE242", 3);
        addPreCourse("CSE242", "CSE112");

        addMatriel("Secure Programming", "CSE243", 3);
        addPreCourse("CSE243", "CSE241");
        addPreCourse("CSE243", "CSE344");

        addMatriel("Software Engineering", "CSE251", 3);
        addPreCourse("CSE251", "CSE015");

        addMatriel("Computer Networks", "CSE261", 3);
        addPreCourse("CSE261", "CSE014");
        addPreCourse("CSE261", "CSE132");

        addMatriel("Parallel Programming", "CSE373", 3);
        addPreCourse("CSE373", "CSE015");

        addMatriel("Image Processing", "CSE281", 3);
        addPreCourse("CSE281", "CSE015");
        addPreCourse("CSE281", "MAT212");

        addMatriel("Introduction to Digital Forensics", "CSE283", 3);

        addMatriel("Computer Graphics", "CSE382", 3);
        addPreCourse("CSE382", "CSE281");

        addMatriel("Graduation Project 1", "CSE493", 3);
        addPreCourse("CSE493", "SENIOR STANDING");

        addMatriel("Graduation Project 2", "CSE494", 3);
        addPreCourse("CSE494", "CSE493");

        addMatriel("Networks Virtualization and Administration", "CSE361", 3);
        addPreCourse("CSE361", "CSE261");
        addPreCourse("CSE361", "CSE262");

        addMatriel("Industrial Networks", "CSE362", 3);
        addPreCourse("CSE362", "CSE261");

        addMatriel("Cloud Computing", "CSE363", 3);
        addPreCourse("CSE363", "CSE261");

        addMatriel("Distributed Information Systems", "CSE474", 3);
        addPreCourse("CSE474", "CSE221");
        addPreCourse("CSE474", "CSE261");

        addMatriel("High Performance Computing", "CSE475", 3);
        addPreCourse("CSE475", "CSE271");

        addMatriel("Advanced Networking", "CSE463", 3);
        addPreCourse("CSE463", "CSE261");
        addPreCourse("CSE463", "CSE262");

        addMatriel("Internet of Things", "CSE464", 3);
        addPreCourse("CSE464", "CSE261");

        addMatriel("Selected Topics in Cloud Computing", "CSE465", 3);
        addPreCourse("CSE465", "CSE363");

        addMatriel("Selected Topics in IoT", "CSE466", 3);
        addPreCourse("CSE466", "CSE464");

        addMatriel("Interactive Multimedia", "CSE484", 3);
        addPreCourse("CSE484", "CSE382");

        addMatriel("Computer Games Theory", "CSE485", 3);
        addPreCourse("CSE485", "CSE382");

        addMatriel("Visualization & Animation", "CSE488", 3);
        addPreCourse("CSE488", "CSE382");

        addMatriel("Introduction to Cyber Security", "CSE344", 3);

        addMatriel("Software Testing", "CSE453", 3);
        addPreCourse("CSE453", "CSE251");

        addMatriel("Advanced Software Engineering", "CSE454", 3);
        addPreCourse("CSE454", "CSE251");

        addMatriel("Real Time & Embedded Systems Design", "CSE335", 3);
        addPreCourse("CSE335", "CSE234");

        addMatriel("Selected Topics in Big Data", "CSE427", 3);
        addPreCourse("CSE427", "CSE322");

        addMatriel("Selected Topics in Information Security", "CSE445", 3);
        addPreCourse("CSE445", "CSE241");
        addPreCourse("CSE445", "CSE344");

        addMatriel("Selected Topics in Embedded Systems", "CSE436", 3);
        addPreCourse("CSE436", "CSE234");

        addMatriel("Embedded Systems", "CSE234", 3);
        addPreCourse("CSE234", "CSE132");

        addMatriel("Parallel & Distributed Systems", "CSE272", 3);
        addPreCourse("CSE272", "CSE132");

        addMatriel("Big Data Analytics 1", "CSE322", 3);
        addPreCourse("CSE322", "AIE121");

        addMatriel("Data Warehousing", "CSE424", 3);
        addPreCourse("CSE424", "CSE323");

        addMatriel("Selected Topics in Data Science", "CSE426", 3);
        addPreCourse("CSE426", "CSE322");

        addMatriel("Graduation Project 1 in AI Science", "AIE493", 3);
        addPreCourse("AIE493", "SENIOR STANDING");

        addMatriel("Graduation Project 2 in AI Science", "AIE494", 3);
        addPreCourse("AIE494", "AIE493");
    }

};