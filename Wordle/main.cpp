#include "Button.h"
#include <iostream>

using namespace sf;
using namespace std;

//WINDOW CONSTANT SIZES
const int length = 1200;
const int width = 900;

//FUNCTION FOR LOADING ALL TEXTURES AT ONCE
void load(Texture* t) {

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

}

int main() {

    //WINDOW DECLARATION AND PROPERTIES
    RenderWindow mainWindow(VideoMode(length, width), "Wordle", Style::None);
    mainWindow.setKeyRepeatEnabled(false);
    mainWindow.setFramerateLimit(60);

    //CALLING FUNCTION AND LOADING ALL TEXTURES
    Texture Letters[26];
    load(Letters);


    Font comic;
    if (!comic.loadFromFile("C:/VisualStudio/Wordle/Wordle/Fonts/comic.ttf"))
        throw("Couldntload");

    Text youWon;
    youWon.setFont(comic);
    youWon.setCharacterSize(72);
    youWon.setFillColor(Color::Black);
    youWon.setStyle(Text::Bold);
    youWon.setPosition(440, 680);
    youWon.setString("You Won!");

    Text youLost;
    youLost.setFont(comic);
    youLost.setCharacterSize(72);
    youLost.setFillColor(Color::Black);
    youLost.setStyle(Text::Bold);
    youLost.setPosition(440, 680);
    youLost.setString("You Lost;(");


    RectangleShape WordleText;
    WordleText.setSize(Vector2f(325, 74));
    WordleText.setPosition(Vector2f(-2, 14));
    Texture wordleText;
    wordleText.loadFromFile("C:/VisualStudio/Wordle/Wordle/WordleText.png");
    WordleText.setTexture(&wordleText);
    WordleText.setFillColor(Color(237, 210, 183));

    RectangleShape Names;
    Names.setSize(Vector2f(241, 55));
    Names.setPosition(Vector2f(0, 90));
    Texture names;
    names.loadFromFile("C:/VisualStudio/Wordle/Wordle/lukabela.png");
    Names.setTexture(&names);
    Names.setFillColor(Color(237, 210, 183));

    //CREATING INITIAL PUZZLES WITH EMPTY FIELDS AND DEFAULT PROPERTIES:
    RectangleShape puzzles[5][5];
    int xCoordinate = 330, yCoordinate = 100, count = 0;
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

    string word = "build", attempt = "";   //here we should add a function for randomizing word


    Text guess;
    guess.setFont(comic);
    guess.setCharacterSize(72);
    guess.setFillColor(Color::Red);
    guess.setStyle(Text::Bold);
    guess.setPosition(505, 790);
    guess.setString(word);

    Texture empty;
    empty.loadFromFile("C:/VisualStudio/Wordle/Wordle/Bg.png");

    Button Exit;
    Texture exit;
    exit.loadFromFile("C:/VisualStudio/Wordle/Wordle/Exit.png");

    bool isGuessed = false;     //TO STOP THE GAME AT PROPER TIME
    int x = 0, y = 0;           //TO CONTROL IN WHICH PUZZLE WE ARE ACTING

    while (mainWindow.isOpen()) {

        Event e;

        while (mainWindow.pollEvent(e)) {

            //WINDOW CLOSE CASES
            if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) mainWindow.close();

            //BUTTONS SECTION
            Exit.createButton(Vector2f(1080, 20), Vector2f(80, 80), e, Color(237, 210, 183), exit);

            if (e.type == sf::Event::MouseButtonPressed) {

                if (e.mouseButton.button == sf::Mouse::Left) {

                    cout << e.mouseButton.x << endl;
                    cout << e.mouseButton.y << endl;
                    if (Exit.isClicked()) mainWindow.close();

                }
            }

            //ENTERING LOWER CASE LETTERS INTO THE ROW
            if (e.text.unicode >= 'a' && e.text.unicode <= 'z') {
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
                    puzzles[x][y].setTexture(&empty);
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
        mainWindow.draw(WordleText);
        mainWindow.draw(Names);

        //WIN/LOSE CASE
        if (isGuessed) mainWindow.draw(youWon);
        else if (x > 4 && !isGuessed) {
            mainWindow.draw(youLost);
            mainWindow.draw(guess);
        }

        //ITERATING TO DISPLAY UPDATED PUZZLES
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                mainWindow.draw(puzzles[i][j]);
            }
        }

        mainWindow.display();
    }

    return 0;
}

//THE END