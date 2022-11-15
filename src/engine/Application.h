#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Engine
{
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };
}