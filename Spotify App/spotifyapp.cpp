#include "spotifyapp.h"
#include "ui_spotifyapp.h"


SpotifyApp::SpotifyApp(QWidget *parent)
	: QMainWindow(parent)
	, m_playing(false)
{

	ui.setupUi(this);
	//ui.Play_Pause->setText("play");
	QObject::connect(ui.Play_Pause, SIGNAL(pressed()), this, SLOT(pressedPPSlot()));
	QObject::connect(ui.Play_Pause, SIGNAL(clicked()), this, SLOT(clickedSlot()));
	QObject::connect(ui.Previous, SIGNAL(pressed()), this, SLOT(pressedPrevSlot()));
	QObject::connect(ui.Previous, SIGNAL(released()), this, SLOT(releasedPrevSlot()));
	QObject::connect(ui.Next, SIGNAL(pressed()), this, SLOT(pressedNextSlot()));
	QObject::connect(ui.Next, SIGNAL(released()), this, SLOT(releasedNextSlot()));

	clickedSlot();
	releasedPrevSlot();
	releasedNextSlot();

	show();
}


SpotifyApp::~SpotifyApp()
{}

void SpotifyApp::changeButtonIcon(QPushButton *btn, char *fileName)
{
	QPixmap pixmap(fileName);
	QIcon ButtonIcon(pixmap);
	btn->setIcon(ButtonIcon);
	btn->setIconSize(pixmap.rect().size());
}

// ------------------------------------------------------------------------------------------------
// This code makes the Play/Pause button change image and text when clicked happens. 
// ------------------------------------------------------------------------------------------------
void SpotifyApp::clickedSlot()
{
	
	if (m_playing == true)
	{
		m_playing = false;
		//ui.Play_Pause->setText("Pause");
		changeButtonIcon(ui.Play_Pause, ":/Resources/Pause.png");
	}
	else
	{
		m_playing = true;
		//ui.Play_Pause->setText("Play");
		changeButtonIcon(ui.Play_Pause, ":/Resources/Play.png");
	}
	
}
// ------------------------------------------------------------------------------------------------
// change Play/Pause button to darken when pressed
// ------------------------------------------------------------------------------------------------
void SpotifyApp::pressedPPSlot()
{
	if (m_playing == true)
	{
		changeButtonIcon(ui.Play_Pause, ":/Resources/Play Dark.png");
	}
	else
	{
		changeButtonIcon(ui.Play_Pause, ":/Resources/Pause Dark.png");
	}
}

// ------------------------------------------------------------------------------------------------
// change Previous button to darken when pressed
// ------------------------------------------------------------------------------------------------
void SpotifyApp::releasedPrevSlot()
{
	changeButtonIcon(ui.Previous, ":/Resources/Previous Bright.png");
}

void SpotifyApp::pressedPrevSlot()
{
	changeButtonIcon(ui.Previous, ":/Resources/Previous.png");
}
// ------------------------------------------------------------------------------------------------
// change Next button to darken when pressed
// ------------------------------------------------------------------------------------------------
void SpotifyApp::releasedNextSlot()
{
	changeButtonIcon(ui.Next, ":/Resources/Next Bright.png");
}

void SpotifyApp::pressedNextSlot()
{
	changeButtonIcon(ui.Next, ":/Resources/Next.png");
}
