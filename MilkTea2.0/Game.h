#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
struct MilkTeaObject {
	int PosDrop;
	int cnt;
	const char *path;
	float speed;
	bool end;
	sf::Texture MilkTeaTex;
	sf::Sprite MilkTeaSprt;
};

class Game
{
public:
	Game();
	void run();
private:
	void ModeSelectFunc();
	std::string RandomPathDialogue();
	std::string RandomPathGirl();
	std::string RandomPathMilkTea();
	float RandomFloat(float a, float b);
	bool checkCollision(sf::Sprite sprite, sf::Sprite sprite2);
	void GenerateMilkTeaArray();
	void GameMode1();
	void GameMode2();
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	std::string BackgroundState = "BackgroundNormal.png";

	sf::Texture BackgroundTexture;
	sf::Sprite Background;

	sf::Texture PlayButtonTexture;
	sf::Sprite PlayButton;

	sf::Texture ModeSelectTexture;
	sf::Sprite ModeSelect;

	sf::Texture TickSelectTexture;
	sf::Sprite TickSelect;

	sf::Texture CartTexture;
	sf::Sprite Cart;

	sf::Font font;
	sf::Text scoreText;

	sf::Texture ProgressBarTexture;
	sf::Sprite ProgressBar;

	sf::Texture HeartTexture;
	sf::Sprite Heart;

	sf::Texture DialogueTexture;
	sf::Sprite Dialogue;

	sf::Texture GirlTexture;
	sf::Sprite Girl;

	sf::Music music;
	sf::Music effect;

	int cnt = 0;
	const int maxImage = 10;
	const int maxGirl = 3;
	const int maxDialogue = 5;

	bool KeyLeft = false, KeyRight = false;

	int DropMaxLv[10] = { 5, 7, 10, 15, 30, 35, 40, 50, 70, 80 };
	int MultiplierLv[10] = { 1, 1, 2, 3, 4, 4, 5, 5, 6, 8 };
	double SpeedMaxStartLv[10] = { 1.5, 1.7, 1.9, 2.1, 2.1, 2.1, 2.1, 2, 2, 2};
	double SpeedMaxEndLv[10] = { 2.0, 2.3, 2.5, 2.5, 2.7, 2.7, 2.9, 2.2, 2.2, 2.2 };
	MilkTeaObject MilkTea[100];


	int counter;
	bool StartGame = false;
	bool stillAlive = true;
	int posxMouse, posyMouse;
	int playReady = 0; // parameter: @1 means ready, @0 means not ready, @2 means click
	int mode = 0; // parameter: @1 means normal, @2 means vortex
	int level = 0;
	int CartX, CartY;
	unsigned long long int score = 0;
	int lives = 5;

	bool ChangedLevel = false;
};


