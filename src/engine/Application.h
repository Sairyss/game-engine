#pragma once

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