#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>

class QMediaPlayer;

enum SoundType
{
        TowerPlaceSound,
        LifeLoseSound,
        LaserShootSound,
        EnemyDestorySound
};

class AudioPlayer : public QObject
{
public:
	explicit AudioPlayer(QObject *parent = 0);

	void startBGM();
	void playSound(SoundType soundType);

private:
        QMediaPlayer *m_backgroundMusic;
};


#endif // AUDIOPLAYER_H
