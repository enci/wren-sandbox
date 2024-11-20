#include <iostream>
#include "wren.hpp"

extern "C" {
    #include "wren_debugger.h"
    #include "wren_vm.h"
}


static void writeFn(WrenVM* vm, const char* text)
{
  printf("%s", text);
}

const char* get_module_path(WrenVM* vm, const char* module, const char* root) 
{
    return NULL;    
}

void errorFn(WrenVM* vm, WrenErrorType errorType,
             const char* module, const int line,
             const char* msg)
{
  switch (errorType)
  {
    case WREN_ERROR_COMPILE:
    {
      printf("[%s line %d] [Error] %s\n", module, line, msg);
    } break;
    case WREN_ERROR_STACK_TRACE:
    {
      printf("[%s line %d] in %s\n", module, line, msg);
    } break;
    case WREN_ERROR_RUNTIME:
    {
      printf("[Runtime Error] %s\n", msg);
    } break;
  }
}

int main()
{
  WrenConfiguration config;
  wrenInitConfiguration(&config);
    config.writeFn = &writeFn;
    config.errorFn = &errorFn;    
    #if WREN_DEBUGGER
      config.modulePathFn = &get_module_path;
      config.debuggerPort = "8080";
      config.enableDebugger = true;
    #endif
  WrenVM* vm = wrenNewVM(&config);

  const char* module = "main";
  const char* script = "System.print(\"I am running in a VM!\")";

  //debuggerAddBreakpoint(&vm->debugger, module, 1);

  wrenDebuggerPollConfigCmds(vm);
  WrenInterpretResult result = wrenInterpret(vm, module, script);

  switch (result) {
    case WREN_RESULT_COMPILE_ERROR:
      { printf("Compile Error!\n"); } break;
    case WREN_RESULT_RUNTIME_ERROR:
      { printf("Runtime Error!\n"); } break;
    case WREN_RESULT_SUCCESS:
      { printf("Success!\n"); } break;
  }

  wrenFreeVM(vm);
}

