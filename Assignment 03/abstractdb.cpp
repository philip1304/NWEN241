/**
 * abstractdb.cpp
 * C++ source file that should contain implementation for member functions
 * - loadCSV()
 * - saveCSV()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Tasks 4 and 5)
 */ 

#include "abstractdb.hpp"
#include <fstream>  // for file i/o stream
#include <sstream>  // for string stream (parsing CSV)
#include <string>   // for std::string
#include <cstring>  // for std::strncpy

namespace nwen {

/**
 * @brief - Saves the contents of the table to a CSV file.
 * 
 * Each record is written on a new line in the format:
 * id,"title",year,"director"
 * 
 * @param filename - The name of the file to save to.
 * @return         - True on success, false if the file can't be opened or a write fails.
 */
bool AbstractDbTable::saveCSV(const std::string& filename) {
    std::ofstream out(filename);  // Open file for writing

    if (!out.is_open()) {
        return false; // Failed to open file
    }

    // Loop through each movie record to write to file
    for (int i = 0; i < rows(); ++i) {
        const movie* m = get(i); // Get pointer to movie at index i

        if (m == nullptr) {
            return false;        // Failed to access a valid movie record
        }

        // Write movie record in CSV format: id,"title",year,"director"
        out << m->id << ","
            << "\"" << m->title << "\"" << ","
            << m->year << ","
            << "\"" << m->director << "\"" << "\n";

        if (out.fail()) {
            return false; // Write operation failed
        }
    }

    out.close(); // Close file after writing
    return true; // Indicate success
}

/**
 * @brief - Loads movie records from a CSV file into the table.
 * 
 * Each valid line must match the format:
 * id,"title",year,"director"
 * 
 * If any line is malformed, loading stops and the function returns false.
 * 
 * @param filename - The name of the file to load from.
 * @return         - True on success, false if the file can't be read or contains invalid data.
 */
bool AbstractDbTable::loadCSV(const std::string& filename) {
    std::ifstream in(filename); // Open file for reading

    if (!in.is_open()) {
        return false; // Failed to open file
    }

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line); // Use string stream to parse each line
        movie m;					  // Temporary movie record to populate
        std::string title, director;  // Temp variables to read in string fields
        char comma, quote;			  // Expected punctuation

        // Parse: ID and comma
        if (!(iss >> m.id >> comma) || comma != ',') {
            return false;
        }

        // Parse: quoted title string
        if (!(iss >> quote) || quote != '"' || !std::getline(iss, title, '"')) {
            return false;
        }

        // Expect comma after title
        if (!(iss >> comma) || comma != ',') {
            return false;
        }

        // Parse: Year and comma
        if (!(iss >> m.year >> comma) || comma != ',') {
            return false;
        }

        // Parse: quoted director string
        if (!(iss >> quote) || quote != '"' || !std::getline(iss, director, '"')) {
            return false;
        }

        // Copy parsed strings into fixed-size char arrays safely
        std::strncpy(m.title, title.c_str(), sizeof(m.title) - 1);
        m.title[sizeof(m.title) - 1] = '\0';

        std::strncpy(m.director, director.c_str(), sizeof(m.director) - 1);
        m.director[sizeof(m.director) - 1] = '\0';

        // Add the parsed movie to the table using add()
        if (!add(m)) {
            return false; // Fail if adding the movie was unsuccessful (e.g., duplicate ID)
        }
    }

    return true;
}

}
