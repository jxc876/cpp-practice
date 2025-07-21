struct Example {
    Example(int x) { }
};

struct ExplicitExample {
    explicit ExplicitExample(int x) { }
};

void narrowing_conversions() {
    constexpr double PI = 3.14;

    // Will compile but "Parentheses Initialization" silently truncate double to int
    Example e1(PI); // > Warning: Narrowing conversion from 'double' to 'int'

    // Error: won't compile, "Brace Initialization" prevents narrowing
    //Example e2{d}; // > Error: Cannot convert double to parameter type int: narrowing conversion
}

void explicit_constructor() {
    Example p6 = 7.0; // implicit conversion (the constructor is called)
    //ExplicitExample ex = 7; // "explicit" prevents it
}

int main() {
    narrowing_conversions();
    explicit_constructor();
}