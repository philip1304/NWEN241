/**
 * vectordb.hpp
 * C++ header file that should contain declaration for
 * - VectorDbTable class
 * 
 * You need to modify this file to declare VectorDbTable class 
 * as specified in the hand-out (Task 2)
 */ 

#ifndef VECTORDATABASE_HPP
#define VECTORDATABASE_HPP

#include <vector>
#include "abstractdb.hpp"

namespace nwen {

/**
 * @class - VectorDbTable
 * @brief - Implementation of AbstractDbTable using a std::vector
 * 			to store movie records in memory.
 */
class VectorDbTable : public AbstractDbTable {
public:
    VectorDbTable(); // Constructs an empty VectorDbTable

    /**
     * @brief  - Returns the number of records currently stored in the table.
     * @return - The number of rows.
     */
    int rows() const override;

    /**
     * @brief     - Returns a pointer to a movie record at the given index.
     * @param row - The index of the record to retrieve.
     * @return    - A const pointer to the movie if index is valid, otherwise nullptr.
     */
    const movie* get(int row) const override;

    /**
     * @brief   - Adds a new movie to the table.
     * @param m - The movie record to add.
     * @return  - True if the movie was added successfully, false if the ID already exists.
     */
    bool add(const movie& m) override;

    /**
     * @brief    - Updates an existing movie record by ID.
     * @param id - The ID of the movie to update.
     * @param m  - The new movie record to replace the old one.
     * @return   - True if the update was successful, false otherwise.
     */
    bool update(unsigned long id, const movie& m) override;

    /**
     * @brief    - Removes a movie record by ID.
     * @param id - The ID fo the movie to remove.
     * @return   - True if the removal was successful, false otherwise.
     */
    bool remove(unsigned long id) override;

private:
    std::vector<movie> table; // Stores the movie records

    /**
     * @brief    - Finds the index of a movie by its ID.
     * @param id - The movie ID to search for.
     * @return   - The index of the movie in the vector, or -1 if not found.
     */
    int findIndexById(unsigned long id) const;
};

}

#endif // VECTORDATABASE_HPP
