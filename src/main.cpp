#include <iostream>
#include "Sandbox.h"

int main(int, char **)
{
    Engine::Log::init();
    LOG_INFO("Application started");

    Sandbox *sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}
