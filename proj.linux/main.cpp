
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

#include "../game/init.h"

using namespace cocos2d;
using namespace neko;

int main(int argc, char **argv)
{
    NekoPlatformer game;
    return Application::getInstance()->run();
}
