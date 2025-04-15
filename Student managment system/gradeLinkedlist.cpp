#include <iostream>
#include "gradeInfo.cpp"
using namespace std;

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
                current->setGradegrade(gradeGrade);
                return;
            }
        }
        cout<< "No grade found with the number"<< gradeID<<".";
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
                << current->getGradeGrade()<< "\n";
        }
    }

    float calculateTotal(){
        if (isEmpty()){return 0;}

        float total = 0;
        gradeInfo *current = head;
        for (; current != nullptr; current = current->next){
            total += current->getGradeGrade();
        }
        if (total > 100){
            cout<< "Grade more than 100 plz update the grade";
            total = -1;
            return total;
        }
        return total;
    }

    string getMark(){
        float total = calculateTotal();
        string mark;
        
        // here needs update
        if (total == -1) return "Grades wrong please update grades.";
        else if (total >= 97) {mark = "A+";} 
        else if (total >= 93) { mark = "A";} 
        else if (total >= 89) {mark = "A-";} 
        else if (total >= 84) { mark = "B+";} 
        else if (total >= 80) {mark = "B";} 
        else if (total >= 76) { mark = "B-";} 
        else if (total >= 73) { mark = "C+";} 
        else if (total >= 70) {mark = "C";} 
        else if (total >= 67) {mark = "C-";} 
        else if (total >= 64) { mark = "D+";} 
        else if (total >= 60) {mark = "D";} 
        else {mark = "F";}
        return mark;
    }
};