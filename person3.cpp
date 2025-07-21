struct Person {
    const char *name;
};

void parenthesesInitialization() {
    Person mike("mike"); // parentheses initialization
}

void braceInitialization() {
    // Provides protection against narrowing conversions
    // Considered more consistent across different initialization scenarios
    // Commonly used when invoking constructor
    // Generally preferred in modern C++ for its consistency and safety features
    Person mike{"mike"}; // brace/uniform initialization (C11)
}

void designatedInitializer() {
    // Designated initializer with brace initialization (C20)
    // Typically used with aggregate types
    // Explicit about which member is being initialized
    Person mike = {.name = "Mike"}; // specifies which member is initialized
}

void stackVsHeapObject() {
    // creates a Person object on the stack
    Person mike{"mike4"}; // scoped to method, auto deleted

    // creates a Person object on the heap
    const Person *p5 = new Person("mike"); // NEW keyword
    delete p5; // requires manual deletion or memory leaks
}

int main() {
    parenthesesInitialization();
    braceInitialization();
    designatedInitializer();
    stackVsHeapObject();
}