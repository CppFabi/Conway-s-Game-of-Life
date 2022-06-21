#include "GameOfLifeRules.h"

void GameOfLifeRules::createGrid(gridSize size)
{
    std::vector<CellState> column{ size.x,CellState::dead };
    m_grid = std::vector<std::vector<CellState>>(size.y, column);
}

auto GameOfLifeRules::getCellStateAt(CellPosition pos) const -> CellState
{
    std::vector<CellState> column = m_grid.at(pos.x % m_grid.size());
    return column.at(pos.y % column.size());
}

void GameOfLifeRules::setCellStateAt(CellPosition pos, CellState state)
{
    std::vector<CellState>& column = m_grid.at(pos.x % m_grid.size());
    column.at(pos.y % column.size()) = state;
}
