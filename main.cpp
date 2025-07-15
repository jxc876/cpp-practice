#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std::string_literals;

// aggregate type
struct Point {
    int x;
    int y;
};

struct Person {
    // struct members are public by default
    const char *name;
    int age;

    // constructor
    // this makes it a non-aggregate
    Person(const char *name, int age): name{name}, age{age} {
        // noop
    }

    // method
    void update_age(int age) {
        this->age = age;
    }
};

class Person2 {
    // class members are private by default
    int age;
    const char *name;

public:
    Person2(const char *name, int age): name{name}, age{age} {
    }

    void Print() const {
        printf("my name is => %s\n", name);
    }
};


int main() {
    std::string my_str2 = "hello world";

    // const Person p{.name = "Mike", .age = 30};
    // printf("p.name is => %s\n", p.name);
    //const Person p = { .name = "Mike", .age = 20 };
    //auto *p2 = new Person2("Mike", 30);
    //auto p2 = Person2{"Mike", 20};
    Person2 p2 = Person2{"Mike", 20};
    p2.Print();

    // when you have a pointer you need * or ->
    // Person2* p_ptr = &p2;
    // (*p_ptr).Print();
    // p_ptr->Print();

    // This is a ref
    const Person2& p_ref = p2;
    p_ref.Print();

    //free(p2);
    // delete p2;
}
