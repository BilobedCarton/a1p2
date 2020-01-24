// lang::CwC
#pragma once
#include <stdlib.h>
#include <string.h>
#include "object.h"
// Reused from warmup 3
class String : public Object {
   public:
    char* str;

    String(const char* str) {
        size_t new_len = strlen(str) + 1;
        this->str = new char[new_len];
        strcpy(this->str, str);
        this->str[new_len - 1] = '\0';
    }

    ~String() { delete[] this->str; }

    String* concat(String* other) {
        size_t new_len = strlen(this->str) + strlen(other->str) + 1;
        char* new_str = new char[new_len];
        strcpy(new_str, this->str);
        strcat(new_str, other->str);
        new_str[new_len - 1] = '\0';
        String* new_str_container = new String(new_str);
        delete[] new_str;
        return new_str_container;
    }

    bool equals(Object* o) {
        if (this == o) return true;
        String* that = dynamic_cast<String*>(o);
        if (that == nullptr) {
            return false;
        } else {
            return strcmp(this->str, that->str) == 0;
        }
    }

    size_t hash() { return strlen(this->str); }
    int cmp(String* other) { return strcmp(this->str, other->str); }
};