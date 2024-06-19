#include <iostream>

using namespace std;

class State {
public:
    virtual ~State() = default;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

class MusicPlayer {
private:
    State* currentState;
    State* stoppedState;
    State* playingState;
    State* pausedState;

public:
    MusicPlayer();

    ~MusicPlayer() {
        delete stoppedState;
        delete pausedState;
        delete playingState;
    }

    void setState(State* state) {
        currentState = state;
    }

    void play() {
        currentState->play();
    }

    void pause() {
        currentState->pause();
    }

    void stop() {
        currentState->stop();
    }

    State* getStoppedState() {
        return stoppedState;
    }

    State* getPlayingState() {
        return playingState;
    }

    State* getPausedState() {
        return pausedState;
    }
};

class StoppedState : public State {
private:
    MusicPlayer* player;

public:
    StoppedState(MusicPlayer* player) : player(player) {}

    void play() {
        cout << "Starting playback." << endl;
        player->setState(player->getPlayingState());
    }

    void pause() {
        cout << "Already stopped." << endl;
    }

    void stop() {
        cout << "Already stopped." << endl;
    }
};

class PausedState : public State {
private:
    MusicPlayer* player;

public:
    PausedState(MusicPlayer* player) : player(player) {}

    void play() {
        cout << "Resuming playback." << endl;
        player->setState(player->getPlayingState());
    }

    void pause() {
        cout << "Already paused." << endl;
    }

    void stop() {
        cout << "Stopping playback." << endl;
        player->setState(player->getStoppedState());
    }
};

class PlayingState : public State {
private:
    MusicPlayer* player;

public:
    PlayingState(MusicPlayer* player) : player(player) {}

    void play() {
        cout << "Already playing." << endl;
    }

    void pause() {
        cout << "Pausing playback." << endl;
        player->setState(player->getPausedState());
    }

    void stop() {
        cout << "Stopping playback." << endl;
        player->setState(player->getStoppedState());
    }
};

MusicPlayer::MusicPlayer() {
    this->stoppedState = new StoppedState(this);
    this->playingState = new PlayingState(this);
    this->pausedState = new PausedState(this);
    currentState = stoppedState;
}


int main()
{

    MusicPlayer player;
    player.play();
    player.play();

}
