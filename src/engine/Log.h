#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory.h>

namespace Engine
{
  class Log
  {
  public:
    static void init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}

#define LOG_CORE_FATAL(...) ::Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_WARN(...) ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_INFO(...) ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_TRACE(...) ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define LOG_FATAL(...) ::Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define LOG_ERROR(...) ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_WARN(...) ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...) ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...) ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)