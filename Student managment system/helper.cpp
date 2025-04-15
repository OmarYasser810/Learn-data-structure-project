#include <iostream>
#include <string.h>
using namespace std;

void swap(int first, int second){
    int temp = first;
    first = second;
    second = temp;
}

void swap(string first, string second){
    string temp = first;
    first = second;
    second = temp;
}

void swap(float first, float second){
    float temp = first;
    first = second;
    second = temp;
}

float gradeToPoint(const string &grade) {
    if (grade == "A") return 4.0;
    if (grade == "B+") return 3.5;
    if (grade == "B") return 3.0;
    if (grade == "C+") return 2.5;
    if (grade == "C") return 2.0;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;
    return 0.0; // Default for unknown grades
    }