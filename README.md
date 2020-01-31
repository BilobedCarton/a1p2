# A1P2 descriptions


## Constructors/Descructors
### Array();
- Empty constructor
### Array(const Array* arr);
- Deep copy of other array
### ~Array();
- Clear contents of this before this is freed


## Inherited methods
### size_t hash();
- Returns hash code for this
### bool equals(const Object* obj);
- Returns true if this equals the other object else false


## Array methods
### size_t count();
- Returns number of elements in this
### Object* get(size_t idx);
- Return the object at the index or null
### Array* append(Object* obj);
- Append a copy of the object to the end of this and return this
### int index(const Object* obj);
- Return index of object in this or -1 if the object is not contained
### bool contains(const Object* obj);
- Returns true if this contains object else false
### Array* extend(const Array* arr);
- Appends a copy of all items of the other array to this and returns this
### Array* insert(size_t idx, Object* obj);
- Insert a copy of the object at the index if index from [0, this->count()] and return this
### Object* pop(size_t idx);
- Return and remove object at the index or return null
### Array* remove(const Object* obj);
- Removes first occurance of object from this if this contains it and return this
### Array* reverse();
- Inplace reverse of this and return this
### void clear();
- Delete contents of this
