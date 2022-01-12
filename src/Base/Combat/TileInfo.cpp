#include "TileInfo.h"

TileInfo::TileInfo(void)
{
	for (Uint8 row = 0; row < ROW; ++row)
	{
		for (Uint8 column = 0; column < COLUMN; ++column)
		{
			info[row][column].state = State::NEUTRAL;
			info[row][column].show = Show::nothing;
			info[row][column].highlight = Color::UNHIGHLIGHT;
			info[row][column].distance = 10;
			info[row][column].actionsLeft = 0;
			info[row][column].hasAttacked = false;
			info[row][column].notSelected = false;
		}
	}
	for (Uint8 column = 4; column < COLUMN - 4; ++column)
	{
		info[0][column].state = State::BLANK;
		info[ROW - 1][column].state = State::BLANK;
	}
	for (Uint8 row = 0; row < ROW; ++row)
	{
		for (Uint8 column = 0; column < 4; ++column)
		{
			info[row][column].state = State::BLANK;
			info[row][COLUMN - 1 - column].state = State::BLANK;
		}
	}
	info[4][1].state = State::TRAIN_HUMAN_INFANTRY;
	info[4][2].state = State::TRAIN_HUMAN_INFANTRY;
	info[4][3].state = State::TRAIN_HUMAN_INFANTRY;

	info[6][1].state = State::TRAIN_HUMAN_ARCHER;
	info[6][2].state = State::TRAIN_HUMAN_ARCHER;
	info[6][3].state = State::TRAIN_HUMAN_ARCHER;

	info[8][1].state = State::TRAIN_HUMAN_KNIGHT;
	info[8][2].state = State::TRAIN_HUMAN_KNIGHT;
	info[8][3].state = State::TRAIN_HUMAN_KNIGHT;
	
	info[10][1].state = State::TRAIN_HUMAN_WING;
	info[10][2].state = State::TRAIN_HUMAN_WING;
	info[10][3].state = State::TRAIN_HUMAN_WING;

	info[15][1].state = State::HUMAN_PAUSE;
	info[15][2].state = State::HUMAN_PAUSE;
	info[15][3].state = State::HUMAN_PAUSE;

	info[17][1].state = State::HUMAN_PASS_TURN;
	info[17][2].state = State::HUMAN_PASS_TURN;
	info[17][3].state = State::HUMAN_PASS_TURN;

	info[4][23].state = State::TRAIN_ORC_INFANTRY;
	info[4][22].state = State::TRAIN_ORC_INFANTRY;
	info[4][21].state = State::TRAIN_ORC_INFANTRY;

	info[6][23].state = State::TRAIN_ORC_ARCHER;
	info[6][22].state = State::TRAIN_ORC_ARCHER;
	info[6][21].state = State::TRAIN_ORC_ARCHER;

	info[8][23].state = State::TRAIN_ORC_KNIGHT;
	info[8][22].state = State::TRAIN_ORC_KNIGHT;
	info[8][21].state = State::TRAIN_ORC_KNIGHT;

	info[10][23].state = State::TRAIN_ORC_WING;
	info[10][22].state = State::TRAIN_ORC_WING;
	info[10][21].state = State::TRAIN_ORC_WING;

	info[15][23].state = State::ORC_PAUSE;
	info[15][22].state = State::ORC_PAUSE;
	info[15][21].state = State::ORC_PAUSE;

	info[17][23].state = State::ORC_PASS_TURN;
	info[17][22].state = State::ORC_PASS_TURN;
	info[17][21].state = State::ORC_PASS_TURN;
}
