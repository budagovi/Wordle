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

    int xCoordinate = 330, yCoordinate = 150, count = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            puzzles[i][j].setSize(Vector2f(100, 100));
            puzzles[i][j].setPosition(Vector2f(xCoordinate, yCoordinate));
            puzzles[i][j].setOutlineThickness(1);
            puzzles[i][j].setFillColor(Color(221, 221, 221));
            puzzles[i][j].setOutlineColor(Color::Black);
            xCoordinate += 110;
       }
        xCoordinate = 330;
        yCoordinate += 110;
    }
    
    int x = 0;
    int y = 0;
    string word="lucas";
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

    RectangleShape Pause;
    Pause.setSize(Vector2f(300, 100));
    Pause.setPosition(Vector2f(600, 450));
    Pause.setFillColor(Color::Red);


    while (mainWindow.isOpen()) {

        Event e;
      

        while (mainWindow.pollEvent(e)) {
            if (e.type == Event::Closed)
                mainWindow.close();          

            if (e.type == Event::KeyPressed) {

                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    puzzles[x][y].setTexture(&A);
                    attempt += 'a';
                }
                else if (Keyboard::isKeyPressed(Keyboard::B)) {
                    puzzles[x][y].setTexture(&B);
                    attempt += 'b';
                }
                else if (Keyboard::isKeyPressed(Keyboard::C)) {
                    puzzles[x][y].setTexture(&C);
                    attempt += 'c';
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)) {
                    puzzles[x][y].setTexture(&D);
                    attempt += 'd';
                }
                else if (Keyboard::isKeyPressed(Keyboard::E)) {
                    puzzles[x][y].setTexture(&E);
                    attempt += 'e';
                }
                else if (Keyboard::isKeyPressed(Keyboard::F)) {
                    puzzles[x][y].setTexture(&F);
                    attempt += 'f';
                }
                else if (Keyboard::isKeyPressed(Keyboard::G)) {
                    puzzles[x][y].setTexture(&G);
                    attempt += 'g';
                }
                else if (Keyboard::isKeyPressed(Keyboard::H)) {
                    puzzles[x][y].setTexture(&H);
                    attempt += 'h';
                }
                else if (Keyboard::isKeyPressed(Keyboard::I)) {
                    puzzles[x][y].setTexture(&I);
                    attempt += 'i';
                }
                else if (Keyboard::isKeyPressed(Keyboard::J)) {
                    puzzles[x][y].setTexture(&J);
                    attempt += 'j';
                }
                else if (Keyboard::isKeyPressed(Keyboard::K)) {
                    puzzles[x][y].setTexture(&K);
                    attempt += 'k';
                }
                else if (Keyboard::isKeyPressed(Keyboard::L)) {
                    puzzles[x][y].setTexture(&L);
                    attempt += 'l';
                }
                else if (Keyboard::isKeyPressed(Keyboard::M)) {
                    puzzles[x][y].setTexture(&M);
                    attempt += 'm';
                }
                else if (Keyboard::isKeyPressed(Keyboard::N)) {
                    puzzles[x][y].setTexture(&N);
                    attempt += 'n';
                }
                else if (Keyboard::isKeyPressed(Keyboard::O)) {
                    puzzles[x][y].setTexture(&O);
                    attempt += 'o';
                }
                else if (Keyboard::isKeyPressed(Keyboard::P)) {
                    puzzles[x][y].setTexture(&P);
                    attempt += 'p';
                }
                else if (Keyboard::isKeyPressed(Keyboard::Q)) {
                    puzzles[x][y].setTexture(&Q);
                    attempt += 'q';
                }
                else if (Keyboard::isKeyPressed(Keyboard::R)) {
                    puzzles[x][y].setTexture(&R);
                    attempt += 'r';
                }
                else if (Keyboard::isKeyPressed(Keyboard::S)) {
                    puzzles[x][y].setTexture(&S);
                    attempt += 's';
                }
                else if (Keyboard::isKeyPressed(Keyboard::T)) {
                    puzzles[x][y].setTexture(&T);
                    attempt += 't';
                }
                else if (Keyboard::isKeyPressed(Keyboard::U)) {
                    puzzles[x][y].setTexture(&U);
                    attempt += 'u';
                }
                else if (Keyboard::isKeyPressed(Keyboard::V)) {
                    puzzles[x][y].setTexture(&V);
                    attempt += 'v';
                }
                else if (Keyboard::isKeyPressed(Keyboard::W)) {
                    puzzles[x][y].setTexture(&W);
                    attempt += 'w';
                }
                else if (Keyboard::isKeyPressed(Keyboard::X)) {
                    puzzles[x][y].setTexture(&X);
                    attempt += 'x';
                }
                else if (Keyboard::isKeyPressed(Keyboard::Y)) {
                    puzzles[x][y].setTexture(&Y);
                    attempt += 'y';
                }
                else if (Keyboard::isKeyPressed(Keyboard::Z)) {
                    puzzles[x][y].setTexture(&Z);
                    attempt += 'z';
                }
                else if (Keyboard::isKeyPressed(Keyboard::Enter)) {
               
                string h = "*****";
                if (attempt.length() != 5) {
                    y--;
                }
                else {
                    for (int j = 0; j < word.length(); ++j) {

                        for (int g = 0; g < h.length(); ++g) {
                            if (islower(h[g])) h[g] = '*';
                        }

                        if (h[j] == '*') {

                            if (attempt[j] != word[j]) {
                                h[j] = '*';
                            }
                            if (attempt[j] == word[j]) {
                                puzzles[count][j].setFillColor(Color::Green);
                                h[j] = char(int(word[j]) - 32);
                                test[j] = '*';
                            }
                        }
                    }
                    //cout << "---- 1)  " << h << endl;
                    for (int j = 0; j < attempt.length(); ++j) {
                        for (int f = 0; f < word.length(); ++f) {
                            if (attempt[j] == word[f] && !isupper(h[j])) { 
                                puzzles[count][j].setFillColor(Color::Yellow);
                                h[j] = attempt[j]; 
                            }
                        }
                    }
                    count++;
                    attempt = "";

                    for (int j = 0; j < h.length(); ++j) {
                        if (isupper(h[j])) result[j] = char(h[j] + 32);
                    }

                    if (result == word) {
                        mainWindow.close();
                    }
                }
                
                }
                else if (Keyboard::isKeyPressed(Keyboard::BackSpace) || Keyboard::isKeyPressed(Keyboard::Backspace)) {
                if (y != 0 ) {
                    y--;
                    puzzles[x][y].setTexture(&empty);
                    y--;
                    attempt = attempt.substr(0, attempt.length() - 1);
                    }
                }
                else if (y == 0) {
                    continue;
                }

                //puzzles[x][y].setFillColor(Color::Blue);
                
                if (x == 4 && y == 4) mainWindow.close();   //needs to be edited
                if (y < 5) y++;
                else {
                    y = 0;
                    x++;
                }
                
            }
        }

        mainWindow.clear(Color(221, 221, 221)); //grey

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                mainWindow.draw(puzzles[i][j]);
            }
        }

        mainWindow.display();
    }

 
    
    return 0;
}