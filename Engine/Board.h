#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public: 
	enum class CellContents
	{
		Empty,
		Obstacle,
		Food,
		Poison
	};
public:
	Board( Graphics& gfx );
	void DrawCell( const Location& loc,Color c );
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard( const Location& loc ) const;
	void DrawBorder();
	CellContents GetContents(const Location& loc) const;
	void SpawnContents(std::mt19937& rng, const class Snake& snake, Board::CellContents content_type);
	void ConsumeContents(const Location& loc);
	void DrawCells();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr Color obstacleColor = Colors::Gray;
	static constexpr Color foodColor = Colors::Red;
	static constexpr Color poisonColor = { 64, 8, 64 };
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	// contents: 0(empty), 1(obstacle), 2(food), 3(speedup)
	CellContents contents[width * height] = { CellContents::Empty };
	Graphics& gfx;
};