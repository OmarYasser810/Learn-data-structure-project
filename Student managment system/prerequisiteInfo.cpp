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