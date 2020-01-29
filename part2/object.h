// lang::CwC
#pragma once
#include <stdlib.h>
// Reused from warmup 3
class Object {
   public:
    Object(){};
    virtual ~Object(){};
    // Compares o with this list for equality.
    virtual bool equals(Object* o) { return this == o; }
    // Returns the hash code value for this list.
    virtual size_t hash() { return reinterpret_cast<size_t>(this); }
};

// Wrapper for int
class Integer : public Object {
   public:
    int val;

    Integer(int val);
    virtual bool equals(Object* o);
    virtual size_t hash();
};

// Wrapper for float
class Float : public Object {
   public:
    float val;

    Float(float val);
    virtual bool equals(Object* o);
    virtual size_t hash();
};

// Wrapper for bool
class Boolean : public Object {
   public:
    bool val;

    Boolean(bool val);
    virtual bool equals(Object* o);
    virtual size_t hash();
};
