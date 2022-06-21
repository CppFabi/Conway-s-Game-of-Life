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
	struct CellPosition
	{
		int x;
		int y;
	};
	struct gridSize
	{
		unsigned int x;
		unsigned int y;
	};

	void createGrid(gridSize size);
	CellState getCellStateAt(CellPosition pos) const;
	void setCellStateAt(CellPosition pos, CellState state = CellState::live);

private:
	std::vector<std::vector<CellState>> m_grid;
};

