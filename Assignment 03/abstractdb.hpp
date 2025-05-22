/**
 * abstractdb.hpp
 * C++ header file that should contain declaration for
 * - struct movie (given)
 * - AbstractDbTable abstract class
 * 
 * You need to modify this file to declare AbstractDbTable abstract class 
 * as specified in the hand-out (Task 1)
 */ 



#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include <string>

namespace nwen 
{
    struct movie {
        unsigned long id;
        char title[50];
        unsigned short year;
        char director[50];
    };

    /**
 * @class - AbstractDbTable
 * @brief - Abstract interface for a database table that stores movie records.
 * 
 * This abstract class defines the interface for all database table implementations,
 * including methods for adding, updating, retrieving, and removing records,
 * as well as loading from and saving to CSV files.
 */
class AbstractDbTable {
public:
    /**
     * @brief - Virtual destructor to allow proper cleanup in derived classes.
     */
    virtual ~AbstractDbTable() {}


    /**
     * @brief  - Returns the number of records currently in the table.
     * @return - An integer indicating the number of rows.
     */
    virtual int rows() const = 0;

    /**
     * @brief     - Retrieves a pointer to the movie at the specified row index.
     * @param row - The row number to retrieve.
     * @return    - A pointer to the movie at the given index, or nullptr if valid.
     */
    virtual const movie* get(int row) const = 0;

    /**
     * @brief   - Adds a new movie to the table.
     * @param m - The movie record to add.
     * @return  - True if the movie was successfully added, false otherwise.
     */
    virtual bool add(const movie& m) = 0;

    /**
     * @brief    - Updates an existing movie in the table by ID.
     * @param id - The ID of the movie to update.
     * @param m  - The new movie data to update.
     * @return   - True if the udpate was successful, false otherwise.
     */
    virtual bool update(unsigned long id, const movie& m) = 0;

    /**
     * @brief    - Removes a movie from the table using its ID.
     * @param id - The ID of the movie to remove.
     * @return   - True of the movie was successfully removed, false otherwise. 
     */
    virtual bool remove(unsigned long id) = 0;

    /**
     * @brief          - Loads movie records from a CSV file into the table.
     * @param filename - The name of the CSV file to load.
     * @return         - True if the file was loaded successfully, false otherwise.
     */
    virtual bool loadCSV(const std::string& filename);

    /**
     * @brief          - Saves the current table contents to a CSV file.
     * @param filename - The name of the CSV file to save to.
     * @return         - True if the file was saved successfully, false otherwise.
     */
    virtual bool saveCSV(const std::string& filename);
};

}

#endif // __ABSTRACT_DB_HPP__
