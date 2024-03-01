#pragma once
class TimeManager
{
public:
	static float GetDeltaTime();
	static void UpdateDeltatime();

private:
	static float deltaTime;
	static float lastFrame;
};