//============================================================================
// Name        : Paper.cpp
// Author      : dong shi
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "ResourceManager/ResourceManager.h"
#include "TaskContainer/GUIClass.h"
#include "TaskContainer/TaskFunctions.hpp"
#include "Background.h"
#include "Menu1.h"
#include "GameDataClasses/BulletData/BulletData.h"

//=================================================
//FrameRate tracker:
//Functions for retrieving frame rate for each
//frame in string form.
//=================================================
namespace fr{

sf::Clock elapsed;

//****************
//floatToString(float d):
//- value to be turned to string.
//takes a float and turns it into a string.
//****************
std::string floatToString(float d){
	std::stringstream ss;
	ss << d;
	return ss.str();
}

//****************
//getFrameRate():
//Returns frame rate
//in string form.
//****************
std::string getFrameRate(){
	float fps = (1.0f / elapsed.GetElapsedTime());
	elapsed.Reset();
	return floatToString(fps);
}

}

//=================================================
//Character Buffer:
//Stores characters entered at each frame,
//to be accessed by modules above.
//=================================================
namespace cc{

std::string chars;

bool active = false;

//****************
//getChars():
//Described in header.
//****************
const std::string & getChars(){
	return chars;
}
//****************
//addChar(char c):
//- c is the character to be added.
//Add chars to the char buffer.
//****************
void addChar(char c){
	if (active)chars.append(1,c);
}

//****************
//clearChars():
//Clears the char buffer.
//To be done every frame.
//****************
void clearChars(){
	chars.clear();
}

//****************
//setActive():
//Described in header.
//****************
void setState(bool state){
	active = state;
}

}

//=================================================
//MAIN FUNCTION:
//- Creates window, size and etc
//- Keeps frame tracker running
//- Loads background and mainmenu tasks
//- Keeps Character buffer running
//- Polls the events
//=================================================
int main(){
	//set Window
	sf::RenderWindow window;
	window.Create(sf::VideoMode(400,800,32), "PaperHeLL - Hell in Paper", sf::Style::Close);
	DrawTypes::setDrawTarget(window);

	//Frame rate tracker
	sf::String fps("0", sf::Font::GetDefaultFont(), 20);
	fps.SetPosition(5,5);

	//load tasks
	tf::startTask(tf::loadTask<Background>("Background"));//background image
	tf::startTask(tf::loadTask<Menu1>("Menu1"));//background image

	bool running = true;

	while (running){
		sf::Event events;

		//event loop
		while (window.GetEvent(events)){

			switch (events.Type){
				case sf::Event::Closed:
					running=false;
					break;

				case sf::Event::TextEntered:
					cc::addChar((char)events.Text.Unicode);
					break;

				default:
					break;
			}

		}

		//getting mouse input
		const sf::Input & input = window.GetInput();
		int x, y, b1, b2;
		x  = input.GetMouseX();
		y  = input.GetMouseY();
		b1 = input.IsMouseButtonDown(sf::Mouse::Left);
		b2 = input.IsMouseButtonDown(sf::Mouse::Right);
		GUIModule::updateMouse(x,y,b1,b2);

		//updateTasks
		tf::updateTask();

		//frame rate
		fps.SetText(fr::getFrameRate());
		window.Draw(fps);

		//display
		window.Display();
		window.Clear();

		//clear chars from char buffer
		cc::clearChars();
	}
	return 0;
}
