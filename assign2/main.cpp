/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob
 * Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"

std::string kYourName = "Connor Anderson"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names
 * as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the
 * function below it) to use a `std::unordered_set` instead. If you do so, make
 * sure to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
    // STUDENT TODO: Implement this function.
    std::ifstream ifs("students.txt");
    std::unordered_set<std::string> results;

    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            results.insert(line);
        }
    }

    return results;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as
 * this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*>
find_matches(std::string name, std::unordered_set<std::string>& students) {
    std::queue<const std::string*> results{};

    char init_f = name.at(0);
    char init_l = name.at(name.find(" ") + 1);

    for (const std::string& student : students) {
        char f = student.at(0);
        char l = student.at(student.find(" ") + 1);

        if (init_f == f && init_l == l) {
            results.push(&student);
        }
    }

    std::cout << "find_matches size" << results.size() << "\n";

    return results;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true
 * match!
 *
 * You can implement this function however you'd like, but try to do something a
 * bit more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
    if (matches.empty()) {
        return "NO MATCHES FOUND";
    }

    std::string match;
    while (!matches.empty()) {
        const std::string& applicant = *matches.front();
        matches.pop();
        if (applicant.length() > match.length()) {
            match = applicant;
        }
    }

    return match;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
