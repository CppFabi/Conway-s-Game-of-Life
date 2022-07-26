#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
	// Name your application
	sAppName = "Conway's Game of Life";
}

bool GameOfLife::OnUserCreate()
{
	// Called once at the start, so create things here
	m_rules.createGrid({ static_cast<unsigned>(ScreenWidth()) , static_cast<unsigned>(ScreenHeight()) });

	//Set some cells for test drawing
	m_rules.setCellStateAt({ 0,0 });
	m_rules.setCellStateAt({ 10,0 });
	m_rules.setCellStateAt({ 20,40 });
	m_rules.setCellStateAt({ 21,40 });
	m_rules.setCellStateAt({ 22,40 });
	m_rules.setCellStateAt({ 230,860 });
	return true;
}

bool GameOfLife::OnUserUpdate(float fElapsedTime)
{
	m_time += fElapsedTime;
	if (m_time > 0.2f)
	{
		m_time = 0.f;
		m_rules.createNextGeneration();
	}

	draw();
	return true;
}

void GameOfLife::draw()
{
	Clear(olc::WHITE);
	for (int x = 0; x < ScreenWidth(); x++)
	{
		for (int y = 0; y < ScreenHeight(); y++)
		{
			if (m_rules.getCellStateAt({ x, y }) == GameOfLifeRules::CellState::live)
			{
				Draw(x, y, olc::GREEN);
			}
		}
	}
}
