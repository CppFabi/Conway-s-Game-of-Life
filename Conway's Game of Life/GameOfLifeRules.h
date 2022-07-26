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
	struct GridSize
	{
		unsigned int x;
		unsigned int y;
	};

	void createGrid(GridSize size);
	CellState getCellStateAt(CellPosition pos) const;
	void setCellStateAt(CellPosition pos, CellState state = CellState::live);

	void createNextGeneration();

private:
	std::vector<std::vector<CellState>> m_grid;
	std::vector<std::vector<CellState>> m_gridNextGeneration;
};

