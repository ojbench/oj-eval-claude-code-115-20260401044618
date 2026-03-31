#include "src.hpp"
#include <iostream>

using namespace sjtu;

struct TestClass {
    int value;
    TestClass(int v) : value(v) {
        std::cout << "Constructed: " << value << std::endl;
    }
    ~TestClass() {
        std::cout << "Destructed: " << value << std::endl;
    }
};

int main() {
    std::cout << "Test 1: Basic construction and destruction" << std::endl;
    {
        unique_ptr<int> p1;
        std::cout << "Empty pointer: " << (p1.get() == nullptr ? "nullptr" : "not null") << std::endl;

        unique_ptr<int> p2(new int(42));
        std::cout << "Value: " << *p2 << std::endl;
    }

    std::cout << "\nTest 2: Move constructor" << std::endl;
    {
        unique_ptr<int> p1(new int(100));
        std::cout << "p1 value: " << *p1 << std::endl;

        unique_ptr<int> p2(std::move(p1));
        std::cout << "After move, p1 is: " << (p1.get() == nullptr ? "nullptr" : "not null") << std::endl;
        std::cout << "p2 value: " << *p2 << std::endl;
    }

    std::cout << "\nTest 3: Move assignment" << std::endl;
    {
        unique_ptr<int> p1(new int(200));
        unique_ptr<int> p2(new int(300));

        std::cout << "Before assignment - p1: " << *p1 << ", p2: " << *p2 << std::endl;
        p2 = std::move(p1);
        std::cout << "After assignment - p1 is: " << (p1.get() == nullptr ? "nullptr" : "not null") << std::endl;
        std::cout << "p2 value: " << *p2 << std::endl;
    }

    std::cout << "\nTest 4: Reset" << std::endl;
    {
        unique_ptr<int> p(new int(400));
        std::cout << "Before reset: " << *p << std::endl;
        p.reset();
        std::cout << "After reset: " << (p.get() == nullptr ? "nullptr" : "not null") << std::endl;
    }

    std::cout << "\nTest 5: Release" << std::endl;
    {
        unique_ptr<int> p(new int(500));
        int *raw = p.release();
        std::cout << "After release, p is: " << (p.get() == nullptr ? "nullptr" : "not null") << std::endl;
        std::cout << "Raw pointer value: " << *raw << std::endl;
        delete raw; // Manually delete since we released ownership
    }

    std::cout << "\nTest 6: make_unique" << std::endl;
    {
        auto p = make_unique<int>(600);
        std::cout << "make_unique value: " << *p << std::endl;
    }

    std::cout << "\nTest 7: Custom class" << std::endl;
    {
        unique_ptr<TestClass> p(new TestClass(777));
        std::cout << "Accessing via ->: " << p->value << std::endl;
    }

    std::cout << "\nTest 8: sizeof check" << std::endl;
    std::cout << "sizeof(unique_ptr<int>): " << sizeof(unique_ptr<int>) << std::endl;
    std::cout << "sizeof(void*): " << sizeof(void*) << std::endl;
    std::cout << "Check passed: " << (sizeof(unique_ptr<int>) <= sizeof(void*) ? "YES" : "NO") << std::endl;

    std::cout << "\nAll tests completed!" << std::endl;
    return 0;
}
