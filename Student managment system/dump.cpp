using namespace std;
#include <iostream>

struct student {
    string Name;
    int ID;
    int Age;
    float GPA;
    student* next;
};

class StudentList {
private:
    student* first;
    student* last;
    int count;

public:
    StudentList() {
        first = last = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    void AddStudent(string name, int ID, int age, float GPA) {
        student* new_student = new student();
        new_student->Name = name;
        new_student->ID = ID;
        new_student->Age = age;
        new_student->GPA = GPA;
        new_student->next = nullptr;

        if (isEmpty()) {
            first = last = new_student;
        } else {
            last->next = new_student;
            last = new_student;
        }
        count++;
    }

    void DeleteStudent(int ID) {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        student* current = first;
        student* previous = nullptr;

        while (current != nullptr && current->ID != ID) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Student with ID " << ID << " not found." << endl;
            return;
        }

        if (previous == nullptr) {
            first = current->next; // Deleting the first node
        } else {
            previous->next = current->next; // Bypass the current node
        }

        if (current == last) {
            last = previous; // Update last if needed
        }

        delete current;
        count--;
        cout << "Student with ID " << ID << " deleted." << endl;
    }

    void UpdateStudent(int ID, string name, int age, float GPA) {
        student* temp = first;
        while (temp != nullptr) {
            if (temp->ID == ID) {
                temp->Name = name;
                temp->Age = age;
                temp->GPA = GPA;
                cout << "Student with ID " << ID << " updated." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student with ID " << ID << " not found." << endl;
    }

    void Display() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
        } else {
            student* temp = first;
            while (temp != nullptr) {
                cout << "Name: " << temp->Name << ", ID: " << temp->ID << ", Age: " << temp->Age << ", GPA: " << temp->GPA << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    StudentList list;  
    int choice;
    int ID;
    int age;
    float GPA;
    string name;

    while (true) {
        // Menu display
        cout << "1. Add Student\n";
        cout << "2. Search By ID\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Bubble sort by GPA\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name, ID, Age, GPA: ";
                cin >> name;
                cin >> ID;
                cin >> age;
                cin >> GPA;
                list.AddStudent(name, ID, age, GPA);
                break;

            case 2:
                cout << "Enter ID to search: ";
                cin >> ID;
                list.SearchByID(ID);
                break;

            case 3:
                cout << "Enter ID to delete: ";
                cin >> ID;
                list.DeleteStudent(ID);
                break;

            case 4:
                cout << "Enter Name, ID, Age, GPA to update: ";
                cin >> name;
                cin >> ID;
                cin >> age;
                cin >> GPA;
                list.UpdateStudent(ID, name, age, GPA);
                break;

            case 5:
                list.bubblesortByGPA();
                cout << "Students sorted by GPA." << endl;
                break;

            case 6:
                list.Display();
                break;

            case 7:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}