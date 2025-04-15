#include <iostream>
using namespace std;

class gradeInfo{
private:
    int gradeID;
    string gradeName;
    float gradeGrade;

public:
    gradeInfo* next;
    
    gradeInfo(int gradeID, string gradeName, float gradeGrade){
        this->gradeID = gradeID;
        this->gradeName = gradeName;
        this->gradeGrade = gradeGrade;
        next = nullptr;
    }

    int GetGradeID() const {
        return gradeID;
    }

    string getGradeName(){
        return gradeName;
    }

    void setGradeName(string gradeName){
        this->gradeName = gradeName;
    }

    float getGradeGrade(){
        return gradeGrade;
    }

    void setGradegrade(float gradeGrade){
        this->gradeGrade = gradeGrade;
    }
};