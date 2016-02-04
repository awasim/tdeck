#include "myviewview.h"
#include <QWebEngineSettings>

myViewView::myViewView() : mwebpage(new myWebPage())
{
    setPage(mwebpage);
    QWebEngineSettings* settings = this->settings();
    settings->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, false);
    settings->setAttribute(QWebEngineSettings::HyperlinkAuditingEnabled, false);
    settings->setAttribute(QWebEngineSettings::LinksIncludedInFocusChain, false);
    settings->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, false);
}
