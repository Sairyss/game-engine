#pragma once

#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate(Engine::Timestep ts) override
  {
    // LOG_DEGUG("ExampleLayer::Update");
  }

  void OnEvent(Engine::Event &e) override
  {
    LOG_DEGUG("[Example Layer] {0}", e.ToString());
  }
};

class Sandbox : public Engine::Application
{
public:
  Sandbox()
  {
    PushLayer(new ExampleLayer());
  }
  ~Sandbox() {}
};
