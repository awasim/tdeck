#ifndef MYWEBPAGE_H
#define MYWEBPAGE_H

#include <QWebEnginePage>

class myWebPage : public QWebEnginePage
{
public:
    myWebPage();
    bool acceptNavigationRequest(const QUrl & url, NavigationType type, bool isMainFrame);

    QWebEnginePage* createWindow(WebWindowType type) {
        return new myWebPage();
    }
    void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString & message, int lineNumber, const QString & sourceID) {
        qDebug() << "Javascript Console Messages: " << message;
    }

};

#endif // MYWEBPAGE_H
