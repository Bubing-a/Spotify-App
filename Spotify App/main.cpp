#include "spotifyapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SpotifyApp w;

	w.setWindowTitle(QString::fromUtf8("Spotify Simple"));
	w.resize(450, 300);
	w.setStyleSheet("background-color:rgb(40, 40, 40);");

	w.show();
	return a.exec();
}
