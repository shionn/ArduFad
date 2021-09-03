#include <menu.h>

// 0-3 : porte
// 4-10 : bouton en bas

Menu::Menu(Arduboy2 *ab, Player **team, Font3x5 *font)
{
    this->ab = ab;
    this->team = team;
    this->font = font;
    this->cursor = 5;
}
void Menu::draw(Room *room)
{
    for (uint8_t i = 0; i < TEAM_SIZE; i++)
    {
        font->setCursor(102, i * 6);
        font->print(team[i]->getShortClassName());
        font->setCursor(108, i * 6);
        font->print(team[i]->getHp());
        font->print('/');
        font->print(team[i]->getMaxHp());
    }

    font->setCursor(102, 24);
    font->print(cursor);

    if (cursor < room->doorCount)
    {
        font->setCursor(102, 30);
        font->print(room->door[cursor]->x);
        font->setCursor(102, 36);
        font->print(room->door[cursor]->y);
        ab->drawRoundRect(room->door[cursor]->x * 8 + room->getDrawStartX(),
                          room->door[cursor]->y * 8 + room->getDrawStartY(),
                          8, 8, 3);
    }

    drawButton(1, 50, F("Attaque"), cursor == 4);
    drawButton(43, 50, F("Todo"), cursor == 5);
    drawButton(88, 50, F("Fuir"), cursor == 6);
    drawButton(1, 57, F("Explorer"), cursor == 7);
    drawButton(43, 57, F("todo"), cursor == 7);
    drawButton(88, 57, F("Sortir"), cursor == 8);
}
Room *Menu::updade(Room *room)
{
    if (ab->justPressed(UP_BUTTON))
    {
        switch (cursor)
        {
        case 0 ... 3:
            if (room->door[cursor]->isDir(DOOR_N))
                cursor = room->getNextDoorIndex(DOOR_N, cursor);
            else if (room->door[cursor]->isDir(DOOR_E))
                cursor = room->getNextDoorIndex(DOOR_E, cursor, room->getFirstDoorIndex(DOOR_N));
            else if (room->door[cursor]->isDir(DOOR_W))
                cursor = room->getNextDoorIndex(DOOR_W, cursor, room->getFirstDoorIndex(DOOR_N));
            else if (room->door[cursor]->isDir(DOOR_S))
                cursor = room->getFirstDoorIndex(DOOR_N, cursor);
            break;
        case 4 ... 6:
            if (room->doorCount)
                cursor = 0; // premiere porte celle la plus en bas
        }
    }
    if (ab->justPressed(DOWN_BUTTON))
    {
        switch (cursor)
        {
        case 0 ... 3:
            if (room->door[cursor]->isDir(DOOR_N))
                cursor = room->getFirstDoorIndex(DOOR_S, 5);
            else if (room->door[cursor]->isDir(DOOR_E))
                cursor = room->getPrevDoorIndex(DOOR_E, cursor, room->getFirstDoorIndex(DOOR_S, 5));
            else if (room->door[cursor]->isDir(DOOR_W))
                cursor = room->getPrevDoorIndex(DOOR_W, cursor, room->getFirstDoorIndex(DOOR_S, 5));
            else if (room->door[cursor]->isDir(DOOR_S))
                cursor = 5; // milieu du menu en bas
            break;
        }
    }

    if (ab->justPressed(LEFT_BUTTON))
    {
        switch (cursor)
        {
        case 0 ... 3:
            if (room->door[cursor]->isDir(DOOR_N))
                cursor = room->getPrevDoorIndex(DOOR_N, cursor, room->getFirstDoorIndex(DOOR_W));
            else if (room->door[cursor]->isDir(DOOR_E))
                cursor = room->getFirstDoorIndex(DOOR_W, cursor);
            else if (room->door[cursor]->isDir(DOOR_S))
                cursor = room->getPrevDoorIndex(DOOR_S, cursor, room->getFirstDoorIndex(DOOR_W));
            //rien a W (on est deja a gauche)
            break;
        }
    }

    if (ab->justPressed(RIGHT_BUTTON))
    {
        switch (cursor)
        {
        case 0 ... 3:
            if (room->door[cursor]->isDir(DOOR_N))
                cursor = room->getNextDoorIndex(DOOR_N, cursor, room->getFirstDoorIndex(DOOR_E)); // TODO menu droite
            else if (room->door[cursor]->isDir(DOOR_E))
                void; //TODO menu droite
            else if (room->door[cursor]->isDir(DOOR_W))
                cursor = room->getFirstDoorIndex(DOOR_E, cursor); //TODO menu droite
            else if (room->door[cursor]->isDir(DOOR_S))
                cursor = room->getNextDoorIndex(DOOR_S, cursor, room->getFirstDoorIndex(DOOR_E)); // TODO menu droite
            //rien a W (on est deja a gauche)
            break;
        }
    }

    if (ab->justPressed(B_BUTTON))
    {
        switch (cursor)
        {
        case 0 ... 3:
            Room *next = room->open(cursor);
            for (uint8_t i = 0; i < next->doorCount; i++)
                if (next->door[i]->room == room)
                    cursor = i;
            return next;
        }
    }
    return room;
}

void Menu::drawButton(uint8_t x, uint8_t y, String text, bool selected)
{
    if (selected)
        ab->fillRect(x - 1, y, text.length() * 4 + 1, 7);
    font->setCursor(x, y);
    font->setTextColor(!selected);
    font->print(text);
}
