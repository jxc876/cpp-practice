#include <cstdio>
#include <boost/scoped_ptr.hpp>

int main() {
    printf("Creating Smart Pointer\n");
    boost::scoped_ptr<int> my_smart_ptr = boost::scoped_ptr<int>(new int(10));
    printf("Smart Pointer was created\n");
}
