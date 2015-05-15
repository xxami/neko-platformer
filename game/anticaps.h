
#ifndef _NEKO_ANTICAPS_H_
#define _NEKO_ANTICAPS_H_

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

#endif // _NEKO_ANTICAPS_H
