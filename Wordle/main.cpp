
#include "Button.h"
using namespace sf;
using namespace std;

int main() {

    //WINDOW DECLARATION AND PROPERTIES
    RenderWindow mainWindow(VideoMode(1200, 900), "Wordle", Style::Close);
    mainWindow.setKeyRepeatEnabled(false);
    mainWindow.setFramerateLimit(60);


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

    int x = 0, y = 0;
    string word = "couch", attempt = "";


    Text guess;
    guess.setFont(comic);
    guess.setCharacterSize(72);
    guess.setFillColor(Color::Red);
    guess.setStyle(Text::Bold);
    guess.setPosition(505, 790);
    guess.setString(word);

    Texture Letters[26];
    Letters[0].loadFromFile("C:/VisualStudio/Wordle/Wordle/A.jpg");
    Letters[1].loadFromFile("C:/VisualStudio/Wordle/Wordle/B.jpg");
    Letters[2].loadFromFile("C:/VisualStudio/Wordle/Wordle/C.jpg");
    Letters[3].loadFromFile("C:/VisualStudio/Wordle/Wordle/D.png");
    Letters[4].loadFromFile("C:/VisualStudio/Wordle/Wordle/E.png");
    Letters[5].loadFromFile("C:/VisualStudio/Wordle/Wordle/F.png");
    Letters[6].loadFromFile("C:/VisualStudio/Wordle/Wordle/G.png");
    Letters[7].loadFromFile("C:/VisualStudio/Wordle/Wordle/H.png");
    Letters[8].loadFromFile("C:/VisualStudio/Wordle/Wordle/I.png");
    Letters[9].loadFromFile("C:/VisualStudio/Wordle/Wordle/J.png");
    Letters[10].loadFromFile("C:/VisualStudio/Wordle/Wordle/K.png");
    Letters[11].loadFromFile("C:/VisualStudio/Wordle/Wordle/L.png");
    Letters[12].loadFromFile("C:/VisualStudio/Wordle/Wordle/M.png");
    Letters[13].loadFromFile("C:/VisualStudio/Wordle/Wordle/N.png");
    Letters[14].loadFromFile("C:/VisualStudio/Wordle/Wordle/O.png");
    Letters[15].loadFromFile("C:/VisualStudio/Wordle/Wordle/P.png");
    Letters[16].loadFromFile("C:/VisualStudio/Wordle/Wordle/Q.png");
    Letters[17].loadFromFile("C:/VisualStudio/Wordle/Wordle/R.png");
    Letters[18].loadFromFile("C:/VisualStudio/Wordle/Wordle/S.png");
    Letters[19].loadFromFile("C:/VisualStudio/Wordle/Wordle/T.png");
    Letters[20].loadFromFile("C:/VisualStudio/Wordle/Wordle/U.png");
    Letters[21].loadFromFile("C:/VisualStudio/Wordle/Wordle/V.png");
    Letters[22].loadFromFile("C:/VisualStudio/Wordle/Wordle/W.png");
    Letters[23].loadFromFile("C:/VisualStudio/Wordle/Wordle/X.png");
    Letters[24].loadFromFile("C:/VisualStudio/Wordle/Wordle/Y.png");
    Letters[25].loadFromFile("C:/VisualStudio/Wordle/Wordle/Z.png");
    Texture empty;
    empty.loadFromFile("C:/VisualStudio/Wordle/Wordle/Bg.png");


    Button Exit;
    Texture exit;
    exit.loadFromFile("C:/VisualStudio/Wordle/Wordle/Exit.png");

    bool isGuessed = false;

    while (mainWindow.isOpen()) {

        Event e;

        while (mainWindow.pollEvent(e)) {

            //BUTTON CONSTRUCTORS:
            Exit.createButton(Vector2f(1080, 20), Vector2f(80, 80), e, Color(237, 210, 183), exit);

            //WINDOW CLOSE CASES
            if (e.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) mainWindow.close();

            //BOTTOMS SECTION
            if (e.type == sf::Event::MouseButtonPressed) {

                if (e.mouseButton.button == sf::Mouse::Left) {

                    cout << e.mouseButton.x << endl;
                    cout << e.mouseButton.y << endl;
                    if (Exit.isClicked()) mainWindow.close();

                }
            }
            
            //ENTERING LOWER CASE LETTERS INTO THE ROW OF 5 PUZZLES
            if (e.type == Event::TextEntered && e.text.unicode > 96 && e.text.unicode < 123) {
                if (y >= 0 && y < 5 && !isGuessed) {
                    puzzles[x][y].setTexture(&Letters[e.text.unicode - 97]);
                    attempt += char(e.text.unicode);
                    y++;
                    cout << attempt << endl;
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
            else if (Keyboard::isKeyPressed(Keyboard::BackSpace) || Keyboard::isKeyPressed(Keyboard::Backspace)) {
                if (y != 0) {
                    y--;
                    puzzles[x][y].setTexture(&empty);
                    attempt = attempt.substr(0, attempt.length() - 1);
                }
            }
            else if (y == 0) {
                continue;
            }
        }

        mainWindow.clear(Color(237, 210, 183));
        mainWindow.draw(Exit.getButton());
        mainWindow.draw(WordleText);
        mainWindow.draw(Names);

        //LOSE CASE
        if (x > 4) {
            mainWindow.draw(youLost);
            mainWindow.draw(guess);
        }

        //WIN CASE
        if (isGuessed) mainWindow.draw(youWon);

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