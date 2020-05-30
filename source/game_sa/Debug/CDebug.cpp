#include "StdInc.h"

#include <windows.h>

int CDebug::counter = 0;

void CDebug::InjectHooks()
{
    HookInstall(0x532260, CDebug::DebugDisplayTextBuffer, 7);
}

// It gets called from address 0x53E920 (Idle in compact idb)
void CDebug::DebugDisplayTextBuffer()
{
    // Literally empty function. No need for original function call even.
    ImguiLoop();
}

// Here begins the Imgui section

// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
//bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
//void ResetDevice();

LRESULT CALLBACK DebugWindowCallback(HWND handleforwindow1, UINT message, WPARAM wParam, LPARAM lParam);

bool window1closed = false;

ImGuiIO* CDebug::io = {};
HWND handleForDebugWindow;
WNDCLASSEX imguiWindow;

void CDebug::ImguiInitialise()
{
    //create imgui window

    ZeroMemory(&imguiWindow, sizeof(WNDCLASSEX));
    imguiWindow.cbClsExtra = NULL;
    imguiWindow.cbSize = sizeof(WNDCLASSEX);
    imguiWindow.cbWndExtra = NULL;
    imguiWindow.hbrBackground = (HBRUSH)COLOR_WINDOW;
    imguiWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
    imguiWindow.hIcon = NULL;
    imguiWindow.hIconSm = NULL;
    imguiWindow.hInstance = NULL;
    imguiWindow.lpfnWndProc = (WNDPROC)DebugWindowCallback;
    imguiWindow.lpszClassName = "Debug Window";
    imguiWindow.lpszMenuName = NULL;
    imguiWindow.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&imguiWindow))
    {
        int nResult = GetLastError();
        MessageBox(NULL,
            "Window class creation failed",
            "Window Class Failed",
            MB_ICONERROR);
    }

        handleForDebugWindow = CreateWindowEx(NULL,
        imguiWindow.lpszClassName,
        "Debug Window",
        WS_OVERLAPPEDWINDOW,
        200,
        150,
        640,
        480,
        NULL,
        NULL,
        NULL,
        NULL                /* No Window Creation data */
        );

    if (!handleForDebugWindow)
    {
        int nResult = GetLastError();

        MessageBox(NULL,
            "Window creation failed",
            "Window Creation Failed",
            MB_ICONERROR);
    }

    // Initialize Direct3D
    /*if (!CreateDeviceD3D(handleForDebugWindow))
    {
        CleanupDeviceD3D();
        UnregisterClass(imguiWindow.lpszClassName, imguiWindow.hInstance);
        printf("D3D device initialization failed for imgui debug window\n");
        return;
    }*/

    ShowWindow(handleForDebugWindow, SW_SHOWDEFAULT);
    //ShowWindow(handleForDebugWindow, 1);
    UpdateWindow(handleForDebugWindow);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO();
    io->DisplaySize = ImVec2(640, 480);

    // Build atlas
    unsigned char* tex_pixels = NULL;
    int tex_w, tex_h;
    io->Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(handleForDebugWindow);
    //ImGui_ImplDX9_Init(g_pd3dDevice);
}

//bool CreateDeviceD3D(HWND hWnd)
//{
//    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
//        return false;
//
//    // Create the D3DDevice
//    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
//    g_d3dpp.Windowed = TRUE;
//    g_d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
//    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
//    g_d3dpp.EnableAutoDepthStencil = TRUE;
//    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
//    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
//    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
//    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
//        return false;
//
//    return true;
//}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK DebugWindowCallback(HWND handleforwindow, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY: {
        MessageBox(NULL,
            "Debug window closed",
            "Message",
            MB_ICONINFORMATION);

        window1closed = true;
        return 0;
    }
                   break;
    }

    return DefWindowProc(handleforwindow, msg, wParam, lParam);
}

void CDebug::ImguiLoop()
{
    counter++;
    printf("NewFrame() called %d times\n", counter);
    io->DeltaTime = 1.0f / 60.0f;
    ImGui::NewFrame();

    static float f = 0.0f;
    ImGui::Text("Hello, world!");
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);
    //ImGui::ShowDemoWindow(NULL);

    ImGui::Render();
}

void CDebug::ImguiDestroy()
{
    printf("DestroyContext()\n");
    ImGui::DestroyContext();
    DestroyWindow(handleForDebugWindow);
    UnregisterClass(imguiWindow.lpszClassName, imguiWindow.hInstance);
}
