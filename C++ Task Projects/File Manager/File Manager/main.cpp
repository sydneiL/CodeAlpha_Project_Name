//File Manager
// Created by Sydnei Lang on 3/2/24.
//C++ Task Project For CodeAlpha


#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void listDirectoryContents(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void createDirectory(const std::string& path) {
    if (fs::create_directory(path)) {
        std::cout << "Directory created successfully.\n";
    } else {
        std::cerr << "Failed to create directory.\n";
    }
}

void viewFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "File copied successfully.\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void moveFile(const std::string& source, const std::string& destination) {
    try {
        fs::rename(source, destination);
        std::cout << "File moved successfully.\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::string currentDirectory = fs::current_path().string();
    std::string userInput;

    while (true) {
        std::cout << "Current Directory: " << currentDirectory << std::endl;
        std::cout << "Commands: ls (list) | mkdir (make directory) | view (view file) | cp (copy file) | mv (move file) | cd (change directory) | exit" << std::endl;
        std::cout << "> ";
        std::cin >> userInput;

        if (userInput == "ls" || userInput == "list") {
            listDirectoryContents(currentDirectory);
        } else if (userInput == "mkdir") {
            std::string directoryName;
            std::cout << "Enter directory name: ";
            std::cin >> directoryName;
            createDirectory(currentDirectory + "/" + directoryName);
        } else if (userInput == "view") {
            std::string fileName;
            std::cout << "Enter file name: ";
            std::cin >> fileName;
            viewFile(currentDirectory + "/" + fileName);
        } else if (userInput == "cp") {
            std::string source, destination;
            std::cout << "Enter source file name: ";
            std::cin >> source;
            std::cout << "Enter destination file name: ";
            std::cin >> destination;
            copyFile(currentDirectory + "/" + source, currentDirectory + "/" + destination);
        } else if (userInput == "mv") {
            std::string source, destination;
            std::cout << "Enter source file name: ";
            std::cin >> source;
            std::cout << "Enter destination file name: ";
            std::cin >> destination;
            moveFile(currentDirectory + "/" + source, currentDirectory + "/" + destination);
        } else if (userInput == "cd") {
            std::string newDirectory;
            std::cout << "Enter directory name: ";
            std::cin >> newDirectory;
            currentDirectory += "/" + newDirectory;
        } else if (userInput == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
