
#include "imgui.h"

class CDebug
{
public:
    // Imgui section
    static ImGuiIO* io;
    static int counter;
    static void ImguiInitialise();
    static void ImguiLoop();
    static void ImguiDestroy();

    static void InjectHooks();

    // This is the only debug function we need. It's empty in GTA:SA. This'll work as our debug loop.
    static void DebugDisplayTextBuffer();
};
