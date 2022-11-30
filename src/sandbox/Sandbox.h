#pragma once

#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate(Engine::Timestep ts) override
  {
    // LOG_DEBUG("ExampleLayer::Update");
  }

  void OnEvent(Engine::Event &e) override
  {
    LOG_DEBUG("[Example Layer] {0}", e.ToString());
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
