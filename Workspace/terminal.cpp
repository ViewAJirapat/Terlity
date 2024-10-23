#include <iostream>
#include <vector>
#include <string>

class Email {
public:
    std::string subject;
    std::string body;

    Email(const std::string& subj, const std::string& bod) : subject(subj), body(bod) {}
};

class Log {
public:
    std::string date;
    std::string content;

    Log(const std::string& dt, const std::string& cont) : date(dt), content(cont) {}
};

class Terminal {
private:
    std::vector<Email> emails;
    std::vector<Log> logs;

public:
    Terminal() {
        // Sample data
        emails.push_back(Email("Mission Update", "Your new mission is to retrieve the data from the server."));
        logs.push_back(Log("2077-10-23", "Server maintenance completed successfully."));
    }

    void displayWelcomeMessage() {
        std::cout << "===================================\n";
        std::cout << "       Welcome to the Terminal     \n";
        std::cout << "     Message of the Day (MOTD):    \n";
        std::cout << "  Remember to complete your tasks!  \n";
        std::cout << "===================================\n\n";
    }

    void displayEmails() {
        std::cout << "Emails:\n";
        for (size_t i = 0; i < emails.size(); ++i) {
            std::cout << i + 1 << ". " << emails[i].subject << std::endl;
        }
        std::cout << "Select an email to read (0 to return): ";
    }

    void readEmail(int index) {
        if (index >= 0 && index < emails.size()) {
            std::cout << "Subject: " << emails[index].subject << "\n" << emails[index].body << "\n\n";
        } else {
            std::cout << "Invalid selection.\n";
        }
    }

    void displayLogs() {
        std::cout << "Logs:\n";
        for (size_t i = 0; i < logs.size(); ++i) {
            std::cout << i + 1 << ". [" << logs[i].date << "] " << logs[i].content << std::endl;
        }
        std::cout << "Select a log to read (0 to return): ";
    }

    void readLog(int index) {
        if (index >= 0 && index < logs.size()) {
            std::cout << "[" << logs[index].date << "] " << logs[index].content << "\n\n";
        } else {
            std::cout << "Invalid selection.\n";
        }
    }

    void run() {
        
        displayWelcomeMessage(); // Display the welcome message

        while (true) {
            std::cout << "Terminal Menu:\n";
            std::cout << "1. View Emails\n";
            std::cout << "2. View Logs\n";
            std::cout << "3. Exit\n";
            std::cout << "Choose an option: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                displayEmails();
                int emailChoice;
                std::cin >> emailChoice;
                if (emailChoice > 0 && emailChoice <= emails.size()) {
                    readEmail(emailChoice - 1);
                }
            } else if (choice == 2) {
                displayLogs();
                int logChoice;
                std::cin >> logChoice;
                if (logChoice > 0 && logChoice <= logs.size()) {
                    readLog(logChoice - 1);
                }
            } else if (choice == 3) {
                break; // Exit
            } else {
                std::cout << "Invalid option. Please try again.\n";
            }
        }
    }
};

int main() {
    Terminal terminal;
    terminal.run();
    return 0;
}
