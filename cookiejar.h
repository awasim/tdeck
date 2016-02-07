#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QSettings>

class MyNetworkCookieJar : public QNetworkCookieJar {
 public:
 
 MyNetworkCookieJar(QObject *parent) : QNetworkCookieJar(parent) { load(); }
  ~MyNetworkCookieJar() { save(); }

  void load() {
	QSettings settings;
	QByteArray data = settings.value("Cookies").toByteArray();
	setAllCookies(QNetworkCookie::parseCookies(data));
	std::cerr << "### Load cookies" << std::endl;
	QList<QNetworkCookie> list = allCookies();
	foreach (QNetworkCookie cookie, list) {
	  std::cerr << "### Loading Saved cookies: " << cookie.domain().toStdString() << " : " << cookie.path().toStdString() << " : " << cookie.value().data()<< std::endl;
	}
  }

  void save() {
	QList<QNetworkCookie> list = allCookies();
	QByteArray data;
	foreach (QNetworkCookie cookie, list) {
	  //if (!cookie.isSessionCookie()) {
	  data.append(cookie.toRawForm());
	  data.append("\n");
		//}
	  std::cerr << "### Save cookies: " << cookie.domain().toStdString() << " : " << cookie.path().toStdString() << " : " << cookie.value().data() << std::endl;
	}
	QSettings settings;
	settings.setValue("Cookies",data);
	settings.sync(); 
  }

  bool saveCookiesToDisk() {
	std::cerr << "Cookies being saved to disk" << std::endl;
	return true;
  }
  
  bool loadCookiesFromDisk() {
	std::cerr << "Cookies Loading from Disk" << std::endl;
	return false;
  }
};
