# Learn-data-structure-project
Project Overview
Create a console-based Student Management System that allows users to manage a list of students in a university. The project will utilize linked lists, pointers (to manage dynamic data storage), sorting algorithms, and different data structures (as you see fit).
1)Features and Requirements
Menu-Driven Interface
A user-friendly text-based menu to perform various operations.
Include options for:
Adding a new student.
Deleting a student by ID.
Searching for a student by ID or name.
Updating a student's information.
Displaying all students in the list.
Sorting the list by name or GPA.
Exiting the system.

2)Student Data Structure
Each student record will include (elements could also be classes/structs, do as you see fit):
ID (integer)
Name (string)
Age (integer)
GPA (float)
Pointer to the next node (for the linked list).
Grades (float) *Made using an array of Grade structs*

3)Core Functionalities
Add Student: Insert a new student record at the end of the linked list.
Delete Student: Remove a student node from the list based on their unique ID.
Search Student: Find a student by ID or name and display their information.
Update Student: Modify details like name, age, or GPA of an existing student.
Display Students: Traverse and print all student records.
Sort Students: Implement sorting of the linked list by name (alphabetical order) or GPA (descending).

4)Error Handling
Ensure appropriate error messages for invalid inputs, such as:
Adding a student with a duplicate ID.
Searching for a non-existent student.
Trying to delete from an empty list.

5)Memory Management
Use dynamic memory allocation to create and manage student nodes.
Ensure proper cleanup of memory when deleting nodes or exiting the program to prevent memory leaks.

6)Modular Design
Use functions to encapsulate each operation (e.g., addStudent(), deleteStudent(), searchStudent()).
Keep the main() function minimal, focusing only on menu handling.


2)Additional Requirements
To ensure that each project implementation is unique and provides comprehensive learning opportunities, include one of the features mentioned below:

1)Customization Features
Unique Sorting Options
Implement an additional sorting option, such as sorting by age or ID, in addition to sorting by name and GPA. Users should also be able to choose whether to sort in ascending or descending order dynamically during runtime.
Enhanced Search Capabilities
Add functionality for partial name searches, allowing users to find students based on case-insensitive substring matching. Include an option to search for students using multiple criteria, such as searching by both ID and GPA thresholds.
Filtering Functionality
Introduce options to filter students based on specific criteria, such as GPA ranges (e.g., above 3.0) or age (e.g., students older than 21).

2)Advanced Data Management
Save and Load Feature
Enable the system to save the linked list data to a file and reload it when the program is restarted. Use a simple file format, such as CSV or JSON, and ensure the program can handle invalid file formats gracefully.
Error Handling Enhancements
Design the system to handle edge cases, such as extremely long names or invalid ID formats, and provide appropriate error messages for these scenarios.
Extended Student Records
Optionally, enhance the student structure by adding fields such as email, department, or year of study. Provide functionality to manage optional fields effectively.

3)Dynamic Interaction
Custom Menu Design
Implement a uniquely styled menu, with the order of options or display format differing from others. Optionally, enhance the menu interface with text colors or special formatting for better usability.
Interactive Sorting Visualization
Allow users to view how the list changes dynamically after each step of the sorting process.

4)Testing and Performance
Test Case Generator
Include a feature to generate random student records (e.g., 50 students with random values) for testing purposes. Use these generated datasets to validate the system's functionality.
Performance Metrics
Display performance metrics, such as the time taken to sort or search through the student records, as part of the output.
