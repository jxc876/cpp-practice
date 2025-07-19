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

    print_line();
    printf("Done\n");
}

void print_line() {
    printf("----------\n");
}