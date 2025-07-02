#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

//interface for shuffle strategy
class IShuffleStrategy{
public:
    virtual void shuffle(vector<string>& playlist) = 0;
    virtual ~IShuffleStrategy() {}
};

class RandomShuffle:public IShuffleStrategy {
public:
    void shuffle(vector<string>&playlist) override{
        std::shuffle(playlist.begin(), playlist.end(), mt19937(random_device{}()));
    }
};

class PlaylistShuffler {
private:
    vector<string> originalSongs;  // original list
    vector<string> currentShuffle; // current shuffle cycle
    int index; // index in currentShuffle
    IShuffleStrategy* strategy; // shuffle strategy

    void reshuffle() {
        currentShuffle = originalSongs;
        strategy->shuffle(currentShuffle);
        index = 0;
    }

public:
    PlaylistShuffler(const vector<string>& songs,IShuffleStrategy*strat):originalSongs(songs), index(0),strategy(strat) {
        reshuffle(); // prepare initial shuffle
    }

    string playNext() {
        if (index >= currentShuffle.size()) {
            reshuffle(); // new shuffle cycle
        }
        return currentShuffle[index++];
    }
};
int main() {
    vector<string> songs = {"Song1", "Song2", "Song3", "Song4"};
    RandomShuffle randomStrategy;
    PlaylistShuffler player(songs, &randomStrategy);
    cout << "Playing shuffled songs:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Playing: " << player.playNext() << endl;
    }

    return 0;
}
