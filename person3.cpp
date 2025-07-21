struct Person {
    const char *name;
};

void parenthesesInitialization() {
    Person mike("mike"); // parentheses initialization
}

void braceInitialization() {
    Person mike{"mike"}; // brace/uniform initialization (C11)
}

void stackVsHeadObject() {
    // creates a Person object on the stack
    Person mike{"mike4"}; // scoped to method, auto deleted

    // creates a Person object on the heap
    const Person *p5 = new Person("mike"); // NEW keyword
    delete p5; // requires manual deletion or memory leaks
}

int main() {
    parenthesesInitialization();
    braceInitialization();
    stackVsHeadObject();
}