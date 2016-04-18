#include <iostream>
#include <string>
using namespace std;

class Greeter
{
public:
    Greeter(string message);
    ~Greeter();

    void greet();

private:
    string message;
};

Greeter::Greeter(string message) : message(message)
{
    cout << "Construct: " << message << endl;
    // Constructor code goes here
}

Greeter::~Greeter()
{
    cout << "Destruct: " << message << endl;
    // Destructor code goes here
}

void Greeter::greet() {
    cout << message << endl;
}

int main()
{
    // Static initialization
    Greeter g1("Hello static");
    g1.greet();

    // Dynamic initialization (pointer)
    Greeter* g2 = new Greeter("Hello dynamic");
    g2->greet();
    delete g2;

    return 0;
}
