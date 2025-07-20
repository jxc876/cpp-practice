#include <iostream>

struct Person {
    char name[50]{};

    // Constructor with string parameter
    explicit Person(const char* n) {
        strncpy(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';  // null terminate
    }

    // Copy constructor
    Person(const Person& other) {
        printf("Copy Constructor Invoked ***\n");
        strncpy(name, other.name, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';  // null terminate
    }

};

void greet(Person p) {
    printf("Hello, my name is %s \n", p.name);
}

/**
 * Demonstrates Copy Constructors.
 * -----
 * A copy constructor gets invoked when passed by value.
 */
int main() {
    Person p1("mike");
    greet(p1); // Copy constructor called

    Person p2 = p1; // Copy constructor called
    Person p3(p1);   // Copy constructor called
}
