#include "mywebpage.h"
#include <QDesktopServices>

myWebPage::myWebPage()
{
    qDebug() << "Web Page created: " << requestedUrl();
}

bool myWebPage::acceptNavigationRequest(const QUrl & url, NavigationType type, bool isMainFrame) {
    qDebug() << "link clicked! " << url.toString() << " " << (int)type << (int)isMainFrame;
    qDebug() << "Requested URL: " << requestedUrl();
    qDebug() << "Url: " << this->url();
    if ((isMainFrame) && (this->url() == QUrl("")) && ((url.toString() != "https://tweetdeck.twitter.com/#") && (url.toString() != "https://tweetdeck.twitter.com/") && (url.toString() != "http://tweetdeck.twitter.com/"))) {
      QDesktopServices::openUrl(url);
      delete this;
    }
    return true;
}


