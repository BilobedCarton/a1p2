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