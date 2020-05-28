
#include "imgui.h"

class CDebug
{
public:
    static void ImguiInitialise();
    static void ImguiLoop();
    static void CDebug::ImguiDestroy();
    static ImGuiIO* io;
};
