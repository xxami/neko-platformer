
#include "main.h"
#include "init.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace neko;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    NekoPlatformer app;
    return Application::getInstance()->run();
}
