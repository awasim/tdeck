#ifndef MYVIEWVIEW_H
#define MYVIEWVIEW_H

#include <QWebEngineView>
#include <mywebpage.h>

class myViewView : public QWebEngineView
{
public:
    myViewView();

private:
    myWebPage* mwebpage;
};

#endif // MYVIEWVIEW_H
