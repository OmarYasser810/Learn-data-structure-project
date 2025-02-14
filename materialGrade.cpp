#include <iostream>
using namespace std;

class gradeInfo{
  private:
    int gradeID;
    string gradeName;
    float grade;

  public:
    gradeInfo* next;
    
    gradeInfo(int gradeID, string gradeName, float grade){
        this->gradeID = gradeID;
        this->gradeName = gradeName;
        this->grade = grade;
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

    float getGrade(){
        return grade;
    }

    void setGrade(float grade){
        this->grade = grade;
    }
};

class grades{
  private:
    int gradeID;
    gradeInfo *head = nullptr;

  public:
    grades(){
        head = nullptr;
        gradeID = 0;
    }

    int getGradeID(){
        return gradeID;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addGrade(string gradeName, float gradeGrade){
        gradeID++;
        gradeInfo *newGrade = new gradeInfo(gradeID, gradeName, gradeGrade);
        if (isEmpty()){
            head = newGrade;
            return;
        }

        float total = calculateTotal() + gradeGrade;
        if (total > 100 || total < 0){
            cout<< "Total grades is more than 100 or less than 0 plz try again.";
            cout<< "Current total = "<< calculateTotal();
            return;
        }

        gradeInfo *current = head;
        for (; current->next != nullptr; current = current->next);
        current->next = newGrade;
    }

    void updateGrade(int gradeID, float gradeGrade){
        if (isEmpty()){
            cout<< "No grades yet.";
            return;
        }

        gradeInfo *current = head;
        for (; current != nullptr; current = current->next){
            if (current->GetGradeID() == gradeID){
                current->setGrade(gradeGrade);
                return;
            }
        }
        cout<< "No grade found with the grade ID: "<< gradeID<<".";
    }

    void deleteGrade(int gradeID){
        if (isEmpty()){
            cout<< "No grades yet.";
        }

        gradeInfo *temp, *current = head;
        for (; current->next != nullptr; current = current->next){
            if (current->next->GetGradeID() == gradeID){
                temp = current->next;
                current->next = current->next->next;
                this->gradeID--;
                delete temp;
                return;
            }
        }
        cout<< "No grade found with the number "<< gradeID<<".";
    }

    void displayGrades(){
        if (isEmpty()){
            cout<< "No grades yet.";
            return;
        }

        gradeInfo *current = head;
        for (; current != nullptr; current = current->next){
            cout<< "\n"<< current->GetGradeID()<< "- "
                << "\n"<< current->getGradeName()<< ": "
                << current->getGrade()<< "\n";
        }
    }

    float calculateTotal(){
        if (isEmpty()){return 0;}

        float total = 0;
        gradeInfo *current = head;
        for (; current != nullptr; current = current->next){
            total += current->getGrade();
        }
        if (total > 100){
            cout<< "Grade more than 100 plz update the grade";
            total = -1;
            return total;
        }
        return total;
    }
};