// O------------------------------------------------------------------------------O
// | Example "Hello World" Program (main.cpp)                                     |
// O------------------------------------------------------------------------------O


#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "GameOfLifeRules.h"

// Override base class with your custom functionality
class GameOfLife : public olc::PixelGameEngine
{
public:
	GameOfLife()
	{
		// Name your application
		sAppName = "Conway's Game of Life";
	}

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		m_rules.createGrid({ static_cast<unsigned>(ScreenWidth()) , static_cast<unsigned>(ScreenHeight()) });
		
		//Set some cells for test drawing
		m_rules.setCellStateAt({ 0,0 });
		m_rules.setCellStateAt({ 10,0 });
		m_rules.setCellStateAt({ 20,40 });
		m_rules.setCellStateAt({ 230,860 });
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
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
		return true;
	}

private:
	GameOfLifeRules m_rules;
};

int main()
{
	GameOfLife game;
	if (game.Construct(80, 45, 20, 20))
		game.Start();
	return 0;
}
