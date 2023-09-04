#include <iostream>
#include <thread>

// Function to be executed by the thread
void threadFunction() {
    // Perform some task
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // Create a thread object and pass the function to be executed
    std::thread myThread(threadFunction);

    // Wait for the thread to finish its execution
    myThread.join();

    // Output a message from the main thread
    std::cout << "Hello from main thread!" << std::endl;

    // return 0;
}
