#include "Button.h"
#include "Text.h"
#include <iostream>

using namespace sf;
using namespace std;

//WINDOW CONSTANT SIZES
const int length = 1200;
const int width = 900;

//FUNCTION FOR LOADING ALL TEXTURES AT ONCE
void loadTextures(Texture* t) {

    t[0].loadFromFile("C:/VisualStudio/Wordle/Wordle/A.jpg");           //LETTER A
    t[1].loadFromFile("C:/VisualStudio/Wordle/Wordle/B.jpg");           //LETTER B
    t[2].loadFromFile("C:/VisualStudio/Wordle/Wordle/C.jpg");           //LETTER C
    t[3].loadFromFile("C:/VisualStudio/Wordle/Wordle/D.png");           //LETTER D
    t[4].loadFromFile("C:/VisualStudio/Wordle/Wordle/E.png");           //LETTER E
    t[5].loadFromFile("C:/VisualStudio/Wordle/Wordle/F.png");           //LETTER F
    t[6].loadFromFile("C:/VisualStudio/Wordle/Wordle/G.png");           //LETTER G
    t[7].loadFromFile("C:/VisualStudio/Wordle/Wordle/H.png");           //LETTER H
    t[8].loadFromFile("C:/VisualStudio/Wordle/Wordle/I.png");           //LETTER I
    t[9].loadFromFile("C:/VisualStudio/Wordle/Wordle/J.png");           //LETTER J
    t[10].loadFromFile("C:/VisualStudio/Wordle/Wordle/K.png");          //LETTER K
    t[11].loadFromFile("C:/VisualStudio/Wordle/Wordle/L.png");          //LETTER L
    t[12].loadFromFile("C:/VisualStudio/Wordle/Wordle/M.png");          //LETTER M
    t[13].loadFromFile("C:/VisualStudio/Wordle/Wordle/N.png");          //LETTER N
    t[14].loadFromFile("C:/VisualStudio/Wordle/Wordle/O.png");          //LETTER O
    t[15].loadFromFile("C:/VisualStudio/Wordle/Wordle/P.png");          //LETTER P
    t[16].loadFromFile("C:/VisualStudio/Wordle/Wordle/Q.png");          //LETTER Q
    t[17].loadFromFile("C:/VisualStudio/Wordle/Wordle/R.png");          //LETTER R
    t[18].loadFromFile("C:/VisualStudio/Wordle/Wordle/S.png");          //LETTER S
    t[19].loadFromFile("C:/VisualStudio/Wordle/Wordle/T.png");          //LETTER T
    t[20].loadFromFile("C:/VisualStudio/Wordle/Wordle/U.png");          //LETTER U
    t[21].loadFromFile("C:/VisualStudio/Wordle/Wordle/V.png");          //LETTER V
    t[22].loadFromFile("C:/VisualStudio/Wordle/Wordle/W.png");          //LETTER W
    t[23].loadFromFile("C:/VisualStudio/Wordle/Wordle/X.png");          //LETTER X
    t[24].loadFromFile("C:/VisualStudio/Wordle/Wordle/Y.png");          //LETTER Y
    t[25].loadFromFile("C:/VisualStudio/Wordle/Wordle/Z.png");          //LETTER Z
    t[26].loadFromFile("C:/VisualStudio/Wordle/Wordle/Bg.png");         //REMOVED FIELD
    //EMPTY FIELD [27]
    t[28].loadFromFile("C:/VisualStudio/Wordle/Wordle/Exit.png");       //"EXIT" BUTTON
    t[29].loadFromFile("C:/VisualStudio/Wordle/Wordle/nouns.png");       //"NOUNS" BUTTON
    t[30].loadFromFile("C:/VisualStudio/Wordle/Wordle/verbs.png");     //"VERBS" BUTTON
    t[31].loadFromFile("C:/VisualStudio/Wordle/Wordle/adjectives.png");       //"ADJECTIVES" BUTTON
}

void loadFonts(Font* f) {
    f[0].loadFromFile("C:/VisualStudio/Wordle/Wordle/Fonts/comic.ttf");             //Comic
    f[1].loadFromFile("C:/VisualStudio/Wordle/Wordle/Fonts/BadlyStamped.ttf");      //BadlyStamped
    //for menu
}

string selectNoun() {
    srand(time(0));
    string arr[30] = { "candy", "enemy", "bacon", "beach", "apple"};
    int index = (rand() % 5);
    //return arr[index];
    return "nouns";
}

string selectVerb() {
    srand(time(0));
    string arr[30] = { "study", "break", "build", "teach", "spell"};
    int index = (rand() % 5);
    //return arr[index];
    return "verbs";
}

string selectAdjective() {
    srand(time(0));
    string arr[30] = { "sweet", "green", "smart", "great", "funny" };
    int index = (rand() % 5);
    //return arr[index];
    return "adjct";
}

int main() {

    //WINDOW DECLARATION AND PROPERTIES
    RenderWindow mainWindow(VideoMode(length, width), "Wordle", Style::None);
    mainWindow.setKeyRepeatEnabled(false);
    mainWindow.setFramerateLimit(60);

    //CREATING OFFGAME WINDOW
    RectangleShape offGame;
    offGame.setFillColor(Color(256, 256, 256, 140));
    offGame.setSize(Vector2f(570, 570));
    offGame.setPosition(Vector2f(315, 85));
    offGame.setOutlineThickness(5);
    offGame.setOutlineColor(Color::Black);

    //RANDOMIZER
    string word, attempt = "";




    //CREATING TEXTURES
    Texture Letters[32];   
    loadTextures(Letters);

    //CREATING FONTS
    Font fonts[3];
    loadFonts(fonts);

    //CREATING TEXTS FOR WINDOW
    text Wordle, Names, Guess, youLost, youWon;
    Wordle.createText(fonts[1], 75, Color::Black, Text::Style::Regular, Vector2f(7, 10), "Wordle");
    Names.createText(fonts[0], 25, Color::Black, Text::Style::Regular, Vector2f(10, 100), "Mariam Alakhverdova \nLuka Budagovi");
    Guess.createText(fonts[0], 72, Color::Red, Text::Style::Bold, Vector2f(505, 790), word);
    youLost.createText(fonts[0], 72, Color::Black, Text::Style::Bold, Vector2f(440, 680), "You Lost;(");
    youWon.createText(fonts[0], 72, Color::Black, Text::Style::Bold, Vector2f(440, 680), "You Win!");

    //CREATING BUTTONS
    Button Exit, Nouns, Verbs, Adjectives;
    Exit.createButton(Vector2f(1080, 20), Vector2f(80, 80), Color(237, 210, 183), Letters[28]);
    Nouns.createButton(Vector2f(478, 160), Vector2f(244, 86), Color::White, Letters[29]);
    Verbs.createButton(Vector2f(478, 290), Vector2f(245, 85), Color::White, Letters[30]);
    Adjectives.createButton(Vector2f(478, 420), Vector2f(244, 86), Color::White, Letters[31]);

    //CREATING INITIAL PUZZLES WITH EMPTY FIELDS AND DEFAULT PROPERTIES:
    RectangleShape puzzles[5][5];
    int xCoordinate = 330, yCoordinate = 100;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            puzzles[i][j].setSize(Vector2f(100, 100));
            puzzles[i][j].setPosition(Vector2f(xCoordinate, yCoordinate));
            puzzles[i][j].setOutlineThickness(3);
            puzzles[i][j].setFillColor(Color(219, 141, 148));
            puzzles[i][j].setOutlineColor(Color::Black);
            xCoordinate += 110;
        }
        xCoordinate = 330;
        yCoordinate += 110;
    }

    bool isGuessed = true;         //TO STOP THE GAME AT PROPER TIME
    int x = 0, y = 0, count = 0;    //TO CONTROL IN WHICH PUZZLE WE ARE ACTING

    while (mainWindow.isOpen()) {

        Event e;

        while (mainWindow.pollEvent(e)) {

            //WINDOW CLOSE CASES
            if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) mainWindow.close();

            //INDICATING EVENIT FOR BUTTONS
            Exit.setEvent(e);
            Nouns.setEvent(e);
            Verbs.setEvent(e);
            Adjectives.setEvent(e);

            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    cout << e.mouseButton.x << endl;
                    cout << e.mouseButton.y << endl;
                    if (Exit.isClicked()) mainWindow.close();
                }
                if (isGuessed) {

                    if (Nouns.isClicked()) word = selectNoun();
                    else if (Verbs.isClicked()) word = selectVerb();
                    else if (Adjectives.isClicked()) word = selectAdjective();
                    isGuessed = false;

                }
            }
            //ENTERING LOWER CASE LETTERS INTO THE ROW

            if (e.type == Event::TextEntered && e.text.unicode >= 'a' && e.text.unicode <= 'z') {
                if (y >= 0 && y < 5 && !isGuessed) {
                    puzzles[x][y].setTexture(&Letters[e.text.unicode - 97]);
                    attempt += char(e.text.unicode);
                    y++;
                    cout << attempt << endl;
                }
            }

            //REMOVING LOWER CASE LETTERS INTO THE ROW
            else if (e.text.unicode == 0x08 && Keyboard::isKeyPressed(Keyboard::BackSpace)) {
                if (y != 0) {
                    y--;
                    puzzles[x][y].setTexture(&Letters[26]);
                    attempt = attempt.substr(0, attempt.length() - 1);
                    cout << "test" << endl;
                }
            }

            //AFTER PRESSING "ENTER" THE GAME CHECKS THE TYPED WORD 
            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                if (attempt.length() == 5) {
                    string h = "*****";         // TO DETECT RED LETTERS;
                    string check(word);         // TO DETECT GREEN AND YELLOW LETTERS;

                    //ITERATING THROUGH THE WORD TO DETECT GREEN WORDS;
                    for (int i = 0; i < 5; ++i) {
                        if (attempt[i] == word[i]) {
                            puzzles[count][i].setFillColor(Color(108, 218, 113));
                            h[i] = '-';
                            check[i] = '*';
                        }
                    }
                    //ITERATING THROUGH THE WORD TO DETECT YELLOW LETTERS;
                    for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                            if (attempt[i] == check[j] && check[i] != '*') {      //HERE WE DONT CHECK ALREADY GUESSED (GREEN) LETTERS (check[i]!='*')
                                puzzles[count][i].setFillColor(Color(236, 215, 124));
                                h[i] = '-';
                            }
                        }
                    }
                    //ITERATING THROUGH THE WORD TO DETECT RED LETTERS;
                    for (int i = 0; i < 5; ++i) {
                        if (h[i] == '*') puzzles[count][i].setFillColor(Color(203, 93, 103));
                        puzzles[count][i].setOutlineThickness(5);
                        puzzles[count][i].setOutlineColor(Color::Black);
                    }
                    //CHECK IF ENTERED WORD IS CORRECTLY GUESSED (Win case)
                    if (attempt == word) {
                        isGuessed = true;
                    }
                    count++;
                    attempt = "";
                    y = 0;
                    x++;
                }
            }
        }

        //DISPLAY COMPONENTS
        mainWindow.clear(Color(237, 210, 183));
        mainWindow.draw(Exit.getButton());
        mainWindow.draw(Wordle.getText());
        mainWindow.draw(Names.getText());

        //ITERATING TO DISPLAY UPDATED PUZZLES
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                mainWindow.draw(puzzles[i][j]);
            }
        }

        //WIN/LOSE CASE
        if (isGuessed) {
            mainWindow.draw(youWon.getText());
            mainWindow.draw(Guess.getText());
            mainWindow.draw(offGame);
            mainWindow.draw(Nouns.getButton());
            mainWindow.draw(Verbs.getButton());
            mainWindow.draw(Adjectives.getButton());
        }
        else if (x > 4 && !isGuessed) {
            mainWindow.draw(youLost.getText());
            mainWindow.draw(Guess.getText());
            mainWindow.draw(offGame);
            mainWindow.draw(Nouns.getButton());
            mainWindow.draw(Verbs.getButton());
            mainWindow.draw(Adjectives.getButton());
        }

        mainWindow.display();
    }

    return 0;
}

//THE END