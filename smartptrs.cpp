#include <cstdio>
#include <boost/scoped_ptr.hpp>

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
    printf("Demo of Smart Pointers\n");
    printf("-----------\n");

    // regular behavior
    {
        auto *person = new Person("mike0");
        person->say_hello();
        delete person; // <== requires manual deletion
    }

    // example one
    {
        boost::scoped_ptr<Person> person_ptr = boost::scoped_ptr(new Person("mike1"));
        person_ptr->say_hello();
    } // <== auto deleted here

    printf("-----------\n");

    // example two, using a typedef alias
    {
        PersonSmartPtr person_ptr(new Person("mike2"));
        person_ptr->say_hello();
    }

    printf("-----------\n");


    // example three, using auto
    {
        auto person_ptr = boost::scoped_ptr(new Person("mike3"));
        person_ptr->say_hello();
    }

    printf("-----------\n");
    printf("Done\n");
}
