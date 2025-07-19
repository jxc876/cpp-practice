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
};

int main() {
    typedef boost::scoped_ptr<Person> PersonSmartPtr;
    printf("Demo of Smart Pointers\n");

    // example one
    {
        boost::scoped_ptr<Person> person_ptr = boost::scoped_ptr(new Person("mike1"));
    } // smart pointer deleted here, no need for delete

    // example two, using a typedef alias
    {
        PersonSmartPtr person_ptr(new Person("mike2"));
    }

    // example three, using auto
    {
        auto person_ptr = boost::scoped_ptr(new Person("mike3"));
    }

    printf("Done\n");
}
