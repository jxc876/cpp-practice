#include <cstdio>
#include <boost/scoped_ptr.hpp>

void print_line();

struct Person {
    const char *name;

    explicit Person(const char *name): name{name} {
        printf("Creating Person: %s \n", name);
    }

    ~Person() {
        printf("Deleting Person: %s \n", name);
    }

    void say_hello() const {
        printf("Hello, my name is %s\n", name);
    }
};

// person here cannot be a copy; scoped_ptr deletes it's copy constructor
void say_hello(boost::scoped_ptr<Person> &p) {
    printf("Hello, my name is %s\n", p->name);
}

void processPerson(Person p) {
    p.say_hello();
}


int main() {
    typedef boost::scoped_ptr<Person> PersonSmartPtr;
    printf("A short demo showing Smart Pointers\n");

    // regular behavior
    {
        print_line();
        auto *person = new Person("mike0");
        person->say_hello();
        delete person; // <== requires manual deletion
    }

    // example one
    {
        print_line();
        boost::scoped_ptr<Person> person_ptr = boost::scoped_ptr(new Person("mike1"));
        person_ptr->say_hello();
    } // <== auto deleted here

    // example two, using a typedef alias
    {
        print_line();
        PersonSmartPtr person_ptr(new Person("mike2"));
        person_ptr->say_hello();
    }

    // example three, using auto
    {
        print_line();
        auto person_ptr = boost::scoped_ptr(new Person("mike3"));
        person_ptr->say_hello();
    }

    // example four, passing using a reference (without copying)
    {
        print_line();
        PersonSmartPtr person_ptr(new Person("mike4"));
        say_hello(person_ptr); // used without copying, passed as reference
    }

    // example 5, swapping
    {
        print_line();
        boost::scoped_ptr<Person> person_ptr1 = boost::scoped_ptr(new Person("mike5A"));
        boost::scoped_ptr<Person> person_ptr2 = boost::scoped_ptr(new Person("mike5B"));
        person_ptr1.swap(person_ptr2); // exchange dynamic objects
        person_ptr1->say_hello(); // Hello, my name is mike5B
        person_ptr2->say_hello(); // Hello, my name is mike5A
    }

    print_line();
    printf("Done\n");
}

void print_line() {
    printf("----------\n");
}