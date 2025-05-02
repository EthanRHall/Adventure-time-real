#include <iostream>
#include <chrono>
#include <thread>
#include "Main_events.h"
#include "Player_stats.h"
#include "MinorEvents.h"
#include "Shop.h"
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

//this is a test please god work

int main() {

	PlayerStats player;
	Shop shop;

	cout << "\nGood morning! Today is the day, the day you will become something more than yourself...more than what you've ever thought you could be and more than you could ever hope to become.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nHonestly, I never thought you'd get to this point. You, Frank, and your dog, Jim, have grown to become a duet that I couldn't be more proud of. No matter what happens today, I will always have that pride.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nWell, the time has come. Will you set off?\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n(when giving answers, please do not use caps or punctuation of any kind. if you think there is no valid answer to the question answer with 'n/a'. if your answer has would be 'the empire state building' make sure you include 'the' in your answer.)\n";

	string choice;
	cin >> choice;

	if (choice != "yes") {
		cout << "\nYou decide not to set off. Game Over.\n" << endl;
		return 0;
	}


	// timers are at 0 between dialogue for testing purposes
	cout << "\nYou and Jim walk from your house towards the woods. You've never been before, but in your time here you've always wondered what lay within.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nYou're not really sure how you got here. In your home there's never been any parents, a concept of which you know nothing about, but the idea that there should be someone to care for you has always been at the back of your mind.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nYou have never seen a living thing other than Jim. You and him have been together for a long time, but just as you're unsure of your own heritage you are also unsure of his.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nEvery morning you had woken up, rolled out of bed, and everything you needed was just...there. Cooked meals, water, clothes, you've needed for nothing. And everything just seems to manifest when you're not looking.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nCome to think of it, who was that talking to you this morning? Never in your life have you heard spoken words, yet, you understood the voice perfectly. You felt safe...\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\n** As you needlessly ponder your existence, you are approached by some sort of bird.**\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	sf::SoundBuffer birdbuffer;
	birdbuffer.loadFromFile("bird_noises_main_1.wav");
	sf::Sound bird(birdbuffer);
	bird.play();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	cout << "\nBird thing: Good morning traveller and dog! I see you're trying to walk through MY territory.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\nWhile it is true this is MINE, I am feeling generous on this beautiful morning the forest has been blessed with. I will let you pass if you can answer one simple question, matter of fact if you answer it correctly I'll keep myself from ending you... and your dog!\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	MainEvent1 event1;
	event1.start(player);

	int eventCount = 2 + rand() % 2; 
	std::cout << "\nYou will face " << eventCount << " minor events.\n";

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (int i = 0; i < eventCount; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
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

	shop.open(player);

	std::cout << "\nCurrent Stats:\n";
	std::cout << "Health: " << player.getHealth()
		<< " | Money: " << player.getMoney()
		<< " | Armor: " << shop.getArmor()
		<< " | Damage Boost: " << shop.getDamageBoost() << "\n";

	std::cout << "Get ready for the next event...\n";
	std::this_thread::sleep_for(std::chrono::seconds(5)); // 5-second pause
	std::cout << "Event is starting!\n";

	cout << "\nYou find yourself in a clearing after the path comes to and end. It's quite odd really, the forest just went from being thick and healthy to being an empty field.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nAs you and jim trot you notice a straight line of 4 men in bright red coats approachig you, very very slowly. They have big black hats and refuse to break order.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nThe first one in line approaches you.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n'Oi! You really fink you and your li-ole dogg can walk fru here wi-out an issue?!'\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nyou can tell these guys aren't really friendly, especilly as the first one draws his saber and poses like a dork. In response you draw your own, but you notice again the ones behind him don't act or do anything...\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	MainEvent2 event2;
	event2.start(player);

	cout << "\nYou find youself at the entrance to another woods, and as you walk in the trees quickly clear out, but not like a field as before. This time its more like a little clearing in the woods.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nIn this clearing there are two large stumps, and at one stands a person like you, but his head doesn't look normal. It looks like a sidewayas funnel with a cone in the mdidle of it.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nYou approach the other stump and he yells speaks, and his voice is the loudest thing you've ever heard in your life.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n'GOOD DAY TRAVELER! COME JOIN OUR GAME!\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nTHE GAME OF WHICH I SPEAK IS ONE OF SKILL AND INTELLECT; YOU MUST GUESS THE NAME OF THE PERSON WHICH I AM IMPEROSNATING.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nSHOULD YOU CHOOSE THE RIGHT PERSON YOU MAY LEAVE! IF NOT... WELL YOU'LL HAVE TO WAIT AND SEE!\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n*he turns around and looks into the empty woods* ARE WE READY TO PLAY OR WHAT?!?!\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nYou hear a thunderous applause coming from within the woods but you see no one other than you and this weird...man?\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n*Please excuse the poor impersonations performed for this event, we just had fun with it*\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	MainEvent3 event3;
	event3.start(player);

	int eventCount = 2 + rand() % 2;
	std::cout << "\nYou will face " << eventCount << " minor events.\n";

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (int i = 0; i < eventCount; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
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

	shop.open(player);

	std::cout << "\nCurrent Stats:\n";
	std::cout << "Health: " << player.getHealth()
		<< " | Money: " << player.getMoney()
		<< " | Armor: " << shop.getArmor()
		<< " | Damage Boost: " << shop.getDamageBoost() << "\n";

	std::cout << "Get ready for the next event...\n";
	std::this_thread::sleep_for(std::chrono::seconds(5)); // 5-second pause
	std::cout << "Event is starting!\n";

	cout << "\nYou walk through the woods and come across a small house... Obviusly you're curious so you walk in.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nThe door slams shut behind you and Jim after the both of you enter. The room is cozy; a fireplace in the middle with a flat screen above the mantle. However, you notice a chair in the corner that is in complete darkness, the only part of the room with no light at all.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nFrom within the darkness you hear a voice...\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n'Hey Frank! you've gotten big! Same goes to you Jim! I  honestly thought I'd never see either of you again, especially since I moved out here. I was really hoping I didn't actually...'\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nHe turns on a lamp and the corner is no longer dark. He just appears to be a skinny old man, guitar on his back and a dagger on his hip. You also notice a few nearly empty glasses on the table next to his chair, they've got some ice sitting at the bottom with some brown liquid left in them.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nHe gets up and stumbles over to you and Jim.\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	
	cout << "\nHe whispers in your ear 'I will never forgive you or your mother for what you did to me...' His voice gets louder 'I've been alone for YEARS, no one to talk to, laugh with, play with, sing with, NOTHING.'\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nYou have no idea what he's talking about, but what you do notice is his hand creeping toward the dagger he keeps at his hip...\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n*For this event you must guess the name of the song he sings, if you guess it right he does not hit you, else he does. The singing is really, really bad. You've been warned.*\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	MainEvent4 event4;
	event4.start(player);

	cout << "\nUpon defeating him everything went white and you found yourself outside your house. \n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\nThe same voice from before speaks to you...\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n'Frank! Amazing job, that was sensational! You and Jim both killed it, literally!'\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	cout << "\n'You might be wondering who that man was and why he hated you... Well just like Tarantino with the case in Pulp Fiction, I'll let you figure that out for yourself! I hope you had fun!'\n" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));

	return 0;
}
