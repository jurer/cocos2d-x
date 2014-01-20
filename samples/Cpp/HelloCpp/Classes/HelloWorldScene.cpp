#include "HelloWorldScene.h"
#include "AppMacros.h"
#include <string>
using namespace std;

USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

BOOL WCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr, DWORD dwSize)  
{  
	DWORD dwMinSize;  
	dwMinSize = WideCharToMultiByte(CP_UTF8,NULL,lpcwszStr,-1,NULL,0,NULL,FALSE);  
	if(dwSize < dwMinSize)  
	{  
		return false;  
	}  
	WideCharToMultiByte(CP_UTF8,NULL,lpcwszStr,-1,lpszStr,dwSize,NULL,FALSE);  
	return true;  
}


inline void WStrToUTF8(std::string& dest, const wstring& src){

	dest.clear();

	for (size_t i = 0; i < src.size(); i++){

		wchar_t w = src[i];

		if (w <= 0x7f)

			dest.push_back((char)w);

		else if (w <= 0x7ff){

			dest.push_back(0xc0 | ((w >> 6)& 0x1f));

			dest.push_back(0x80| (w & 0x3f));

		}

		else if (w <= 0xffff){

			dest.push_back(0xe0 | ((w >> 12)& 0x0f));

			dest.push_back(0x80| ((w >> 6) & 0x3f));

			dest.push_back(0x80| (w & 0x3f));

		}

		else if (sizeof(wchar_t) > 2 && w <= 0x10ffff){

			dest.push_back(0xf0| ((w >> 18) & 0x07)); // wchar_t 4-bytes situation

			dest.push_back(0x80| ((w >> 12) & 0x3f));

			dest.push_back(0x80| ((w >> 6) & 0x3f));

			dest.push_back(0x80| (w & 0x3f));

		}

		else

			dest.push_back('?');

	}

}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	//std::string strDest = "";
	//WStrToUTF8(strDest, L"中国");
	//CCLabelTTF* pLabel = CCLabelTTF::create(strDest.c_str(), "fonts/arialuni.ttf", 32);

	wchar_t str[100] = {L"中国"};  
	char strs[200] = {0};  
	WCharToMByte(str,strs,sizeof(str)/sizeof(strs[0]));
	CCLabelTTF* pLabel = CCLabelTTF::create(strs, "fonts/arialuni.ttf", 32);
    //CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
