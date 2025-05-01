#pragma once

#include "Player_stats.h"
#include <vector>
#include <string>

class MinorEvent {
public:
    virtual void trigger(PlayerStats& player) = 0;
    virtual ~MinorEvent() = default;
};

class CoinEvent : public MinorEvent {
public:
    void trigger(PlayerStats& player) override;
};

class EnemyEvent : public MinorEvent {
public:
    void trigger(PlayerStats& player) override;
};

class PuzzleEvent : public MinorEvent {
public:
    void trigger(PlayerStats& player) override;

private:
    std::vector<std::pair<std::string, std::string>> puzzles;
    void loadPuzzles();
};

class TriviaEvent : public MinorEvent {
public:
    void trigger(PlayerStats& player) override;

private:
    std::vector<std::pair<std::string, std::string>> trivia;
    void loadTrivia();
};
