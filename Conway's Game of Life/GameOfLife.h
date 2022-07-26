#pragma once
#include "olcPixelGameEngine.h"
#include "GameOfLifeRules.h"

class GameOfLife : public olc::PixelGameEngine
{
public:
	GameOfLife();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	void draw();

	GameOfLifeRules m_rules;
	float m_time{ 0.f };
};

