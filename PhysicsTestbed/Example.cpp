#include "Example.h"
#include"KinematicObject.h"
#include <vector>

Example::Example() : Testbed()
{
	//Your initialisation code goes here!
	for (int i = 0; i < 50; i++)
	{
		stuff.push_back(KinematicObject());
	}
	
}

void Example::Update()
{
	//This call ensures that your mouse position and aspect ratio are maintained as correct.
	Testbed::Update();
	

	//Your physics (or whatever) code goes here!
	for (int i = 0; i < stuff.size(); i++)
	{
		stuff[i].Update(deltaTime);
	}
}

void Example::Render()
{

	//Example code that draws a blue square.
	std::vector<glm::vec2> points;
	points.push_back({ 1.5f, 1.5f });
	points.push_back({ 1.5f, 2.5f });
	points.push_back({ 2.5f, 2.5f });
	points.push_back({ 2.5f, 1.5f });

	lines.DrawRawShape((float*)points.data(), (unsigned int) points.size(), glm::vec3(0, 0, 1));


	//Example code that draws a coloured circle at the mouse position, whose colour depends on which buttons are down.
	if (leftButtonDown)
	{
		
		lines.DrawCircle(cursorPos, 0.2f, { 1, 0, 0 });
	}
	else if (rightButtonDown)
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 1, 0 });
	}
	else
	{
		lines.DrawCircle(cursorPos, 0.2f, { 0, 0, 1 });
	}

	for (int i = 0; i < stuff.size(); i++)
	{
		
		
		lines.DrawCircle(stuff[i].position, stuff[i].radius, { 1,1,1 }, 8);
		
	}


	//Your drawing code goes here!
	


	//This call puts all the lines you've set up on screen - don't delete it or things won't work.
	Testbed::Render();
}