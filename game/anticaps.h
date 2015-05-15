
#ifndef _neko_anticaps_h
#define _neko_anticaps_h

/**
 * CC_PLATFORM* > cc_platform*
 */
#define cc_platform_win32 CC_PLATFORM_WIN32
#define cc_platform_linux CC_PLATFORM_LINUX
#define cc_platform_mac CC_PLATFORM_MAC
#define cc_target_platform CC_TARGET_PLATFORM

/**
 * CC_LOG* > cc_log*
 */
#if (!defined(COCOS2D_DEBUG) || COCOS2D_DEBUG == 0)
	#define cc_log(...) do {} while (0)
	#define cc_loginfo(...) do {} while (0)
	#define cc_logerror(...) do {} while (0)
	#define cc_logwarn(...) do {} while (0)

#elif (COCOS2D_DEBUG == 1)
	#define cc_log(format, ...) cocos2d::log(format, ##__VA_ARGS__)
	#define cc_loginfo(format,...) cocos2d::log(format, ##__VA_ARGS__)
	#define cc_logerror(format,...) do {} while (0)
	#define cc_logwarn(...) __CCLOGWITHFUNCTION(__VA_ARGS__)

#elif (COCOS2D_DEBUG > 1)
	#define cc_log(format, ...) cocos2d::log(format, ##__VA_ARGS__)
	#define cc_loginfo(format,...) cocos2d::log(format, ##__VA_ARGS__)
	#define cc_logerror(format,...) cocos2d::log(format, ##__VA_ARGS__)
	#define cc_logwarn(...) __CCLOGWITHFUNCTION(__VA_ARGS__)
#endif // COCOS2D_DEBUG

/**
 * CC_CALLBACK* > cc_callback*
 */
#define cc_callback0(__selector__,__target__, ...) \
	std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define cc_callback1(__selector__,__target__, ...) \
	std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)
#define cc_callback2(__selector__,__target__, ...) \
	std::bind(&__selector__,__target__, std::placeholders::_1, \
	std::placeholders::_2, ##__VA_ARGS__)
#define cc_callback3(__selector__,__target__, ...) \
	std::bind(&__selector__,__target__, std::placeholders::_1, \
	std::placeholders::_2, std::placeholders::_3, ##__VA_ARGS__)

/**
 * CREATE_FUNC > cc_createfunc
 */
#define cc_createfunc(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}

#endif // _neko_anticaps_h
