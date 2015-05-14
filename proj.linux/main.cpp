
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "../Classes/AppDelegate.h"

using namespace cocos2d;
using namespace neko;

int main(int argc, char **argv)
{
    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
