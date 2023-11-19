#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    // Function to add a task to the list
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << "\n";
    }

    // Function to view all tasks
    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].completed) {
                    std::cout << " (Completed)";
                }
                std::cout << "\n";
            }
        }
    }

    // Function to mark a task as completed
    void markAsCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << "\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    // Function to remove a task from the list
    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << "\n";
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    std::string taskDescription;

    std::cout << "Welcome to the To-Do List Manager!\n";

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore newline from previous input
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter the index of the task to mark as completed: ";
                size_t completedIndex;
                std::cin >> completedIndex;
                toDoList.markAsCompleted(completedIndex);
                break;
            case 4:
                std::cout << "Enter the index of the task to remove: ";
                size_t removeIndex;
                std::cin >> removeIndex;
                toDoList.removeTask(removeIndex);
                break;
            case 0:
                std::cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

