#ifndef SPOTIFYAPP_H
#define SPOTIFYAPP_H
#include "ui_spotifyapp.h"
#include <QMainWindow>
#include <QPushButton>

//namespace Ui {
//class SpotifyAppClass;
//}

class SpotifyApp : public QMainWindow
{
	Q_OBJECT

public:
	explicit SpotifyApp(QWidget *parent = nullptr);
	~SpotifyApp();

private:
	Ui_SpotifyAppClass ui;
	bool m_playing;
	//void clicked();
	//void pressed();
	void changeButtonIcon(QPushButton *btn, char *fileName);

private slots:

	void clickedSlot();
	void releasedPrevSlot();
	void releasedNextSlot();
	void pressedPPSlot();
	void pressedNextSlot();
	void pressedPrevSlot();
	

};

#endif // SPOTIFYAPP_H
