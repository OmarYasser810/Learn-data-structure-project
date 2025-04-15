#include <iostream>
#include "studentLinkedlist.cpp"
#include <cctype>
#include <cstdlib> // لاستخدام system("cls")
using namespace std;

Students s;
void menu();

void updateStudentInfo(){
    
}//not done

void updateStudentMterial(){
    
}//not done

void addStudent() {
    string studentName, phoneNumber, address, program;
    int dateOfBirth;
    
    cout << "\n====== Add Student ======\n";
    bool b;
    do{
        cout << "Enter Student Name: ";
        cin.ignore(); // للتأكد من قراءة السطر بالكامل
        getline(cin, studentName);

        b = true;
        for (char c : studentName) {
            if (!isalpha(c) && c!=' ' ) {
                cout << "Error in Student Name\n";
                b = false;
                break;
            }
        }
    }while(!b);


    do{
        cout << "Enter Address: ";
        getline(cin, address);

        b = true;
        for (char c : address) {
            if (!isalpha(c) && c!=' ' ) {
                cout << "Error in Address\n";
                b = false;
                break;
            }
        }
    }while(!b);
    
    do{
        cout << "Enter Program: SE or AI";
        cin >> program;
        if (program == "SE" || program == "AI" || program == "Ai" ||program == "Se" ){
            break;
        }else{
            cout << "error Enter Ai or Se\n";
        }
        
    }while(true);
    
    cout << "Enter Date of Birth (YYYYMMDD): ";
    cin >> dateOfBirth;
    
    
    do{
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        
        b = true;
        if( phoneNumber.length() != 12 ){
            cout << "\nEnter 12 Digit for Phone Number\n";
            continue;
        }
        
        for (int i=0; i<11; i++){
            
            if( !( 48 <= phoneNumber[i] && phoneNumber[i] <= 57 ) ){//ASCII value of digits [0 – 9] ranges from [48 – 57].
                
                cout << "\nEnter 11 Digit Number only !!\n";
                b=false;
            }
            
        }break;
    }while(!b);
    
    system("cls");

    s.add_student(studentName, dateOfBirth, address, stoi(phoneNumber), program);
    cout << "\nStudent added successfully!\n";
    menu();
}

void DisplayRange(string type){
    int x,y;
    cout<< "Enter range";
    cin >> x;
    cin >> y;
    
}

void displayAllStudents(bool inOrder,string type){
    cout << "\n====== All Students By " << type << " ======\n";
    
    if (inOrder){
        //in code
    }else{
        //in code
    }
    cout << "\n==========================\n";
    cout << "1- Update Student info\n";
    cout << "2- Update Student Material\n";
    cout << "3- Back to menu\n";
    
    string choice;
    char sw;
    
    cin >> choice;
    system("cls" );
    
    if( choice.length() != 1 ){
        cout << "Enter 1 Digit\n";
        displayAllStudents(inOrder,type);
        return;
    }
    
    switch (sw) {
        case '1':
            updateStudentInfo();
            break;
        case '2':
            updateStudentMterial();
            break;
        case '3':
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            displayAllStudents(inOrder, type);
    }
}//90%

void Display(string type){
    string choice;
    char sw;
    
    cout << "\n====== Display Students by " << type << " ======\n";
    cout << "1- Display All Students by " << type << " In order\n";
    cout << "2- Display All Students by " << type << " Reverse in order\n";
    cout << "3- Display Range of Students by " << type << "\n";
    cout << "4- Back to Menu\n";
    cin >> choice;
    
    system("cls");
    
    if( choice.length() != 1 ){
        cout << "Enter 1 Digit\n";
        Display(type);
    }
    
    switch (sw) {
        case '1':
            displayAllStudents(true,type);
            break;
        case '2':
            displayAllStudents(false,type);
            break;
        case '3':
            DisplayRange(type);
            break;
        case '4':
            menu();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            Display(type);
    }
}//Done

void displayStudents(){
    string choice;
    char sw;
    cout << "\n====== Display Students ======\n";
    cout << "1- Display by ID\n";
    cout << "2- Display by GPA\n";
    cout << "3- Display by Name\n";
    cout << "4- Back to Menu\n";
    
    cin >> choice;
    sw = choice[0];
    system("cls" );
    
    if( choice.length() != 1 ){
        cout << "Enter 1 Digit\n";
        displayStudents();
    }
    
    switch (sw) {
        case '1':
            Display("ID");
            break;
        case '2':
            Display("GPA");
            break;
        case '3':
            Display("Name");
            break;
        case '4':
            menu();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            displayStudents();
    }
    
}//Done

void searchStudentBy(string type){
    
    string str;
    cout << "\n====== Search Student by " << type << " ======\n";
    cout << "Enter Student " << type << "\n";
    cin >> str;
    system("cls" );
    
    if(type == "ID"){//1000 to 2000
        
        if( str.length() != 4 ){
            cout << "\nEnter 4 Digit for Search By ID \n";
            searchStudentBy("ID");
            return;
        }
        
        for (int i=0; i<4; i++){
            
            if( !( 48 <= str[i] && str[i] <= 57 ) ){//ASCII value of digits [0 – 9] ranges from [48 – 57].
                
                cout << "\nEnter 4 Number only !!\n";
                searchStudentBy("ID");
                return;
                
            }
            
        }
        
        int ID = stoi(str);  // stoi : int لتحويل النص إلى
        
        // in code
        //searchStudent(ID)
        
    }else if(type == "Name"){
        
        for (char c : str) {
            if (!isalpha(c) || c!=' ' ) {
                cout << "Error in Student Name\n";
                searchStudentBy("Name");
                return;
            }
        }
        
        //in code
        //searchStudent(str)
        
    }
}//Done 90%

void searchStudent(){

    string choice;
    char sw;

    cout << "\n====== Search Student ======\n";
    cout << "1- Search Student by Name\n";
    cout << "2- Search Student by ID\n";
    cout << "3- Back to Menu\n";
    
    cin >> choice;
    sw = choice[0];
    system("cls" );
    
    if( choice.length() != 1 ){
        cout << "Enter 1 Digit\n";
        searchStudent();
    }
    
    switch (sw) {
        case '1':
            searchStudentBy("Name");
            break;
        case '2':
            searchStudentBy("ID");
            break;
        case '3':
            menu();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            searchStudent();
    }
    
}//Done

void deleteStudent(){
    string str;
    
    cout << "Enter ID Student : ";
    cout << "Enter \"Exit\" if you need Back to menu";
    cin >> str;
    
    if(str == "Exit"){
        menu();
        return;
    }
    
    if( str.length() != 4 ){
        cout << "\nEnter 4 Digit for Search By ID \n";
        deleteStudent();
        return;
    }
    
    for (int i=0; i<4; i++){
        
        if( !( 48 <= str[i] && str[i] <= 57 ) ){//ASCII value of digits [0 – 9] ranges from [48 – 57].
            
            cout << "\nEnter 4 Digit Number only !!\n";
            deleteStudent();
            return;
        }
        
    }
    
    int ID = stoi(str);  // stoi : int لتحويل النص إلى
    
    //in code
    //deleteStudent(ID);
    
}//Done

void menu(){
    
    string choice;
    char sw;
    bool lock = true;
    while (lock) {
        
        cout << "\n====== Student Management System ======\n";
        cout << "1- Add Student\n";//not Done
        cout << "2- Display Students\n";//90%
        cout << "3- Search Student\n";//90%
        cout << "4- Delete Student by ID\n";//90%
        cout << "5- Update Student info\n";
        cout << "6- Update Student Material\n";
        cout << "7- Exit\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        sw = choice[0];
        system("cls" );
        
        if( choice.length() != 1 ){
            cout << "Enter 1 Digit\n";
            continue;
        }
        
        lock = false;
        
        switch (sw) {
            case '1':
                addStudent();
                break;
            case '2':
                displayStudents();
                break;
            case '3':
                searchStudent();
                break;
            case '4':
                deleteStudent();
                break;
            case '5':
                //updateStudentInfo();
                break;
            case '6':
                //updateStudentMterial();
                break;
            case '7':
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                lock = true;
        }
    }
}

int main()
{
    menu();
    return 0;
}