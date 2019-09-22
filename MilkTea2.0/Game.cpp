#include "Game.h"

const float PlayButtonPosX = 590;
const float PlayButtonPosY = 450;

Game::Game()
	: mWindow(sf::VideoMode(1350, 900), "Milk Tea Catcher 2.0")
{
	mWindow.setFramerateLimit(60);
	BackgroundTexture.loadFromFile(BackgroundState);
	Background.setTexture(BackgroundTexture);
}

void Game::run()
{
	if (!music.openFromFile("Aces_High.ogg"))
	{
		std::cout << 1111111111111;
	}

	music.setVolume(60);
	music.play();
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

bool Game::checkCollision(sf::Sprite sprite, sf::Sprite sprite2)
{
	sf::FloatRect shape1 = sprite.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();

	if (sprite.getPosition().x < sprite2.getPosition().x + shape2.width &&
		sprite.getPosition().x + shape1.width > sprite2.getPosition().x &&
		sprite.getPosition().y < sprite2.getPosition().y + shape2.height &&
		shape1.height + sprite.getPosition().y > sprite2.getPosition().y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Generate random girl name
std::string Game::RandomPathDialogue() {
	std::string path = "-Dialogue.png";
	int RandDialogue = rand() % (maxDialogue)+1;
	std::string s = std::to_string(RandDialogue);
	path.insert(0, s);
	return path;
}

//Generate random girl name
std::string Game::RandomPathGirl() {
	std::string path = "-Girl.png";
	int RandGirl = rand() % (maxGirl)+1;
	std::string s = std::to_string(RandGirl);
	path.insert(0, s);
	return path;
}

//Generate random milk tea name
std::string Game::RandomPathMilkTea() {
	std::string path = ".png";
	int RandTypeMilkTea = rand() % (maxImage)+1;
	std::string s = std::to_string(RandTypeMilkTea);
	path.insert(0, s);
	return path;
}

float Game::RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}


void Game::GenerateMilkTeaArray() {
	counter = DropMaxLv[level];
	for (int i = 0; i < DropMaxLv[level]; i++) {
		std::string path1 = RandomPathMilkTea();

		MilkTea[i].path = path1.c_str();

		MilkTea[i].PosDrop = rand() % (800 - 50 + 1) + 50; //Generate random position to drop
		MilkTea[i].cnt = -(rand() % (1000 - 100 + 1) + 100); // generate position dropping when scrolling

		MilkTea[i].speed = RandomFloat(SpeedMaxStartLv[level], SpeedMaxEndLv[level]);

		MilkTea[i].end = false;

		MilkTea[i].MilkTeaTex.loadFromFile(MilkTea[i].path);
		MilkTea[i].MilkTeaSprt.setTexture(MilkTea[i].MilkTeaTex);
		MilkTea[i].MilkTeaSprt.setScale(0.4, 0.4);
	}
}

void Game::GameMode1() {
	BackgroundTexture.loadFromFile("GameBackground.png");
	Background.setTexture(BackgroundTexture);

	CartTexture.loadFromFile("Cart.png");
	Cart.setTexture(CartTexture);

	GenerateMilkTeaArray();

	
	font.loadFromFile("RifficFree.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(58);
	scoreText.setStyle(sf::Text::Regular);
	scoreText.setPosition(1045, 370);
 	sf::Color color (117, 96, 96);
	scoreText.setFillColor(color);

	ProgressBarTexture.loadFromFile("ProgressBar.png");
	ProgressBar.setTexture(ProgressBarTexture);
	ProgressBar.setPosition(970, 597);
	ProgressBar.setScale(0, 1.0);

	HeartTexture.loadFromFile("Heart.png");
	Heart.setTexture(HeartTexture);

	GirlTexture.loadFromFile("2-Girl.png");
	Girl.setTexture(GirlTexture);
	Girl.setPosition(1055, 92);

	DialogueTexture.loadFromFile("Dialogue0.png");
	Dialogue.setTexture(DialogueTexture);
	Dialogue.setPosition(798, 38);
}


/*------------------------------------*/



void Game::GameMode2() {
	BackgroundTexture.loadFromFile("GameBackground.png");
	Background.setTexture(BackgroundTexture);

	CartTexture.loadFromFile("Cart.png");
	Cart.setTexture(CartTexture);

	GenerateMilkTeaArray();


	font.loadFromFile("RifficFree.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(58);
	scoreText.setStyle(sf::Text::Regular);
	scoreText.setPosition(1045, 370);
	sf::Color color(117, 96, 96);
	scoreText.setFillColor(color);

	ProgressBarTexture.loadFromFile("ProgressBar.png");
	ProgressBar.setTexture(ProgressBarTexture);
	ProgressBar.setPosition(970, 597);
	ProgressBar.setScale(0, 1.0);

	HeartTexture.loadFromFile("Heart.png");
	Heart.setTexture(HeartTexture);

	GirlTexture.loadFromFile("2-Girl.png");
	Girl.setTexture(GirlTexture);
	Girl.setPosition(1055, 92);

	DialogueTexture.loadFromFile("Dialogue0.png");
	Dialogue.setTexture(DialogueTexture);
	Dialogue.setPosition(798, 38);

	CartX = 200;
}

void Game::ModeSelectFunc() {
	BackgroundTexture.loadFromFile("BackgroundModeSelect.png");
	Background.setTexture(BackgroundTexture);
	ModeSelectTexture.loadFromFile("ModeSelect.png");
	ModeSelect.setTexture(ModeSelectTexture);
	ModeSelect.setPosition(270, 105);

	if (mode == 2) {
		TickSelectTexture.loadFromFile("TickSelect.png");
		TickSelect.setTexture(TickSelectTexture);
		TickSelect.setPosition(772, 325);
	}

	if (mode == 1) {
		TickSelectTexture.loadFromFile("TickSelect.png");
		TickSelect.setTexture(TickSelectTexture);
		TickSelect.setPosition(472, 324);
	}
	
	
}


void Game::processEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		KeyRight = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		KeyLeft = true;
	}
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		   case sf::Event::MouseMoved: {   
				  posxMouse = event.mouseMove.x;
				  posyMouse = event.mouseMove.y;
				  //std::cout << posxMouse << " " << posyMouse << std::endl;
				 // std::cout << StartGame << " " << mode << std::endl;
				  if (playReady != 2 && StartGame==false) {
					   if (posxMouse >= 607 && posxMouse <= 742 && posyMouse >= 465 && posyMouse <= 610) {
						 PlayButtonTexture.loadFromFile("Play.Hover.png");
						 PlayButton.setTexture(PlayButtonTexture);
						 PlayButton.setPosition(PlayButtonPosX, PlayButtonPosY);
						 playReady = 1;
					   }
					   else {
						   PlayButtonTexture.loadFromFile("Play.Normal.png");
						   PlayButton.setTexture(PlayButtonTexture);
						   PlayButton.setPosition(PlayButtonPosX, PlayButtonPosY);
						   playReady = 0;
					   }
				 }
			   break;
			}

		   case sf::Event::MouseButtonPressed: {
			//   if (playReady) {
					if (StartGame == false) {
					   playReady = 2;
					   ModeSelectFunc();
					   if (posxMouse >= 770 && posxMouse <= 895 && posyMouse >= 329 && posyMouse <= 452)
						   mode = 2;
					   if (posxMouse >= 474 && posxMouse <= 596 && posyMouse >= 326 && posyMouse <= 460)
						   mode = 1;
				//   }
					if (mode != 0) {
					       if (posxMouse >= 940 && posxMouse <= 1034 && posyMouse >= 200 && posyMouse <= 280) {
								 playReady = 0;
								 StartGame = true;
								 if (mode == 1) GameMode1();
								 if (mode == 2) GameMode2();
					   }
				   }
			   }
			   break;
			}
			
			case sf::Event::Closed : {
						mWindow.close();
			}
			
			default: {

			}
		}
	}
}

void Game::update()
{
	if (StartGame == true && mode == 1)
	{
		if (posxMouse>=53 && posxMouse<=700) CartX = posxMouse;
		CartY = 715;
		Cart.setPosition(CartX, CartY);
		for (int i = 0; i < DropMaxLv[level]; i++) {
			MilkTea[i].MilkTeaSprt.setPosition(MilkTea[i].PosDrop, MilkTea[i].cnt++*MilkTea[i].speed);
		}
	}

	if (StartGame == true && mode == 2) {
		if (CartX >= 53 && CartX <= 700) {
			if (KeyLeft) {
				CartX -= 5;
				KeyLeft = false;
			}
			if (KeyRight) {
				CartX += 5;
				KeyRight = false;
			}
		}
		CartY = 715;
		Cart.setPosition(CartX, CartY);
		for (int i = 0; i < DropMaxLv[level]; i++) {
			MilkTea[i].MilkTeaSprt.setPosition(MilkTea[i].PosDrop, MilkTea[i].cnt++*MilkTea[i].speed);
		}
	}
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(Background);


	if (lives == 0) {
		BackgroundTexture.loadFromFile("EndGame.png");
		Background.setTexture(BackgroundTexture);
	}


	if (StartGame == false) mWindow.draw(PlayButton);
	if (playReady) {
		mWindow.draw(ModeSelect);
		if (mode != 0 ) mWindow.draw(TickSelect);
	}

	if (StartGame == true )//&& mode == 1)
	{
		if (stillAlive) {
			mWindow.draw(Girl);
			mWindow.draw(Dialogue);
		}
		if (ChangedLevel)
		{
			std::string path1 = RandomPathGirl();
			GirlTexture.loadFromFile(path1);
			Girl.setTexture(GirlTexture);
			ChangedLevel = false;
		}

		for (int k = 0; k < lives; k++) {
			Heart.setPosition(1010 + k * 60, 766);
			mWindow.draw(Heart);
		}

		mWindow.draw(ProgressBar);
		std::string scoreToString = std::to_string(score);
		scoreText.setString(scoreToString);
		mWindow.draw(scoreText);

		mWindow.draw(Cart);
		if (stillAlive) {
		for (unsigned int i = 0; i < DropMaxLv[level]; i++)
			if (MilkTea[i].end == false)
			{
				mWindow.draw(MilkTea[i].MilkTeaSprt);

				if (checkCollision(Cart, MilkTea[i].MilkTeaSprt)) {
					MilkTea[i].end = true;
					counter--;
					score += 5 * MultiplierLv[level];
					if (counter % 3 == 0) {
						std::string path1 = RandomPathDialogue();
						DialogueTexture.loadFromFile(path1);
						Dialogue.setTexture(DialogueTexture);
					}
				}
				//	std::cout << MilkTea[0].cnt << std::endl;
				if (MilkTea[i].cnt >= 380) {
					MilkTea[i].end = true;
					lives--;
					counter--;
					std::cout << "LIVES: " << lives << std::endl;
				}

				if (counter == 0 && lives != 0) //go to next level condition
												//@counter==0 means the last milk tea appeared and finish line
												//@lives!=0 means you haven't dead.
				{
					ChangedLevel = true;
					level++;
					ProgressBar.setScale(level*0.1, 1.0);
					GenerateMilkTeaArray();
				}
			}
			}
	}

	if (StartGame == true && mode == 1)
	{
		mWindow.draw(Girl);
		mWindow.draw(Dialogue);
		if (ChangedLevel)
		{
			std::string path1 = RandomPathGirl();
			GirlTexture.loadFromFile(path1);
			Girl.setTexture(GirlTexture);
			ChangedLevel = false;
		}

		for (int k = 0; k < lives; k++) {
			Heart.setPosition(1010 + k * 60, 766);
			mWindow.draw(Heart);
		}

		mWindow.draw(ProgressBar);
		std::string scoreToString = std::to_string(score);
		scoreText.setString(scoreToString);
		mWindow.draw(scoreText);

		mWindow.draw(Cart);

		for (unsigned int i = 0; i < DropMaxLv[level]; i++)
			if (MilkTea[i].end == false)
		{
			mWindow.draw(MilkTea[i].MilkTeaSprt);

			if (checkCollision(Cart, MilkTea[i].MilkTeaSprt)) {
				effect.play();
				MilkTea[i].end = true;
				counter--;
				score += 5 * MultiplierLv[level];
				if (counter % 3 ==0) {
					std::string path1 = RandomPathDialogue();
					DialogueTexture.loadFromFile(path1);
					Dialogue.setTexture(DialogueTexture);
				}
			}
		//	std::cout << MilkTea[0].cnt << std::endl;
			if (MilkTea[i].cnt >= 360) {
				MilkTea[i].end = true;
				lives--;
				counter--;
				std::cout << "LIVES: " << lives << std::endl;
			}

			if (counter == 0 && lives != 0) //go to next level condition
											//@counter==0 means the last milk tea appeared and finish line
											//@lives!=0 means you haven't dead.
			{
				ChangedLevel = true;
				stillAlive = false;
				level++;
				ProgressBar.setScale(level*0.1, 1.0);
				GenerateMilkTeaArray();
			}
		}
	}
	mWindow.display();
}