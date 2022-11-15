#include <iostream>
#include "./sandbox/Sandbox.cpp"

int main(int, char **)
{
    Engine::Log::init();
    LOG_INFO("Application started");

    Sandbox *sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
