#include <iostream>
#include <QApplication>
#include <QWebView>
#include <QWebSettings>
#include <QWebPage>
#include <QDesktopServices>
#include <cookiejar.h>

void linkClicked(QUrl link) {
  std::cerr << "Link with following URL was clicked: " << link.toString().toStdString() << std::endl;
  if (link.toString() != "https://tweetdeck.twitter.com/#")
	QDesktopServices::openUrl(link);
}

int main(int argc, char ** argv) {
  QApplication app(argc, argv);
  QWebView *view = new QWebView();
  QWebPage *ppage = view->page();
  QWebSettings *settings = ppage->settings();

  settings->setAttribute(QWebSettings::LocalStorageEnabled, true);
  settings->enablePersistentStorage("./storage");
  ppage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
  QObject::connect(view, &QWebView::linkClicked, linkClicked);
  
  view->resize(687, 1000);
  view->load(QUrl("http://tweetdeck.twitter.com"));
  view->show();

  return app.exec();
}
