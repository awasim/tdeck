rm tdeck.pro
rm tdeck.o
qmake -project
echo "QT += widgets webkit webkitwidgets" >> tdeck.pro
echo "ICON = tdeck.icns" >> tdeck.pro
qmake
make
