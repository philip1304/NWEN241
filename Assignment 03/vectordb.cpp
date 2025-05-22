/**
 * vectordb.cpp
 * C++ source file that should contain implementation for member functions
 * - rows()
 * - get()
 * - add()
 * - update()
 * - remove()
 * 
 * You need to modify this file to implement the above-mentioned member functions
 * as specified in the hand-out (Task 3)
 */ 

#include "vectordb.hpp"

namespace nwen {

VectorDbTable::VectorDbTable() {
    // Constructor – nothing special needed here for now
}

/**
 * Returns the number of rows (movie records) currently stored in the table.
 * 
 * @return - The number of entries in the table vector.
 */
int VectorDbTable::rows() const {
    return table.size();
}

/**
 * Retrieves a pointer to the movie at the specified row index.
 * 
 * @param row - The index of the row to retrieve.
 * @return    - A const pointer to the movie at the specified index,
 * 			    or nullptr if the index is out of bounds.
 */
const movie* VectorDbTable::get(int row) const {
    if (row < 0 || row >= static_cast<int>(table.size())) {
        return nullptr; // Out-of-bounds check
    }
    return &table[row]; // Return address of the movie at the given index
}

/**
 * Adds a new movie record to the table.
 * 
 * If a record with the same ID already exists, the function will return false
 * and the new record will not be inserted.
 * 
 * @param m - The movie record to insert.
 * @return  - True if the record was successfully inserted, false otherwise.
 */
bool VectorDbTable::add(const movie& m) {
    if (findIndexById(m.id) != -1) {
        return false; // ID already exists
    }
    table.push_back(m);
    return true;
}

/**
 * Updates an existing movie record identified by its ID.
 * 
 * Replaces the current movie record with the one provided if the ID exists.
 * 
 * @param id - The ID of the movie to update.
 * @param m  - The new movie data to replace the old record.
 * @return   - True if the update was successful, false otherwise.
 */
bool VectorDbTable::update(unsigned long id, const movie& m) {
    int index = findIndexById(id);
    if (index == -1) {
        return false; // Not found
    }
    table[index] = m;
    return true;
}

/**
 * Removes a movie record from the table using its ID.
 * 
 * If a record with the specified ID is found, it is removed from the table.
 * 
 * @param id - The ID of the movie to remove.
 * @return   - True if the record was removed, false otherwise.
 */
bool VectorDbTable::remove(unsigned long id) {
    int index = findIndexById(id);
    if (index == -1) {
        return false;
    }
    table.erase(table.begin() + index);
    return true;
}

/**
 * Helper function to find the index of a movie by its ID.
 * 
 * Iterates through the table to locate the index of the movie with the specified ID.
 * 
 * @param id - The ID of the movie to find.
 * @return   - The index of the movie in the table if found, otherwise -1.
 */
int VectorDbTable::findIndexById(unsigned long id) const {
    for (int i = 0; i < static_cast<int>(table.size()); ++i) {
        if (table[i].id == id) {
            return i;
        }
    }
    return -1;
}

}
