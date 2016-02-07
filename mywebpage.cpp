#include "mywebpage.h"
#include <QDesktopServices>

myWebPage::myWebPage()
{
}

bool myWebPage::acceptNavigationRequest(const QUrl & url, NavigationType type, bool isMainFrame) {
    if ((isMainFrame) && (this->url() == QUrl("")) && ((url.toString() != "https://tweetdeck.twitter.com/#") && (url.toString() != "https://tweetdeck.twitter.com/") && (url.toString() != "http://tweetdeck.twitter.com/"))) {
      QDesktopServices::openUrl(url);
      delete this;
    }
    return true;
}


