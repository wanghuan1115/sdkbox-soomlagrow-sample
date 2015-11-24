#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginIAP/PluginIAP.h"
#include "PluginFacebook/PluginFacebook.h"
#include "PluginSoomlaGrow/PluginSoomlaGrow.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::IAPListener, sdkbox::FacebookListener, sdkbox::SoomlaGrowListener
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void onLoginClicked(cocos2d::Ref* sender);
    void onShareClicked(cocos2d::Ref* sender);

    void onRestoreClicked(cocos2d::Ref* sender);
    void onRefreshClicked(cocos2d::Ref* sender);
    void onPurchaseClicked(cocos2d::Ref* sender);
    
    //IAP Listener
    virtual void onInitialized(bool ok) override;
    
    virtual void onSuccess(sdkbox::Product const& p) override;
    
    virtual void onFailure(sdkbox::Product const& p, const std::string &msg) override;
    
    virtual void onCanceled(sdkbox::Product const& p) override;
    
    virtual void onRestored(sdkbox::Product const& p) override;
    
    virtual void onProductRequestSuccess(std::vector<sdkbox::Product> const &products) override;
    
    virtual void onProductRequestFailure(const std::string &msg) override;
    
    void onRestoreComplete(bool ok, const std::string &msg) override;
    
    //Facebook Listener
    // Events
    void onLogin(bool isLogin, const std::string& msg) override;
    void onSharedSuccess(const std::string& message) override;
    void onSharedFailed(const std::string& message) override;
    void onSharedCancel() override;
    void onAPI(const std::string& key, const std::string& jsonData) override;
    void onPermission(bool isLogin, const std::string& msg) override;
    void onFetchFriends(bool ok, const std::string& msg) override;

    void onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends )  override;
    void onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg )  override;
    void onInviteFriendsResult( bool result, const std::string& msg )  override;
    void onGetUserInfo( const sdkbox::FBGraphUser& userInfo )  override;

    //Soomla Grow Listener
    virtual void onGrowInitialized() override;
    virtual void onGrowConnected() override;
    virtual void onGrowDisconnected() override;
    virtual void onGrowInsightsInitialized() override;
    virtual void onInsightsRefreshFailed() override;
    virtual void onInsightsRefreshFinished() override;
    virtual void onInsightsRefreshStarted() override;

private:
    std::string _productName;
};

#endif // __HELLOWORLD_SCENE_H__
