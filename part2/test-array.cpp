// lang::C++
#include <iostream>
#include "array.h"
#include "string.h"

void FAIL() { exit(1); }
void OK(const char* m) { std::cout << "OK: " << m << std::endl; }
void t_true(bool p) {
    if (!p) FAIL();
}
void t_false(bool p) {
    if (p) FAIL();
}

template <class ArrayType, class ContainedType>
void test(ContainedType t1, ContainedType t2, ContainedType a, ContainedType b,
          ContainedType a_obj) {
    ArrayType* empty = new ArrayType();
    ArrayType* a1_str = (new ArrayType())->append(a);
    ArrayType* a1_obj = (new ArrayType())->append(a_obj);
    ArrayType* a3 = (new ArrayType())->append(a)->append(b)->append(a_obj);
    // Copy constructor
    ArrayType* a4 = (new ArrayType(a3))->append(b);
    ArrayType* a7 = new ArrayType();
    ArrayType* temp_a = new ArrayType();

    // hash
    t_true(empty->hash() == 0);
    t_false(a1_str->hash() == a->hash());
    t_true(a1_str->hash() == a1_obj->hash());
    OK("Hash tests passed");

    // equals
    t_false(empty->equals(a));
    t_false(empty->equals(a_obj));
    t_false(empty->equals(a1_str));
    t_false(empty->equals(a1_obj));
    t_true(a1_str->equals(a1_obj));
    t_false(a1_str->equals(a3));
    OK("Equals tests passed");

    // count
    t_true(empty->count() == 0);
    t_true(a1_str->count() == 1);
    t_true(a1_obj->count() == 1);
    t_true(a3->count() == 3);
    OK("Count tests passed");

    // get, append
    t_true(empty->get(0) == nullptr);
    t_true(empty->get(1) == nullptr);
    t_false(a1_str->get(0) == a);
    t_true(a1_str->get(0)->equals(a));
    t_true(a1_str->get(1) == nullptr);
    t_true(a3->get(0)->equals(a));
    t_true(a3->get(1)->equals(b));
    t_true(a3->get(2)->equals(a_obj));
    t_true(a3->get(3) == nullptr);
    t_false(a4->get(0)->equals(a));
    t_false(a4->get(1)->equals(b));
    t_false(a4->get(2)->equals(a_obj));
    t_true(a4->get(0)->equals(a));
    t_true(a4->get(1)->equals(b));
    t_true(a4->get(2)->equals(a_obj));
    t_true(a4->get(3)->equals(b));
    OK("Get and append tests passed");

    // index
    t_true(empty->index(a) == -1);
    t_true(a1_str->index(a) == 0);
    t_true(a1_str->index(b) == -1);
    t_true(a3->index(a) == 0);
    t_true(a3->index(b) == 1);
    t_true(a3->index(a_obj) == 2);
    OK("Index tests passed");

    // contains
    t_false(empty->contains(a));
    t_true(a1_str->contains(a));
    t_false(a1_str->contains(b));
    t_true(a3->contains(a));
    t_true(a3->contains(b));
    t_true(a3->contains(a_obj));
    OK("Contains tests passed");

    // extend
    t_true(a7->count() == 0);
    t_true(a7->extend(a3)->count() == 3);
    t_true(a7->extend(a4)->count() == 7);
    t_true(a7->get(0)->equals(a));
    t_true(a7->get(1)->equals(b));
    t_true(a7->get(2)->equals(a_obj));
    t_true(a7->get(3)->equals(a));
    t_true(a7->get(4)->equals(b));
    t_true(a7->get(5)->equals(a_obj));
    t_true(a7->get(6)->equals(b));
    OK("Extend tests passed");

    // insert
    t_true(a7->count() == 7);
    a7->insert(0, t1)->insert(0, t2);
    t_true(a7->get(0)->equals(t2));
    t_true(a7->get(1)->equals(t1));
    t_true(a7->count() == 9);
    a7->insert(a7->count(), t1);
    t_true(a7->get(a7->count() - 1)->equals(t1));
    t_true(a7->count() == 10);
    t_true(a7->pop(a7->count() - 1)->equals(t1));
    t_true(a7->count() == 9);
    a7->insert(a7->count() * 2, t1);
    t_true(a7->count() == 9);
    OK("Insert tests passed");

    // pop
    t_true(a7->pop(0)->equals(t2));
    t_true(a7->pop(0)->equals(t1));
    t_true(a7->count() == 7);
    OK("Pop tests passed");

    // remove
    t_true(a7->remove(t1)->count() == 7);
    a7->insert(2, t1)->insert(5, t2);
    t_true(a7->count() == 9);
    a7->remove(t2);
    t_false(a7->get(5)->equals(t2));
    t_true(a7->count() == 8);
    a7->remove(t1);
    t_false(a7->get(2)->equals(t1));
    t_true(a7->count() == 7);
    OK("Remove tests passed");

    // reverse
    temp_a->extend(a7);
    t_true(a7->equals(temp_a));
    temp_a->reverse()->reverse();
    t_true(a7->equals(temp_a));
    temp_a->reverse();
    for (size_t i = 0; i < a7->count(); i++) {
        t_true(a7->get(i)->equals(temp_a->get(a7->count() - i - 1)));
    }
    t_true(temp_a->count() == 7);
    OK("Reverse tests passed");

    // clear
    empty->clear();
    t_true(empty->count() == 0);
    temp_a->clear();
    t_true(temp_a->count() == 0);
    OK("Clear tests passed");

    // deconstructor
    delete empty;
    delete a1_str;
    delete a1_obj;
    delete a3;
    delete a4;
    delete a7;
    delete temp_a;
    
}

template <class ArrayType, class ContainedType>
void test_primitive(ContainedType t1, ContainedType t2, ContainedType a, ContainedType b,
          ContainedType a_obj, ContainedType defaultValue) {
    ArrayType* empty = new ArrayType();
    ArrayType* a1_str = (new ArrayType())->append(a);
    ArrayType* a1_obj = (new ArrayType())->append(a_obj);
    ArrayType* a3 = (new ArrayType())->append(a)->append(b)->append(a_obj);
    // Copy constructor
    ArrayType* a4 = (new ArrayType(a3))->append(b);
    ArrayType* a7 = new ArrayType();
    ArrayType* temp_a = new ArrayType();

    // hash
    t_true(empty->hash() == 0);
    t_false(a1_str->hash() == a);
    t_true(a1_str->hash() == a1_obj->hash());
    OK("Hash tests passed");

    // equals
    t_false(empty->equals(a1_str));
    t_false(empty->equals(a1_obj));
    t_true(a1_str->equals(a1_obj));
    t_false(a1_str->equals(a3));
    OK("Equals tests passed");

    // count
    t_true(empty->count() == 0);
    t_true(a1_str->count() == 1);
    t_true(a1_obj->count() == 1);
    t_true(a3->count() == 3);
    OK("Count tests passed");

    // get, append
    t_true(empty->get(0) == defaultValue);
    t_true(empty->get(1) == defaultValue);
    t_false(a1_str->get(0) == a);
    t_true(a1_str->get(0) == a);
    t_true(a1_str->get(1) == defaultValue);
    t_true(a3->get(0) == a);
    t_true(a3->get(1) == b);
    t_true(a3->get(2) == a_obj);
    t_true(a3->get(3) == defaultValue);
    t_false(a4->get(0) == a);
    t_false(a4->get(1) == b);
    t_false(a4->get(2) == a_obj);
    t_true(a4->get(0) == a);
    t_true(a4->get(1) == b);
    t_true(a4->get(2) == a_obj);
    t_true(a4->get(3) == b);
    OK("Get and append tests passed");

    // index
    t_true(empty->index(a) == -1);
    t_true(a1_str->index(a) == 0);
    t_true(a1_str->index(b) == -1);
    t_true(a3->index(a) == 0);
    t_true(a3->index(b) == 1);
    t_true(a3->index(a_obj) == 2);
    OK("Index tests passed");

    // contains
    t_false(empty->contains(a));
    t_true(a1_str->contains(a));
    t_false(a1_str->contains(b));
    t_true(a3->contains(a));
    t_true(a3->contains(b));
    t_true(a3->contains(a_obj));
    OK("Contains tests passed");

    // extend
    t_true(a7->count() == 0);
    t_true(a7->extend(a3)->count() == 3);
    t_true(a7->extend(a4)->count() == 7);
    t_true(a7->get(0) == a);
    t_true(a7->get(1) == b);
    t_true(a7->get(2) == a_obj);
    t_true(a7->get(3) == a);
    t_true(a7->get(4) == b);
    t_true(a7->get(5) == a_obj);
    t_true(a7->get(6) == b);
    OK("Extend tests passed");

    // insert
    t_true(a7->count() == 7);
    a7->insert(0, t1)->insert(0, t2);
    t_true(a7->get(0) == t2);
    t_true(a7->get(1) == t1);
    t_true(a7->count() == 9);
    a7->insert(a7->count(), t1);
    t_true(a7->get(a7->count() - 1) == t1);
    t_true(a7->count() == 10);
    t_true(a7->pop(a7->count() - 1) == t1);
    t_true(a7->count() == 9);
    a7->insert(a7->count() * 2, t1);
    t_true(a7->count() == 9);
    OK("Insert tests passed");

    // pop
    t_true(a7->pop(0) == t2);
    t_true(a7->pop(0) == t1);
    t_true(a7->count() == 7);
    OK("Pop tests passed");

    // remove
    t_true(a7->remove(t1)->count() == 7);
    a7->insert(2, t1)->insert(5, t2);
    t_true(a7->count() == 9);
    a7->remove(t2);
    t_false(a7->get(5) == t2);
    t_true(a7->count() == 8);
    a7->remove(t1);
    t_false(a7->get(2) == t1);
    t_true(a7->count() == 7);
    OK("Remove tests passed");

    // reverse
    temp_a->extend(a7);
    t_true(a7->equals(temp_a));
    temp_a->reverse()->reverse();
    t_true(a7->equals(temp_a));
    temp_a->reverse();
    for (size_t i = 0; i < a7->count(); i++) {
        t_true(a7->get(i) == temp_a->get(a7->count() - i - 1));
    }
    t_true(temp_a->count() == 7);
    OK("Reverse tests passed");

    // clear
    empty->clear();
    t_true(empty->count() == 0);
    temp_a->clear();
    t_true(temp_a->count() == 0);
    OK("Clear tests passed");

    // deconstructor
    delete empty;
    delete a1_str;
    delete a1_obj;
    delete a3;
    delete a4;
    delete a7;
    delete temp_a;
    
}

int main() {
    // Array tests
    String* t1 = new String("t1");
    String* t2 = new String("t2");
    String* a = new String("a");
    String* b = new String("b");
    Object* a_obj = new String("a");

    test<Array, Object*>(t1, t2, a, b, a_obj);

    delete t1;
    delete t2;
    delete a;
    delete b;
    delete a_obj;
    OK("All Array tests passed");

    // IntArray tests
    test_primitive<IntArray, int>(1, 2, 3, 4, 3);
    OK("All IntArray tests passed");

    // FloatArray tests
    test_primitive<FloatArray, float>(1.0, 2.0, 3.0, 4.0, 3.0);
    OK("All FloatArray tests passed");

    // BoolArray tests
    test_primitive<BoolArray, bool>(true, false, false, true, false);
    OK("All BoolArray tests passed");
    OK("All tests passed");
    return 0;
}
