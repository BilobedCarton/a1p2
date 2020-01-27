// lang::CwC
#pragma once
#include <cstddef>
#include "object.h"
// String extends Object so Array supports String

// Resizeable array with amortized appending to end of list and constant 
// time retrieval
class Array : public Object {
   public:
    // Empty constructor
    Array();
    // Deep copy of other array
    Array(const Array* arr);
    // Clear contents of this before this is freed
    ~Array();
    // Returns hash code for this
    size_t hash();
    // Returns true if this equals the other object else false
    bool equals(const Object* obj);
    // Returns number of elements in this
    size_t count();
    // Return the object at the index or null
    Object* get(size_t idx);
    // Append a copy of the object to the end of this and return this
    Array* append(Object* obj);
    // Return index of object in this or -1 if the object is not contained
    int index(const Object* obj);
    // Returns true if this contains object else false
    bool contains(const Object* obj);
    // Appends a copy of all items of the other array to this and returns this
    Array* extend(const Array* arr);
    // Insert a copy of the object at the index if index from [0, this->count()] and return this
    Array* insert(size_t idx, Object* obj);
    // Return and remove object at the index or return null
    Object* pop(size_t idx);
    // Removes first occurance of object from this if this contains it and
    // return this
    Array* remove(const Object* obj);
    // Inplace reverse of this and return this
    Array* reverse();
    // Delete contents of this
    void clear();
};
