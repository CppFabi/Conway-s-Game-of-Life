#include "GameOfLifeRules.h"

namespace
{
	GameOfLifeRules::CellState getCellStateInGrid(GameOfLifeRules::CellPosition pos, const std::vector<std::vector<GameOfLifeRules::CellState>>& grid)
	{
		const std::vector<GameOfLifeRules::CellState>& column = grid.at(pos.x % grid.size());
		return column.at(pos.y % column.size());
	}

	void setCellStateInGrid(GameOfLifeRules::CellPosition pos, GameOfLifeRules::CellState state, std::vector<std::vector<GameOfLifeRules::CellState>>& grid)
	{
		std::vector<GameOfLifeRules::CellState>& column = grid.at(pos.x % grid.size());
		column.at(pos.y % column.size()) = state;
	}


	int countNeighbours(GameOfLifeRules::CellPosition pos, const std::vector<std::vector<GameOfLifeRules::CellState>>& grid)
	{
		int count{ 0 };
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				if (getCellStateInGrid({ pos.x + dx,pos.y + dy }, grid) == GameOfLifeRules::CellState::live)
				{
					if (dy != 0 || dx != 0)
					{
						count++;
					}
				}
			}
		}
		return count;
	}
}

void GameOfLifeRules::createGrid(GridSize size)
{
    std::vector<CellState> column{ size.y,CellState::dead };
    m_grid = std::vector<std::vector<CellState>>(size.x, column);
	m_gridNextGeneration = std::vector<std::vector<CellState>>(size.x, column);
}

auto GameOfLifeRules::getCellStateAt(CellPosition pos) const -> CellState
{
	return getCellStateInGrid(pos, m_grid);
}

void GameOfLifeRules::setCellStateAt(CellPosition pos, CellState state)
{
	setCellStateInGrid(pos, state, m_grid);
}



void GameOfLifeRules::createNextGeneration()
{
	for (int x = 0; x < m_grid.size(); x++)
	{
		for (int y = 0; y < m_grid.at(x).size(); y++)
		{
			auto count = countNeighbours({ x,y }, m_grid);
			if (count == 3 || (count == 2 && getCellStateAt({ x, y }) == CellState::live))
			{
				setCellStateInGrid({ x,y }, CellState::live, m_gridNextGeneration);
			}
			else
			{
				setCellStateInGrid({ x,y }, CellState::dead, m_gridNextGeneration);
			}
		}
	}
	std::swap(m_grid, m_gridNextGeneration);
}
