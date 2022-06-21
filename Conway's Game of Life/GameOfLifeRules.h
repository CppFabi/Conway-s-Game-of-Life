#pragma once
#include <vector>

class GameOfLifeRules
{
public:
	enum class CellState 
	{
		live,
		dead
	};


private:
	std::vector<std::vector<CellState>> m_grid;
};

