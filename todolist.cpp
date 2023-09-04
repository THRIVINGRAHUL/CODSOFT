#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TaskManager {
public:
    void addTask(const string& desc) {
        Task newTask(desc);
        tasks.push_back(newTask);
        cout << "Task added successfully." << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                const Task& task = tasks[i];
                cout << i + 1 << ". " << task.description << " (" << (task.completed ? "Completed" : "Pending") << ")" << endl;
            }
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex < tasks.size()) {
            cout << "Removed task: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    TaskManager taskManager;

    while (true) {
        cout << "\nTodo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cin.ignore(); // Clear newline from the input buffer
                cout << "Enter the task: ";
                getline(cin, taskDescription);
                taskManager.addTask(taskDescription);
                break;
            }
            case 2:
                taskManager.viewTasks();
                break;
            case 3: {
                taskManager.viewTasks();
                size_t taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                taskManager.markTaskCompleted(taskIndex - 1); // Adjust for 0-based index
                break;
            }
            case 4: {
                taskManager.viewTasks();
                size_t taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                taskManager.removeTask(taskIndex - 1); // Adjust for 0-based index
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
