// lang::CwC
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

int main() {
    // constructor
    String* t1 = new String("t1");
    String* t2 = new String("t2");
    String* a = new String("a");
    String* b = new String("b");
    Object* a_obj = new String("a");

    Array* empty = new Array();
    Array* a1_str = (new Array())->append(a);
    Array* a1_obj = (new Array())->append(a_obj);
    Array* a3 = (new Array())->append(a)->append(b)->append(a_obj);
    // Copy constructor
    Array* a4 = (new Array(a3))->append(b);
    Array* a7 = new Array();
    Array* temp_a = new Array();

    // hash
    t_true(empty->hash() == 0);
    t_true(a1_str->hash() == a->hash());
    t_true(a3->hash() == a->hash() + b->hash() + a_obj->hash());

    // equals
    t_false(empty->equals(a));
    t_false(empty->equals(a_obj));
    t_false(empty->equals(a1_str));
    t_false(empty->equals(a1_obj));
    t_true(a1_str->equals(a1_obj));
    t_false(a1_str->equals(a3));

    // count
    t_true(empty->count() == 0);
    t_true(a1_str->count() == 1);
    t_true(a1_obj->count() == 1);
    t_true(a3->count() == 3);

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

    // index
    t_true(empty->index(a) == -1);
    t_true(a1_str->index(a) == 0);
    t_true(a1_str->index(b) == -1);
    t_true(a3->index(a) == 0);
    t_true(a3->index(b) == 1);
    t_true(a3->index(a_obj) == 2);

    // contains
    t_false(empty->contains(a));
    t_true(a1_str->contains(a));
    t_false(a1_str->contains(b));
    t_true(a3->contains(a));
    t_true(a3->contains(b));
    t_true(a3->contains(a_obj));

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

    // pop
    t_true(a7->pop(0)->equals(t2));
    t_true(a7->pop(0)->equals(t1));
    t_true(a7->count() == 7);

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

    // reverse
    temp_a->extend(a7);
    t_true(a7->equals(temp_a));
    temp_a->reverse()->reverse();
    t_true(a7->equals(temp_a));
    temp_a->reverse();
    for (size_t i = 0; i < a7->count(); i++) {
        t_true(a7->get(i)->equals(temp_a->get(a7->count() - i)));
    }
    t_true(temp_a->count() == 7);

    // clear
    empty->clear();
    t_true(empty->count() == 0);
    temp_a->clear();
    t_true(temp_a->count() == 0);

    // deconstructor
    delete temp_a;
    delete a4;
    delete a3;
    delete a1_obj;
    delete a1_str;
    delete empty;
    delete a_obj;
    delete b;
    delete a;
    delete t2;
    delete t1;
    OK("Array");
    return 0;
}
