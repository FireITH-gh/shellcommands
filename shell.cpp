#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main() {

    int choice;

    do {
        // Present user with a menu of 6 choices
        std::cout << std::endl << "Choose a function:\n0. Exit\n1. List contents of current working directory\n2. Print the currrent working directory\n3. Create a new directory\n4. Display a give message\n5. Edit, concatenate and display the contents of chosen files" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 0: {
                // User elected to exit program
                std::cout << std::endl << "Exiting..." << std::endl;
                break;
            }

            case 1: {
                std::cout << std::endl << "Files in current directory: " << std::endl;

                // Lists files in the current directory
                int returnCode = system("dir"); 
                std::cout << std::endl;

                // Error handling
                if (returnCode != 0) {
                    std::cout << std::endl << "Error: unable to list files" << std::endl;
                }

                break;
            }

            case 2: {
                std::cout << std::endl << "Current working directory: ";

                // Lists the current working directory
                int returnCode = system("cd");
                
                // Error handling
                if (returnCode != 0) {
                    std::cout << std::endl << "Error: unable to print current directory" << std::endl;
                }
                break;
            }

            case 3: {
                std::string dirName;
                std::cout << std::endl << "Enter the name of the directory you wish to create: " << std::endl;

                // Get directory name from user
                std::cin.ignore();
                std::getline(std::cin, dirName);
                std::string command = "mkdir " + dirName;

                // Creates a new directory, and stores the result of the function
                int returnCode = system(command.c_str());  

                // Check if command was successful
                if (returnCode != 0) {
                    std::cout << std::endl << "Unable to create the given directory" << std::endl;
                    break;
                } else {
                    std::cout << std::endl << "Successfully created the given directory." << std::endl;
                    std::cout << std::endl << "Current directory contents: " << std::endl;
                    system("dir");
                    std::cout << std::endl;
                    break;
                }
            }

            case 4: {
                std::string message;
                std::cout << std::endl << "Enter the message to be displayed: " << std::endl;

                // Get message from user
                std::cin.ignore();
                std::getline(std::cin, message);
                std::string command = "echo " + message;

                // Print user message using system
                std::cout << std::endl;
                int returnCode = system(command.c_str());
                std::cout << std::endl;

                // Error handling
                if (returnCode != 0) {
                    std::cout << std::endl << "Error: unable to print given message" << std::endl;
                }
                break;
            }

            case 5: {
                std::string filename1;
                std::string filename2;

                // Get name of the first file from user
                std::cout << std::endl << "Enter the first file name to create or open:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, filename1);

                // Get name of the second file from user
                std::cout << std::endl << "Enter the second file name to create or open: " << std::endl;
                std::getline(std::cin, filename2);

                // Open/create the first file
                std::ofstream file1(filename1);

                // Error handling
                if (!file1.is_open()) {
                    std::cout << std::endl << "Error: Unable to open/create " << filename1 << std::endl;
                    break;
                }

                std::string input1;

                // Get input for first file from user
                std::cout << std::endl << "Enter the contents of the first file:" << std::endl;
                std::getline(std::cin, input1);

                // Write content to the first file
                file1 << input1;
                file1.close();

                // Open/create the second file
                std::ofstream file2(filename2);

                // Error handling
                if (!file2.is_open()) {
                    std::cout << std::endl << "Error: Unable to open/create " << filename2 << std::endl;
                }

                std::string input2;

                // Get input for second file from user
                std::cout << std::endl << "Enter the contents of the second file: " << std::endl;
                std::getline(std::cin, input2);

                // Write content to the second file
                file2 << input2;
                file2.close();

                // Concatenate and display both files
                std::string command = "type " + filename1 + "&& type " + filename2;
                std::cout << std::endl << "Concatenated files: " << std::endl;
                int returnCode = system(command.c_str());

                // Error handling
                if (returnCode != 0) {
                    std::cout << std::endl << "Error: unable to concatenate or display files" << std::endl;
                }
                break;
            }
            
            default: {
                std::cout << std::endl << "Invalid selection. Please choose between 0-5." << std::endl;
            }
        }


    } while (choice != 0);




    return 0;
}