#include <menu.h>



Menu::Menu(Arduboy2 *ab, Player **team, Font3x5 *font)
{
    this->ab = ab;
    this->team = team;
    this->font = font;
}
void Menu::draw(Room *room)
{
    for (uint8_t i = 0; i < TEAM_SIZE; i++)
    {
        font->setCursor(98, i * 6);
        font->print(team[i]->getShortClassName());
        font->setCursor(104, i * 6);
        font->print(team[i]->getHp());
        font->print('/');
        font->print(team[i]->getMaxHp());
    }

    drawButton(1, 50, F("Attaque"), true);
    drawButton(64, 50, F("Fuir"));

    font->setCursor(1, 57);
    font->print("Explorer");

    font->setTextColor(0);
    ab->fillRect(63, 57, 6 * 4 + 1, 7);
    font->setCursor(64, 57);
    font->print("Sortir");
    font->setTextColor(1);
}
void Menu::updade(Room *Room)
{
}

void Menu::drawButton(uint8_t x, uint8_t y, String text, bool selected)
{
    if (selected)
    {
        ab->fillRect(x - 1, y, text.length() * 4 + 1, 7);
    }
    font->setCursor(x, y);
    font->setTextColor(!selected);
    font->print(text);
}
