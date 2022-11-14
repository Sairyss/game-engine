#include <iostream>
#include "./sandbox/Sandbox.cpp"

int main(int, char **)
{
    std::cout << "Hello, world!\n";
    Sandbox *sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
