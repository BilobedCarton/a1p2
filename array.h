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

// Resizeable array with amortized appending to end of list and constant
// time retrieval
class IntArray : public Object {
   public:
    // Empty constructor
    IntArray();
    // Deep copy of other array
    IntArray(const IntArray* arr);
    // Clear contents of this before this is freed
    ~IntArray();
    // Returns hash code for this
    size_t hash();
    // Returns true if this equals the other object else false
    bool equals(const Object* obj);
    // Returns number of elements in this
    size_t count();
    // Return the object at the index or null
    int get(size_t idx);
    // Append a copy of the object to the end of this and return this
    IntArray* append(int obj);
    // Return index of object in this or -1 if the object is not contained
    int index(const int obj);
    // Returns true if this contains object else false
    bool contains(const int obj);
    // Appends a copy of all items of the other array to this and returns this
    IntArray* extend(const IntArray* arr);
    // Insert a copy of the object at the index if index from [0, this->count()]
    // and return this
    IntArray* insert(size_t idx, int obj);
    // Return and remove object at the index or return null
    int pop(size_t idx);
    // Removes first occurance of object from this if this contains it and
    // return this
    IntArray* remove(const int obj);
    // Inplace reverse of this and return this
    IntArray* reverse();
    // Delete contents of this
    void clear();
};

// Resizeable array with amortized appending to end of list and constant
// time retrieval
class FloatArray : public Object {
   public:
    // Empty constructor
    FloatArray();
    // Deep copy of other array
    FloatArray(const FloatArray* arr);
    // Clear contents of this before this is freed
    ~FloatArray();
    // Returns hash code for this
    size_t hash();
    // Returns true if this equals the other object else false
    bool equals(const Object* obj);
    // Returns number of elements in this
    size_t count();
    // Return the object at the index or null
    float get(size_t idx);
    // Append a copy of the object to the end of this and return this
    FloatArray* append(float obj);
    // Return index of object in this or -1 if the object is not contained
    int index(const float obj);
    // Returns true if this contains object else false
    bool contains(const float obj);
    // Appends a copy of all items of the other array to this and returns this
    FloatArray* extend(const FloatArray* arr);
    // Insert a copy of the object at the index if index from [0, this->count()]
    // and return this
    FloatArray* insert(size_t idx, float obj);
    // Return and remove object at the index or return null
    float pop(size_t idx);
    // Removes first occurance of object from this if this contains it and
    // return this
    FloatArray* remove(const float obj);
    // Inplace reverse of this and return this
    FloatArray* reverse();
    // Delete contents of this
    void clear();
};

// Resizeable array with amortized appending to end of list and constant
// time retrieval
class BoolArray : public Object {
   public:
    // Empty constructor
    BoolArray();
    // Deep copy of other array
    BoolArray(const BoolArray* arr);
    // Clear contents of this before this is freed
    ~BoolArray();
    // Returns hash code for this
    size_t hash();
    // Returns true if this equals the other object else false
    bool equals(const Object* obj);
    // Returns number of elements in this
    size_t count();
    // Return the object at the index or null
    bool get(size_t idx);
    // Append a copy of the object to the end of this and return this
    BoolArray* append(bool obj);
    // Return index of object in this or -1 if the object is not contained
    int index(const bool obj);
    // Returns true if this contains object else false
    bool contains(const bool obj);
    // Appends a copy of all items of the other array to this and returns this
    BoolArray* extend(const BoolArray* arr);
    // Insert a copy of the object at the index if index from [0, this->count()]
    // and return this
    BoolArray* insert(size_t idx, bool obj);
    // Return and remove object at the index or return null
    bool pop(size_t idx);
    // Removes first occurance of object from this if this contains it and
    // return this
    BoolArray* remove(const bool obj);
    // Inplace reverse of this and return this
    BoolArray* reverse();
    // Delete contents of this
    void clear();
};