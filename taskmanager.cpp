#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    string title;
    string description;
    string dueDate;
};

// Function to display a task
void displayTask(const Task& task) {
    cout << "Title: " << task.title << endl;
    cout << "Description: " << task.description << endl;
    cout << "Due Date: " << task.dueDate << endl;
    cout << endl;
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task title: ";
    getline(cin, newTask.title);
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    cout << "Enter due date: ";
    getline(cin, newTask.dueDate);
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }
    cout << "All Tasks:" << endl;
    for (const Task& task : tasks) {
        displayTask(task);
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }
    cout << "Enter the index of the task you want to delete: ";
    int index;
    cin >> index;
    cin.ignore(); // Ignore the newline character
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid index. No task deleted." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    do {
        cout << "Task Manager Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character
        switch(choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);
    return 0;
}
