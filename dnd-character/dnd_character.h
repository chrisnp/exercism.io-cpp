#pragma once

namespace dnd_character {

auto ability() -> int;
auto modifier(int) -> int;

struct Character {
    int strength { 0 };
    int dexterity { 0 };
    int constitution { 0 };
    int intelligence { 0 };
    int wisdom { 0 };
    int charisma { 0 };
    int hitpoints { 0 };
    Character();
};

}  // namespace dnd_character

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif