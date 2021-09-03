#include <menu.h>

// 0-5 : bouton en bas
// 6-10 : porte

Menu::Menu(Arduboy2 *ab, Player **team, Font3x5 *font)
{
    this->ab = ab;
    this->team = team;
    this->font = font;

    this->cursor = 6;
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

    font->setCursor(98, 24);
    font->print(room->doorCount);

    for (uint8_t d = 0; d < room->doorCount; d++)
    {
        if (d + 6 == cursor)
        {
            ab->drawRoundRect(room->door[d]->x * 8 + room->getDrawStartX(), room->door[d]->y * 8 + room->getDrawStartY(), 8, 8, 1);
        }
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
