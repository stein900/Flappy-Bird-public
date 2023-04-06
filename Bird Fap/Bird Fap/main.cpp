#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Bird Flap");
    sf::Clock clock;

    // D�finition des chemins d'acc�s des fichiers de ressources

    const std::string Background = "C:/Game/resources/Background.png";

    const std::string Bird1 = "C:/Game/resources/pngwing.png";
    const std::string Bird2 = "C:/Game/resources/bird flap high.png";
    const std::string Bird3 = "C:/Game/resources/Royal Eagle Jerl.png";
    const std::string Bird4 = "C:/Game/resources/Skin viking .png";
    const std::string Bird5 = "C:/Game/resources/Skin class bird.png";
    const std::string Bird6 = "C:/Game/resources/Skin samurai bird.png";
    const std::string Bird7 = "C:/Game/resources/Skin flying fish.png";
    const std::string Bird8 = "C:/Game/resources/Skin monkey.png";
    const std::string Bird9 = "C:/Game/resources/Skin flying Squirel.png";
    const std::string Bird10 = "C:/Game/resources/Skin manga ref.png";
    const std::string Bird11 = "C:/Game/resources/Skin pegas.png";
    const std::string Bird12 = "C:/Game/resources/Skin Minou.png";

    const std::string pipeUP = "C:/Game/resources/sgsgvssdrg - Copie.png";
    const std::string pipeDOWN = "C:/Game/resources/sgsgvssdrg.png";

    const std::string cloud1 = "C:/Game/resources/12-cloud-png-image.png";
    const std::string cloud2 = "C:/Game/resources/19-cloud-png-image.png";
    const std::string cloud3 = "C:/Game/resources/30-white-clouds-png-image.png";
    const std::string cloud4 = "C:/Game/resources/rain-clouds-png-27.png";

    const std::string aviondeChasse = "C:/Game/resources/Avion de chasse de passage.png";

    const std::string MenuS = "C:/Game/resources/Principal Menu 2.png";
    const std::string LockerS = "C:/Game/resources/Locker casier.png";
    const std::string GAMEOVERS = "C:/Game/resources/Game Over 2.png";

    const std::string Building1 = "C:/Game/resources/pngegg (1).png";
    const std::string Building2 = "C:/Game/resources/pngegg (2).png";

    const std::string Montain1 = "C:/Game/resources/Montaine1.png";
    const std::string Montain2 = "C:/Game/resources/Montaine2.png";
    const std::string Montain3 = "C:/Game/resources/Montaine3.png";

    const std::string FontT = "C:/Game/resources/arial.ttf";

    // Charger les textures
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(Background);
    /* sf::Texture birdTexture, birdTexture2;
     birdTexture.loadFromFile("X:/tout le reste/Images, videos et musiques/bird flap high.png") || birdTexture2.loadFromFile("X:/tout le reste/Images, videos et musiques/bird flap low.png");*/
    sf::Texture birdTexture, birdTexture2, birdTexture3, birdTexture4, birdTexture5, birdTexture6, birdTexture7, birdTexture8, birdTexture9, birdTexture10, birdTexture11, birdTexture12, birdTexture13, birdTexture14;
    if (!birdTexture2.loadFromFile(Bird3) || !birdTexture.loadFromFile(Bird2) || !birdTexture3.loadFromFile(Bird2) || !birdTexture4.loadFromFile(Bird1) || !birdTexture5.loadFromFile(Bird4) || !birdTexture6.loadFromFile(Bird5) || !birdTexture7.loadFromFile(Bird6) || !birdTexture8.loadFromFile(Bird7) || !birdTexture9.loadFromFile(Bird8) || !birdTexture10.loadFromFile(Bird9) || !birdTexture11.loadFromFile(Bird9) || !birdTexture12.loadFromFile(Bird10) || !birdTexture13.loadFromFile(Bird11) || !birdTexture14.loadFromFile(Bird12))
    {
        return 1; // Erreur de chargement de l'image
    }
    sf::Texture pipeTexture;
    pipeTexture.loadFromFile(pipeDOWN);
    sf::Texture pipeTexture2;
    pipeTexture2.loadFromFile(pipeUP);

    // Cr�er les sprites
    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Sprite birdSprite(birdTexture);
    sf::Sprite birdSprite2(birdTexture2);
    sf::Sprite birdSprite3(birdTexture3);
    sf::Sprite birdSprite4(birdTexture4);
    sf::Sprite pipeUpSprite(pipeTexture2);
    sf::Sprite pipeDownSprite(pipeTexture);

    // Positionner les sprites
    backgroundSprite.setPosition(0, 0);
    birdSprite.setPosition(50, 400);
    pipeUpSprite.setPosition(600, -500);
    pipeDownSprite.setPosition(600, 600);

    pipeUpSprite.setScale(0.000059, .000001);
    pipeDownSprite.setScale(0.00000059, .000001);
    birdSprite.setScale(.00004, .000004);
    birdSprite.setTexture(birdTexture4);

    //---------------------------------------------Musique----------------------------------------------------

    //    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("C:/Game/resources/Music/Profano.wav"))
    //    return EXIT_FAILURE;


    //music.setLoop(window.isOpen());

    //// Play the music
    //music.play();


        // Load a music to play
        sf::Music JumpSong;
    if (!JumpSong.openFromFile("C:/Game/resources/Music/Flappy Jump song.wav"))
        return EXIT_FAILURE;

    // Load a music to play
    sf::Music HurtSong;
    if (!HurtSong.openFromFile("C:/Game/resources/Music/Flappy hurt song.wav"))
        return EXIT_FAILURE;

    bool spacePressedLastFrame = false;

    //--------------------------------Les nuages----------------------------------------------

    // Charger l'image
    sf::Texture clouds;
    if (!clouds.loadFromFile(cloud4))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss(clouds);

    // Charger l'image
    sf::Texture clouds2;
    if (!clouds2.loadFromFile(cloud3))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss2(clouds2);
    cloudss2.setPosition(354, 394);


    // Charger l'image
    sf::Texture clouds3;
    if (!clouds3.loadFromFile(cloud2))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss3(clouds3);

    // Charger l'image
    sf::Texture clouds4;
    if (!clouds4.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss4(clouds4);


    // Charger l'image
    sf::Texture clouds6;
    if (!clouds6.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss6(clouds6);

    cloudss6.setPosition(200.f, 200.f);


    // Charger l'image
    sf::Texture clouds7;
    if (!clouds7.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss7(clouds7);

    sf::Color couleur = cloudss7.getColor();
    couleur.a = 128; // valeur alpha de 128 (50% de transparence)
    cloudss7.setColor(couleur);



    // Charger l'image
    sf::Texture clouds72;
    if (!clouds72.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss72(clouds72);
    cloudss72.setColor(couleur);

    // Charger l'image
    sf::Texture clouds73;
    if (!clouds73.loadFromFile(cloud3))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss73(clouds73);
    cloudss73.setColor(couleur);
    cloudss73.setPosition(20, 190);



    // Charger l'image
    sf::Texture clouds733;
    if (!clouds733.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss733(clouds733);
    cloudss733.setColor(couleur);

    cloudss733.setPosition(200, 452);




    // Charger l'image
    sf::Texture clouds8;
    if (!clouds8.loadFromFile(cloud3))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss8(clouds8);
    cloudss8.setPosition(120, 325);

    // Charger l'image
    sf::Texture clouds9;
    if (!clouds9.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss9(clouds9);

    // Charger l'image
    sf::Texture clouds10;
    if (!clouds10.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss10(clouds10);

    // Charger l'image
    sf::Texture clouds100;
    if (!clouds100.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss100(clouds100);

    cloudss100.setPosition(-600, 0);


    // Charger l'image
    sf::Texture clouds101;
    if (!clouds101.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss101(clouds101);

    cloudss101.setPosition(-660, 0);

    // Charger l'image
    sf::Texture clouds11;
    if (!clouds11.loadFromFile(cloud1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss11(clouds11);

    // Charger l'image
    sf::Texture clouds12;
    if (!clouds12.loadFromFile(cloud3))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite cloudss12(clouds12);

    cloudss12.setPosition(250, 452);


    // Charger l'image
    sf::Texture avionChasse;
    if (!avionChasse.loadFromFile(aviondeChasse))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite avionChassee(avionChasse);

    avionChassee.setScale(.1, .1);
    avionChassee.setPosition(586, 321);


    //--------------------------------------------MENU ET AFFICHAGE----------------------------------------------------

    // Charger GAME OVER
    sf::Texture textOV;
    if (!textOV.loadFromFile(GAMEOVERS))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite textOVV(textOV);


    // D�finir l'�chelle de l'image
    textOVV.setScale(.005f, .005f); // Double la taille de l'image
    textOVV.setPosition(3000, -3000);

    // Charger Menu Principal
    sf::Texture textOV2;
    if (!textOV2.loadFromFile(MenuS))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite textOVV2(textOV2);


    // D�finir l'�chelle de l'image
    textOVV2.setScale(.31f, .31f);
    textOVV2.setPosition(2, 200);


    // Charger le casier
    sf::Texture locker;
    if (!locker.loadFromFile(LockerS))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite lockerr(locker);


    // D�finir l'�chelle de l'image
    lockerr.setScale(.005f, .005f);
    lockerr.setPosition(3000, -3000);


    //-----------------------------------------building---------------------------------------------------

        // Charger l'image
    sf::Texture building1;
    if (!building1.loadFromFile(Building1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite buildingg1(building1);
    buildingg1.setPosition(600, 500);

    // Charger l'image
    sf::Texture building2;
    if (!building2.loadFromFile(Building2))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite buildingg2(building2);
    buildingg2.setPosition(300, 300);

    // Charger l'image
    sf::Texture building3;
    if (!building3.loadFromFile(Building2))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite buildingg3(building3);
    buildingg3.setPosition(450, 300);


    // Charger l'image
    sf::Texture Montaine1;
    if (!Montaine1.loadFromFile(Montain2))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite Montainee1(Montaine1);
    Montainee1.setPosition(300, 550);
    Montainee1.setScale(1, 1);


    // Charger l'image
    sf::Texture Montaine2;
    if (!Montaine2.loadFromFile(Montain1))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite Montainee2(Montaine2);
    Montainee2.setPosition(-250, 500);

    // Charger l'image
    sf::Texture Montaine3;
    if (!Montaine3.loadFromFile(Montain3))
    {
        return 1; // Erreur de chargement de l'image
    }

    // Cr�er le sprite (l'image affich�e dans la fen�tre)
    sf::Sprite Montainee3(Montaine3);
    Montainee3.setPosition(600, 500);

    // Vitesse de l'oiseau
    float birdSpeed = 0;
    int level = 0;

    //-----------------------------------------Animation rotation--------------------------------------------------------

    float angle = 0.0f;


    //---------------------------------------------------------syst�me de score-----------------------------------------------------------------

    int score = 0;

    sf::Font font;
    font.loadFromFile(FontT);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(34);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(-250, -510);

    sf::Clock clock2;
    float elapsed2 = 0.0f;

    //r�sulat du score
    int scoreRes = 0;
    sf::Font font2;
    font2.loadFromFile(FontT);
    sf::Text scoreTextR;
    scoreTextR.setFont(font2);
    scoreTextR.setCharacterSize(24);
    scoreTextR.setFillColor(sf::Color::Black);
    scoreTextR.setStyle(sf::Text::Bold);
    scoreTextR.setPosition(-250, -510);


    //Best score
    sf::Font font3;
    font3.loadFromFile(FontT);
    sf::Text bestscoreTextR;
    bestscoreTextR.setFont(font3);
    bestscoreTextR.setCharacterSize(24);
    bestscoreTextR.setFillColor(sf::Color::Black);
    bestscoreTextR.setStyle(sf::Text::Bold);
    bestscoreTextR.setPosition(180, 100);


    //Best score
    sf::Font font4;
    font4.loadFromFile(FontT);
    sf::Text LockerText;
    LockerText.setFont(font4);
    LockerText.setString("Press 'L' for open the locker");
    LockerText.setCharacterSize(24);
    LockerText.setFillColor(sf::Color::Black);
    LockerText.setStyle(sf::Text::Bold);
    LockerText.setPosition(130, 650);

    //Best score
    sf::Font font5;
    font5.loadFromFile(FontT);
    sf::Text levelGameTexte;
    levelGameTexte.setFont(font5);
    levelGameTexte.setCharacterSize(24);
    levelGameTexte.setFillColor(sf::Color::Black);
    levelGameTexte.setStyle(sf::Text::Bold);
    levelGameTexte.setPosition(450, 10);


    //Best score
    sf::Font font6;
    font6.loadFromFile(FontT);
    sf::Text LockerDescriptiontext;
    LockerDescriptiontext.setFont(font6);
    LockerDescriptiontext.setString("you can choose a skin by pressing a button according to your level and your best score.");
    LockerDescriptiontext.setCharacterSize(12);
    LockerDescriptiontext.setFillColor(sf::Color::Black);
    LockerDescriptiontext.setStyle(sf::Text::Bold);
    LockerDescriptiontext.setPosition(-5214, -5421);


    //Best score
    sf::Font font7;
    font7.loadFromFile(FontT);
    sf::Text Notenough;
    Notenough.setFont(font7);
    Notenough.setString("Not enough.");
    Notenough.setCharacterSize(56);
    Notenough.setFillColor(sf::Color::Red);
    Notenough.setStyle(sf::Text::Bold);
    Notenough.setPosition(-5214, -5421);


    //-------------------------------------------------------Sauvegarde du score---------------------------------------------------------

    // Chargement du score � partir du fichier "score.txt"
    int BestScore = 0;
    std::ifstream inputFile("score.txt");
    if (inputFile.is_open()) {
        inputFile >> BestScore;
        inputFile.close();
    }
    bestscoreTextR.setString("your best score is: " + std::to_string(BestScore));

    //--------------------------------------Sauvegarde du level-------------------------------------------------


    // Chargement du score � partir du fichier "score.txt"
    int levelGame = 0;
    std::ifstream inputFile2("level.txt");
    if (inputFile2.is_open()) {
        inputFile2 >> levelGame;
        inputFile2.close();
    }
    levelGameTexte.setString("level: " + std::to_string(levelGame));

    // Boucle principale du jeu
    while (window.isOpen())
    {
        // G�rer les �v�nements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space || event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {

                if (level == 1)
                {
                    // L'oiseau saute quand la touche Espace est press�e
                    birdSpeed = -10;
                    //-----------------------------------------Animation rotation--------------------------------------------------------
                    //angle -= 25.0f;
                    /*birdSprite.setTexture(birdTexture);*/
                }

                else if (level == 2)
                {
                    // L'oiseau saute quand la touche Espace est press�e
                    birdSpeed = -12;
                    //-----------------------------------------Animation rotation--------------------------------------------------------
                    //angle -= 25.0f;
                }

                else if (level == 3)
                {
                    // L'oiseau saute quand la touche Espace est press�e
                    birdSpeed = -13;
                    //-----------------------------------------Animation rotation--------------------------------------------------------
                    //angle -= 25.0f;
                }



            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N)
            {
                int score = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreTextR.setPosition(-250, -510);
                scoreText.setPosition(223, 10);
                backgroundSprite.setPosition(0, 0);
                birdSprite.setPosition(50, 400);
                pipeUpSprite.setPosition(600, -500);
                pipeDownSprite.setPosition(600, 600);
                textOVV.setScale(.005f, .005f);
                textOVV.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                birdSprite.setScale(.04, .04);
                birdSprite2.setScale(.04, .04);
                textOVV2.setScale(.005f, .005f);
                textOVV2.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                lockerr.setScale(.005f, .005f);
                lockerr.setPosition(3000, -3000);
                LockerText.setPosition(-5130, -4650);
                LockerDescriptiontext.setPosition(-5214, -5421);
                Notenough.setPosition(-5214, -5421);
                window.display();

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            {
                level = 1;
                score = 0;
                birdSpeed = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreText.setPosition(223, 10);
                scoreTextR.setPosition(-250, -510);
                backgroundSprite.setPosition(0, 0);
                birdSprite.setPosition(50, 400);
                pipeUpSprite.setPosition(600, -500);
                pipeDownSprite.setPosition(600, 600);
                textOVV.setScale(.005f, .005f);
                textOVV.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                birdSprite.setScale(.04, .04);
                birdSprite.setTexture(birdTexture4);
                textOVV2.setScale(.005f, .005f);
                textOVV2.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                lockerr.setScale(.005f, .005f);
                lockerr.setPosition(3000, -3000);
                LockerText.setPosition(-5130, -4650);
                LockerDescriptiontext.setPosition(-5214, -5421);
                Notenough.setPosition(-5214, -5421);
                window.display();

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z || event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                level = 2;
                score = 0;
                birdSpeed = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreText.setPosition(223, 10);
                scoreTextR.setPosition(-250, -510);
                backgroundSprite.setPosition(0, 0);
                birdSprite.setPosition(50, 400);
                pipeUpSprite.setPosition(600, -500);
                pipeDownSprite.setPosition(600, 600);
                textOVV.setScale(.005f, .005f);
                textOVV.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                birdSprite.setScale(.04, .04);
                birdSprite.setTexture(birdTexture3);
                textOVV2.setScale(.005f, .005f);
                textOVV2.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                lockerr.setScale(.005f, .005f);
                LockerText.setPosition(-5130, -4650);
                LockerDescriptiontext.setPosition(-5214, -5421);
                lockerr.setPosition(3000, -3000);
                Notenough.setPosition(-5214, -5421);
                window.display();

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
            {
                level = 3;
                score = 0;
                birdSpeed = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreText.setPosition(223, 10);
                scoreTextR.setPosition(-250, -510);
                backgroundSprite.setPosition(0, 0);
                birdSprite.setPosition(50, 400);
                pipeUpSprite.setPosition(600, -500);
                pipeDownSprite.setPosition(600, 600);
                textOVV.setScale(.005f, .005f);
                textOVV.setPosition(3000, -3000);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                birdSprite.setTexture(birdTexture2);
                birdSprite.setScale(.06, .06);
                textOVV2.setScale(.005f, .005f);
                textOVV2.setPosition(3000, -3000);
                LockerText.setPosition(-5130, -4650);
                pipeUpSprite.setScale(0.59, 1);
                pipeDownSprite.setScale(0.59, 1);
                lockerr.setScale(.005f, .005f);
                LockerDescriptiontext.setPosition(-5214, -5421);
                Notenough.setPosition(-5214, -5421);
                lockerr.setPosition(3000, -3000);
                window.display();

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
            {
                score = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreText.setPosition(223, 10);
                scoreTextR.setPosition(-250, -510);
                scoreText.setPosition(-5223, -510);
                scoreTextR.setPosition(-250, -510);
                birdSprite.setScale(.00005f, .000005);
                textOVV2.setScale(.31f, .31f);
                textOVV2.setPosition(5, 200);
                textOVV.setScale(.005f, .005f);
                textOVV.setPosition(3000, -3000);
                lockerr.setScale(.005f, .005f);
                lockerr.setPosition(3000, -3000);
                LockerText.setPosition(130, 650);
                LockerDescriptiontext.setPosition(-5214, -5421);
                pipeUpSprite.move(0, 0);
                Notenough.setPosition(-5214, -5421);
                pipeDownSprite.move(0, 0);

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
            {
                score = 0;
                bestscoreTextR.setPosition(-250, -510);
                scoreText.setPosition(-5223, -510);
                scoreTextR.setPosition(-250, -510);
                birdSprite.setScale(.00005f, .000005);
                lockerr.setScale(.39f, .39f);
                lockerr.setPosition(-6, 150);
                pipeUpSprite.move(0, 0);
                pipeDownSprite.move(0, 0);
                textOVV2.setScale(-5687.5431f, -558.31f);
                textOVV2.setPosition(-5815, -6200);
                LockerText.setPosition(-5130, -4650);
                textOVV.setScale(-5687.5431f, -558.31f);
                Notenough.setPosition(-5214, -5421);
                textOVV.setPosition(-5815, -6200);
                LockerDescriptiontext.setPosition(30, 100);
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
            {

                if (BestScore >= 15)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    LockerText.setPosition(-5130, -4650);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture5);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.06, .06);
                    Notenough.setPosition(-5214, -5421);
                    window.display();
                }

                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
            {

                if (BestScore >= 20)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    LockerText.setPosition(-5130, -4650);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    birdSprite.setTexture(birdTexture6);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    Notenough.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    birdSprite.setScale(.06, .06);
                    window.display();
                }

                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Y)
            {
                if (BestScore >= 25)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    LockerText.setPosition(-5130, -4650);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture7);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    Notenough.setPosition(-5214, -5421);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    birdSprite.setScale(.06, .06);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U)
            {
                if (levelGame >= 500 && BestScore >= 30)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    LockerText.setPosition(-5130, -4650);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture8);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    Notenough.setPosition(-5214, -5421);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.06, .06);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
            {
                if (BestScore >= 36)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture9);
                    textOVV2.setScale(.005f, .005f);
                    LockerText.setPosition(-5130, -4650);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    textOVV2.setPosition(3000, -3000);
                    birdSprite.setScale(.06, .06);
                    pipeUpSprite.setScale(0.59, 1);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    Notenough.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O)
            {
                if (levelGame >= 800)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture10);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    Notenough.setPosition(-5214, -5421);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    LockerText.setPosition(-5130, -4650);
                    birdSprite.setScale(.06, .06);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }
            }

            //else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            //{
            //    if (levelGame >= 2000 && BestScore >= 45)
            //    {
            //        level = 2;
            //        score = 0;
            //        bestscoreTextR.setPosition(-250, -510);
            //        scoreText.setPosition(223, 10);
            //        scoreTextR.setPosition(-250, -510);
            //        backgroundSprite.setPosition(0, 0);
            //        birdSprite.setPosition(50, 400);
            //        pipeUpSprite.setPosition(600, -500);
            //        pipeDownSprite.setPosition(600, 600);
            //        textOVV.setScale(.005f, .005f);
            //        lockerr.setScale(.005f, .005f);
            //        lockerr.setPosition(3000, -3000);
            //        textOVV.setPosition(3000, -3000);
            //        pipeUpSprite.setScale(0.59, 1);
            //        pipeDownSprite.setScale(0.59, 1);
            //        birdSprite.setScale(.04, .04);
            //        birdSprite.setTexture(birdTexture11);
            //        textOVV2.setScale(.005f, .005f);
            //        textOVV2.setPosition(3000, -3000);
            //        LockerText.setPosition(-5130, -4650);
            //        birdSprite.setScale(.06, .06);
            //        pipeUpSprite.setScale(0.59, 1);
            //        pipeDownSprite.setScale(0.59, 1);
            //        window.display();
            //    }


            //}

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
            {
                if (levelGame >= 2000 && BestScore >= 45)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    lockerr.setScale(.005f, .005f);
                    LockerText.setPosition(-5130, -4650);
                    lockerr.setPosition(3000, -3000);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture12);
                    textOVV2.setScale(.005f, .005f);
                    birdSprite.setScale(.06, .06);
                    textOVV2.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    Notenough.setPosition(-5214, -5421);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
            {
                if (levelGame >= 5000)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    lockerr.setScale(.005f, .005f);
                    lockerr.setPosition(3000, -3000);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    LockerText.setPosition(-5130, -4650);
                    pipeDownSprite.setScale(0.59, 1);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture13);
                    textOVV2.setScale(.005f, .005f);
                    Notenough.setPosition(-5214, -5421);
                    textOVV2.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    birdSprite.setScale(.06, .06);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
            {
                if (levelGame >= 10000 && BestScore >= 70)
                {
                    level = 2;
                    score = 0;
                    birdSpeed = 0;
                    bestscoreTextR.setPosition(-250, -510);
                    scoreText.setPosition(223, 10);
                    scoreTextR.setPosition(-250, -510);
                    backgroundSprite.setPosition(0, 0);
                    birdSprite.setPosition(50, 400);
                    pipeUpSprite.setPosition(600, -500);
                    pipeDownSprite.setPosition(600, 600);
                    textOVV.setScale(.005f, .005f);
                    textOVV.setPosition(3000, -3000);
                    pipeUpSprite.setScale(0.59, 1);
                    pipeDownSprite.setScale(0.59, 1);
                    lockerr.setScale(.005f, .005f);
                    LockerText.setPosition(-5130, -4650);
                    lockerr.setPosition(3000, -3000);
                    birdSprite.setScale(.04, .04);
                    birdSprite.setTexture(birdTexture14);
                    textOVV2.setScale(.005f, .005f);
                    textOVV2.setPosition(3000, -3000);
                    birdSprite.setScale(.06, .06);
                    LockerDescriptiontext.setPosition(-5214, -5421);
                    pipeUpSprite.setScale(0.59, 1);
                    Notenough.setPosition(-5214, -5421);
                    pipeDownSprite.setScale(0.59, 1);
                    window.display();
                }
                else
                {
                    Notenough.setPosition(150, 30);
                }

            }

            //------------------------------------------Cheat pour les teste----------------------------------------------------

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K)
            {
                BestScore += 99999;
                levelGame += 99999;

            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J)
            {
                BestScore -= 99999;
                levelGame -= 99999;
            }
        }
        //// V�rifier si 1 seconde s'est �coul�e
        //if (clock.getElapsedTime().asSeconds() >= .005f)
        //{
        //    // Alterner les sprites
        //    if (birdSprite.getTexture() == &birdTexture)
        //    {
        //        birdSprite.setTexture(birdTexture2);
        //    }
        //    // R�initialiser l'horloge
        //    clock.restart();
        //}

        //---------------------------------------------------------syst�me de score-----------------------------------------------------------------

        // Mettre � jour le score toutes les 1.6 secondes
        elapsed2 += clock2.restart().asSeconds();
        if (elapsed2 >= 1.6f) {
            score++;
            elapsed2 -= 1.6f;
        }

        // Mettre � jour le texte affich� � l'�cran
        scoreText.setString("Score: " + std::to_string(score));


        //----------------------------------------son dynamique-----------------------------------------------------------

        // V�rifier si la touche espace est enfonc�e
        bool spacePressedThisFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

        // Jouer le son si la touche espace vient juste d'�tre rel�ch�e
        if (!spacePressedLastFrame && spacePressedThisFrame)
        {
            JumpSong.play();
        }

        spacePressedLastFrame = spacePressedThisFrame;

        //---------------------------------------Les spawns des nuages, les trajectoires al�atoire et leurs vitesses---------------------------------------------------

        window.draw(cloudss);
        sf::Vector2f cloudPosition52 = cloudss.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition52.x < -280) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss.move(-1.9, 0); //Bouge vers la gauche

        window.draw(birdSprite);
        sf::Vector2f cloudPosition = birdSprite.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition.y > 800) //si c'est � gauche de l'�cran en hors champs
        {

        }

        window.draw(cloudss2);
        sf::Vector2f cloudPosition2 = cloudss2.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition2.x < -480) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss2.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss2.move(-1.2, 0); //Bouge vers la gauche

        window.draw(cloudss3);
        sf::Vector2f cloudPosition3 = cloudss3.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition3.x < -1760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss3.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss3.move(-1.2, 0); //Bouge vers la gauche

        window.draw(cloudss4);
        sf::Vector2f cloudPosition4 = cloudss4.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition4.x < -1760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss4.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss4.move(-3.2, 0); //Bouge vers la gauche

        window.draw(cloudss6);
        sf::Vector2f cloudPosition6 = cloudss6.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition6.x < -1760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss6.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss6.move(-3.2, 0); //Bouge vers la gauche

        window.draw(cloudss7);
        sf::Vector2f cloudPosition7 = cloudss7.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition7.x < -760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss7.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss7.move(-.09, 0); //Bouge vers la gauche

        window.draw(cloudss72);
        sf::Vector2f cloudPosition72 = cloudss7.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition72.x < -760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss72.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss72.move(-.01, 0); //Bouge vers la gauche

        window.draw(cloudss73);
        sf::Vector2f cloudPosition73 = cloudss73.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition73.x < -460) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss73.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss73.move(-1.3, 0); //Bouge vers la gauche


        window.draw(cloudss733);
        sf::Vector2f cloudPosition723 = cloudss733.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition723.x < -760) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss733.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss733.move(-.01, -.2); //Bouge vers la gauche

        window.draw(cloudss8);
        sf::Vector2f cloudPosition8 = cloudss8.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition8.x < -460) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss8.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss8.move(-1.2, 0); //Bouge vers la gauche

        window.draw(cloudss9);
        sf::Vector2f cloudPosition9 = cloudss9.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition9.x < -3000) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 680) + 20; //prend une hauteur al�atoire
            cloudss9.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss9.move(-2.2, 0); //Bouge vers la gauche

        window.draw(cloudss10);
        sf::Vector2f cloudPosition10 = cloudss10.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition10.x < -3000) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 70) + 20; //prend une hauteur al�atoire
            cloudss10.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss10.move(-.001, 0); //Bouge vers la gauche

        window.draw(cloudss11);
        sf::Vector2f cloudPosition11 = cloudss11.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition11.x < -1650) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 70) + 20; //prend une hauteur al�atoire
            cloudss11.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss11.move(-3.1, 0); //Bouge vers la gauche

        window.draw(cloudss12);
        sf::Vector2f cloudPosition12 = cloudss12.getPosition(); //Recup la position de la pok�ball
        if (cloudPosition12.x < -460) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 70) + 20; //prend une hauteur al�atoire
            cloudss12.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        cloudss12.move(-2.2, 0); //Bouge vers la gauche

        window.draw(avionChassee);
        sf::Vector2f avionChassee1 = avionChassee.getPosition(); //Recup la position de la pok�ball
        if (avionChassee1.x < -5460) //si c'est � gauche de l'�cran en hors champs
        {
            int y = (rand() % 800) + 20; //prend une hauteur al�atoire
            avionChassee.setPosition(sf::Vector2f(1000, y)); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        avionChassee.move(-10.2, 0); //Bouge vers la gauche


        //-------------------------------------------------------------Loop building------------------------------------------------------------


        buildingg1.move(-2, 0);
        buildingg2.move(-1.2, 0);
        buildingg3.move(-.9, 0);
        Montainee1.move(-.2, 0);
        Montainee2.move(-.6, 0);
        Montainee3.move(-.8, 0);


        window.draw(buildingg1);
        sf::Vector2f BuildingPosition1 = buildingg1.getPosition(); //Recup la position de la pok�ball
        if (BuildingPosition1.x < -1000) //si c'est � gauche de l'�cran en hors champs
        {
            buildingg1.setPosition(1000, 500); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        }
        buildingg1.move(-.01, 0); //Bouge vers la gauche

        //window.draw(buildingg2);
        //sf::Vector2f BuildingPosition2 = buildingg2.getPosition(); //Recup la position de la pok�ball
        //if (BuildingPosition2.x < -1000) //si c'est � gauche de l'�cran en hors champs
        //{
        //    buildingg2.setPosition(1000, 500); //Remet la pok�ball � droite hors champs � la hauteur pioch�e au dessus
        //}
        //buildingg2.move(-.01, 0); //Bouge vers la gauche

        if (buildingg2.getPosition().x < -1500)
        {
            buildingg2.setPosition(600, 300);
        }

        if (buildingg3.getPosition().x < -1500)
        {
            buildingg3.setPosition(600, 300);
        }

        if (Montainee1.getPosition().x < -1000)
        {
            Montainee1.setPosition(600, 550);
        }

        if (Montainee2.getPosition().x < -1000)
        {
            Montainee2.setPosition(600, 500);
        }

        if (Montainee3.getPosition().x < -1000)
        {
            Montainee3.setPosition(600, 500);
        }

        //// V�rifier si 1 seconde s'est �coul�e
        //if (clock.getElapsedTime().asSeconds() >= .005f)
        //{
        //    birdSprite.setTexture(birdTexture2);
        //    // R�initialiser l'horloge
        //    clock.restart();
        //}



        // Mettre � jour la position de l'oisa
        birdSpeed += 0.5;
        birdSprite.move(0, birdSpeed);

        //-----------------------------------------Animation rotation--------------------------------------------------------

        //static sf::Clock clock4;
        //birdSprite.setRotation(angle);
        //if (clock4.getElapsedTime().asSeconds() < 0.9)
        //{
        //    angle = +25.0;
        //} clock4.restart();



        // Mettre � jour la position des tuyaux tah les mario
        pipeUpSprite.move(-7.1, 0);
        pipeDownSprite.move(-7.1, 0);

        // Recycler les tuyaux quand ils sortent de l'�cran
        if (pipeUpSprite.getPosition().x < -100)
        {
            int y = (rand() % 800 + 100);
            pipeUpSprite.setPosition(sf::Vector2f(600, y - 1090));
            pipeDownSprite.setPosition(sf::Vector2f(600, y));
        }

        //------------------------------------------Sauvegarde du score-------------------------------------------------------

        static sf::Clock clock3;
        if (clock3.getElapsedTime().asSeconds() > 5) {
            std::ofstream outputFile("score.txt");
            if (outputFile.is_open())
            {
                outputFile << BestScore;
                outputFile.close();
            }
            clock3.restart();
        }


        static sf::Clock clock6;
        if (clock6.getElapsedTime().asSeconds() > 5) {
            std::ofstream outputFile2("level.txt");
            if (outputFile2.is_open())
            {
                outputFile2 << levelGame;
            }
            clock6.restart();
        }



        // sprite �a mere
        window.clear();
        window.draw(backgroundSprite);
        window.draw(Montainee1);
        window.draw(Montainee3);
        window.draw(Montainee2);
        window.draw(cloudss12);
        window.draw(buildingg3);
        window.draw(buildingg2);
        window.draw(buildingg1);
        window.draw(avionChassee);
        /*    window.draw(cloudss100);*/
        window.draw(cloudss101);
        window.draw(cloudss);
        window.draw(cloudss3);
        window.draw(cloudss4);
        window.draw(cloudss6);
        window.draw(cloudss8);
        /*window.draw(cloudss9);*/
        window.draw(cloudss7);
        window.draw(cloudss72);
        window.draw(cloudss73);
        window.draw(cloudss733);
        window.draw(cloudss2);
        window.draw(cloudss11);
        window.draw(pipeUpSprite);
        window.draw(pipeDownSprite);
        window.draw(birdSprite);
        window.draw(textOVV);
        window.draw(textOVV2);
        window.draw(scoreText);
        window.draw(scoreTextR);
        window.draw(LockerText);
        window.draw(lockerr);
        window.draw(bestscoreTextR);
        window.draw(levelGameTexte);
        window.draw(LockerDescriptiontext);
        window.draw(Notenough);


        window.display();

        // colision la
        if (birdSprite.getGlobalBounds().intersects(pipeUpSprite.getGlobalBounds())
            || birdSprite.getGlobalBounds().intersects(pipeDownSprite.getGlobalBounds()))
        {
            // Play the music
            HurtSong.play();

            if (BestScore < score)
            {
                BestScore = score;

            }

            if (score >= 2)
            {
                levelGame += score;
            }

            scoreRes = score;
            scoreTextR.setString("your current score is : " + std::to_string(scoreRes));
            bestscoreTextR.setString("your best score is: " + std::to_string(BestScore));
            scoreTextR.setPosition(160, 50);
            bestscoreTextR.setPosition(180, 100);
            levelGameTexte.setString("level: " + std::to_string(levelGame));
            score = 0;
            scoreText.setPosition(-250, -510);
            birdSprite.setScale(.00005f, .000005);
            textOVV.setScale(.31f, .31f);
            textOVV.setPosition(2, 200);
            LockerText.setPosition(130, 650);
            pipeUpSprite.move(0, 0);
            pipeDownSprite.move(0, 0);
            pipeUpSprite.setScale(0.000059, .000001);
            pipeDownSprite.setScale(0.00000059, .000001);

        }

        // Attendre 1/60�me de seconde (60 FPS)
        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asMilliseconds() < 16)
        {
            sf::sleep(sf::milliseconds(16) - elapsedTime);
        }
        clock.restart();
    }

    return 0;
}