#include <iostream>
#include <chrono>
#include <thread>
#include "Main_events.h"
#include "Player_stats.h"
#include "MinorEvents.h"
using namespace std;

int main() {

	PlayerStats player;

	cout << "Good morning! Today is the day, the day you will become something more than yourself...more than what you've ever thought you could be and more than you could ever hope to become." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "Honestly, I never thought you'd get to this point. You, Frank, and your dog, Jim, have grown to become a duet that I couldn't be more proud of. No matter what happens today, I will always have that pride." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "Well, the time has come. Will you set off?" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));

	cout << "(when giving answers, please do not use caps or punctuation of any kind. if you think there is no valid answer to the question answer with 'n/a'. if your answer has would be 'the empire state building' make sure you include 'the' in your answer.)";

	string choice;
	cin >> choice;

	if (choice != "yes") {
		cout << "You decide not to set off. Game Over." << endl;
		return 0;
	}


	// timers are at 0 between dialogue for testing purposes
	cout << "You and Jim walk from your house towards the woods. You've never been before, but in your time here you've always wondered what lay within." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "You're not really sure how you got here. In your home there's never been any parents, a concept of which you know nothing about, but the idea that there should be someone to care for you has always been at the back of your mind." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "You have never seen a living thing other than Jim. You and him have been together for a long time, but just as you're unsure of your own heritage you are also unsure of his." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "Every morning you had woken up, rolled out of bed, and everything you needed was just...there. Cooked meals, water, clothes, you've needed for nothing. And everything just seems to manifest when you're not looking." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "Come to think of it, who was that talking to you this morning? Never in your life have you heard spoken words, yet, you understood the voice perfectly. You felt safe..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "** As you needlessly ponder your existence, you are approached by some sort of bird.**" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "Bird thing: Good morning traveller and dog! I see you're trying to walk through MY territory." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(0));
	cout << "While it is true this is MINE, I am feeling generous on this beautiful morning the forest has been blessed with. I will let you pass if you can answer one simple question, matter of fact if you answer it correctly I'll keep myself from ending you... and your dog!" << endl;

	MainEvent1 event1;
	event1.start(player);

	int eventCount = 2 + rand() % 2; 
	std::cout << "You will face " << eventCount << " minor events.\n";

	for (int i = 0; i < eventCount; ++i) {
		std::cout << "\n--- Minor Encounter #" << (i + 1) << " ---\n";

		int triggerRoll = rand() % 3; 
		if (triggerRoll < 2) {
			int eventType = rand() % 4;
			std::unique_ptr<MinorEvent> event;

			switch (eventType) {
			case 0: event = std::make_unique<CoinEvent>(); break;
			case 1: event = std::make_unique<EnemyEvent>(); break;
			case 2: event = std::make_unique<PuzzleEvent>(); break;
			case 3: event = std::make_unique<TriviaEvent>(); break;
			}

			event->trigger(player);
		}
		else {
			std::cout << "You travel safely. No event occurred.\n";
		}

		std::cout << "Current Health: " << player.getHealth()
			<< " | Current Money: " << player.getMoney() << "\n";
	}


	MainEvent2 event2;
	event2.start(player);

	return 0;
}
