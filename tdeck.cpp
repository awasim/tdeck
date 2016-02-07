#include <iostream>
#include <QApplication>
#include "myviewview.h"


int main(int argc, char ** argv) {
  QApplication app(argc, argv);

    myViewView vv;
    vv.resize(687, 1000);
    vv.load(QUrl("http://tweetdeck.twitter.com"));
    vv.show();

  return app.exec();
}
