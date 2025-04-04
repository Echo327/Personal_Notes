// After OpenAI's ChatGPT-4, February 2025 failed at multithreading
// I decided to keep it simple due to time constraints, and come back later
// The comments and base code are generated by OpenAI's ChatGPT-4, February 2025
// Further modifications were done to the code generated

#include <iostream>
#include <vector>
#include <functional>

// Command Class - Represents the Command in the Command Design Pattern
class Task {
public:
    std::function<void()> action;  // Stores the task action (function/lambda)
    int taskID;  // Unique task ID
    
    static int taskIDCounter;  // Static counter for task IDs
    
    // Constructor initializes task action and assigns a unique task ID
    Task(std::function<void()> action) : action(action), taskID(taskIDCounter++) {}

    // Executes the task action (command execution)
    void execute() {
        action();  // Perform the task's action (can be any callable)
        // The callable is known as the Receiver
    }
};

// Initialize the static task ID counter
int Task::taskIDCounter = 1;

// Invoker Class - The class that triggers the execution of commands (tasks)
class Worker {
public:
    // Executes the given command (task) by calling the task's execute function
    void executeTask(Task* task) {
        if (task) {
            task->execute();  // Perform the task's action
            std::cout << "Task " << task->taskID << " was executed" << std::endl;
        }
    }
};

// Client Class - The scheduler that schedules tasks and manages cycles
class Scheduler {
private:
    std::vector<Task*> taskQueue;  // Task queue (using vector)
    Worker* worker;  // Worker (Invoker) responsible for executing tasks
    int emptyCycles = 0;  // Counter for cycles with no tasks
    int cycleCounter = 1;  // Counter to track the cycle number

public:
    // Constructor initializes the worker (Invoker)
    Scheduler(Worker* w) : worker(w) {}

    // Adds a task (command) to the scheduler
    void addTask(Task* task) {
        taskQueue.push_back(task);  // Add the task to the task queue
        std::cout << "Task " << task->taskID << " added." << std::endl;
    }

    // Starts the scheduler and executes tasks cyclically
    void start() {
        // While there are tasks to execute and fewer than 3 empty cycles
        while (emptyCycles < 3) {
            int tasksExecuted = 0;

            // Print the start of a new cycle
            std::cout << "--- Cycle " << cycleCounter++ << " started ---" << std::endl;

            // Execute up to 2 tasks per cycle
            for (int i = 0; i < 2 && !taskQueue.empty(); ++i) {
                Task* task = taskQueue.front();  // Get the first task in the queue
                taskQueue.erase(taskQueue.begin());  // Remove the task from the queue
                worker->executeTask(task);  // Worker executes the task (command)
                ++tasksExecuted;  // Count the number of tasks executed in this cycle
            }

            // If no tasks were executed, it means the worker was idle
            if (tasksExecuted == 0) {
                ++emptyCycles;  // Increment the empty cycle counter
                std::cout << "Both workers were idle" << std::endl;
            } else if (tasksExecuted == 1)
            {
                std::cout << "1 worker was idle" << std::endl;
                ++emptyCycles; // Half-Empty counts as an empty cycle
            }
            else {
                emptyCycles = 0;  // Reset the empty cycle counter if tasks were executed
            }

            std::cout << "--- Moving to next cycle ---" << std::endl;
        }

        // Stop when there are no more tasks for 3 consecutive empty cycles
        std::cout << "No more tasks to execute." << std::endl;
    }
};

// Main Function
int main() {
    Worker worker;  // Create a worker (Invoker)
    Scheduler scheduler(&worker);  // Create the scheduler (Client)

    // Add tasks dynamically using lambdas (commands)
    scheduler.addTask(new Task([](){ std::cout << "Executing Task A" << std::endl; }));
    scheduler.addTask(new Task([](){ std::cout << "Executing Task B" << std::endl; }));
    scheduler.addTask(new Task([](){ std::cout << "Executing Task C" << std::endl; }));
    scheduler.addTask(new Task([](){ std::cout << "Executing Task D" << std::endl; }));
    scheduler.addTask(new Task([](){ std::cout << "Executing Task E" << std::endl; }));

    // Start the scheduler, which will trigger the execution of tasks (commands)
    scheduler.start();

    return 0;
}
