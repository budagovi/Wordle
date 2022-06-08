#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main() {


    RenderWindow mainWindow(VideoMode(1200, 900), "Wordle", Style::Close);
    mainWindow.setKeyRepeatEnabled(false);
    mainWindow.setFramerateLimit(60);

    RectangleShape puzzles[5][5];

    CircleShape Exit;
    Exit.setRadius(40);
    Exit.setFillColor(Color(237, 210, 183));
    Exit.setPosition(1080, 20);
    Texture exit;
    exit.loadFromFile("C:/VisualStudio/Wordle/Wordle/Exit.png");
    Exit.setTexture(&exit);

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

    int x = 0;
    int y = 0;
    string word = "count";
    string attempt = "";
    string test(word);
    string result = "-----";

    Texture A;
    A.loadFromFile("C:/VisualStudio/Wordle/Wordle/A.jpg");
    Texture B;
    B.loadFromFile("C:/VisualStudio/Wordle/Wordle/B.jpg");
    Texture C;
    C.loadFromFile("C:/VisualStudio/Wordle/Wordle/C.jpg");
    Texture D;
    D.loadFromFile("C:/VisualStudio/Wordle/Wordle/D.png");
    Texture E;
    E.loadFromFile("C:/VisualStudio/Wordle/Wordle/E.png");
    Texture F;
    F.loadFromFile("C:/VisualStudio/Wordle/Wordle/F.png");
    Texture G;
    G.loadFromFile("C:/VisualStudio/Wordle/Wordle/G.png");
    Texture H;
    H.loadFromFile("C:/VisualStudio/Wordle/Wordle/H.png");
    Texture I;
    I.loadFromFile("C:/VisualStudio/Wordle/Wordle/I.png");
    Texture J;
    J.loadFromFile("C:/VisualStudio/Wordle/Wordle/J.png");
    Texture K;
    K.loadFromFile("C:/VisualStudio/Wordle/Wordle/K.png");
    Texture L;
    L.loadFromFile("C:/VisualStudio/Wordle/Wordle/L.png");
    Texture M;
    M.loadFromFile("C:/VisualStudio/Wordle/Wordle/M.png");
    Texture N;
    N.loadFromFile("C:/VisualStudio/Wordle/Wordle/N.png");
    Texture O;
    O.loadFromFile("C:/VisualStudio/Wordle/Wordle/O.png");
    Texture P;
    P.loadFromFile("C:/VisualStudio/Wordle/Wordle/P.png");
    Texture Q;
    Q.loadFromFile("C:/VisualStudio/Wordle/Wordle/Q.png");
    Texture R;
    R.loadFromFile("C:/VisualStudio/Wordle/Wordle/R.png");
    Texture S;
    S.loadFromFile("C:/VisualStudio/Wordle/Wordle/S.png");
    Texture T;
    T.loadFromFile("C:/VisualStudio/Wordle/Wordle/T.png");
    Texture U;
    U.loadFromFile("C:/VisualStudio/Wordle/Wordle/U.png");
    Texture V;
    V.loadFromFile("C:/VisualStudio/Wordle/Wordle/V.png");
    Texture W;
    W.loadFromFile("C:/VisualStudio/Wordle/Wordle/W.png");
    Texture X;
    X.loadFromFile("C:/VisualStudio/Wordle/Wordle/X.png");
    Texture Y;
    Y.loadFromFile("C:/VisualStudio/Wordle/Wordle/Y.png");
    Texture Z;
    Z.loadFromFile("C:/VisualStudio/Wordle/Wordle/Z.png");
    Texture empty;
    empty.loadFromFile("C:/VisualStudio/Wordle/Wordle/Bg.png");

    /*RectangleShape Pause;
    Pause.setSize(Vector2f(300, 100));
    Pause.setPosition(Vector2f(600, 450));
    Pause.setFillColor(Color::Red); */


    while (mainWindow.isOpen()) {

        Event e;


        while (mainWindow.pollEvent(e)) {
            if (e.type == Event::Closed)
                mainWindow.close();

            if (Keyboard::isKeyPressed(Keyboard::Escape)) mainWindow.close();

            if (e.type == sf::Event::MouseButtonPressed) {

                if (e.mouseButton.button == sf::Mouse::Left) {

                    cout << e.mouseButton.x << endl;
                    cout << e.mouseButton.y << endl;
                    if (e.mouseButton.x > 1080 && e.mouseButton.x < 1120 && e.mouseButton.y>20 && e.mouseButton.y < 60) mainWindow.close();

                }
            }

            if (e.type == Event::KeyPressed) {

                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&A);
                        attempt += 'a';
                        y++;
                    }
                    //else if (y == -1 || y > 5) continue;
                }
                else if (Keyboard::isKeyPressed(Keyboard::B)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&B);
                        attempt += 'b';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::C)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&C);
                        attempt += 'c';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&D);
                        attempt += 'd';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::E)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&E);
                        attempt += 'e';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::F)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&F);
                        attempt += 'f';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::G)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&G);
                        attempt += 'g';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::H)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&H);
                        attempt += 'h';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::I)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&I);
                        attempt += 'i';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::J)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&J);
                        attempt += 'j';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::K)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&K);
                        attempt += 'k';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::L)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&L);
                        attempt += 'l';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::M)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&M);
                        attempt += 'm';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::N)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&N);
                        attempt += 'n';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::O)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&O);
                        attempt += 'o';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::P)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&P);
                        attempt += 'p';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Q)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&Q);
                        attempt += 'q';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::R)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&R);
                        attempt += 'r';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::S)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&S);
                        attempt += 's';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::T)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&T);
                        attempt += 't';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::U)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&U);
                        attempt += 'u';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::V)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&V);
                        attempt += 'v';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::W)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&W);
                        attempt += 'w';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::X)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&X);
                        attempt += 'x';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Y)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&Y);
                        attempt += 'y';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Z)) {
                    if (y >= 0 && y < 5) {
                        puzzles[x][y].setTexture(&Z);
                        attempt += 'z';
                        y++;
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    if (attempt.length() != 5) {
                        y--;

                        y++;

                    }
                    else {
                        string h = "*****";
                        for (int j = 0; j < word.length(); ++j) {

                            for (int g = 0; g < h.length(); ++g) {
                                if (islower(h[g])) h[g] = '*';
                            }

                            if (h[j] == '*') {

                                if (attempt[j] != word[j]) {
                                    h[j] = '*';
                                }
                                if (attempt[j] == word[j]) {

                                    puzzles[count][j].setFillColor(Color(108, 218, 113));


                                    h[j] = char(int(word[j]) - 32);
                                    test[j] = '*';
                                }
                            }
                        }
                        //cout << "---- 1)  " << h << endl;
                        for (int j = 0; j < attempt.length(); ++j) {
                            for (int f = 0; f < word.length(); ++f) {
                                if (attempt[j] == test[f] && !isupper(h[j])) {

                                    puzzles[count][j].setFillColor(Color(236, 215, 124));
                                    h[j] = attempt[j];
                                }
                            }
                        }
                        count++;
                        attempt = "";

                        for (int j = 0; j < h.length(); ++j) {
                            if (isupper(h[j])) result[j] = char(h[j] + 32);
                        }
                       
                        if (attempt == word) {
                            mainWindow.close();
                        }

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

                //puzzles[x][y].setFillColor(Color::Blue);

                if (x == 5) mainWindow.close();   //needs to be edited


            }

            //puzzles[1][0].setFillColor(Color::Yellow);
        }

        mainWindow.clear(Color(221, 221, 221)); //grey

        mainWindow.clear(Color(237, 210, 183)); //grey

        mainWindow.draw(Exit);
        mainWindow.draw(WordleText);
        mainWindow.draw(Names);

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