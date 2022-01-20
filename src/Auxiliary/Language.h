#pragma once
#include <SDL.h>
#include <iostream>

struct Mouse
{
	int x, y;
};

struct Coordinate
{
	Uint8 x, y;
};

struct Receipt
{
	Uint16 gold, yield;
};

enum class Faction
{
	NEUTRAL = 0,

	HUMAN = 1,
	ORC = -1,
};

struct Flag
{
	Faction human, orc;
};

enum class Color
{
	UNHIGHLIGHT = 0,

	BLUE = 1,
	RED = -1,
};

enum class Engage
{
	NO = 0,

	PAUSE = 1,
	VICTORY = 5,

	KEEP = 2,
	KEEP_1 = 2,
	KEEP_2 = 3,
	UNIT = 4,
};

enum class State
{
	BLANK = 99,
	NEUTRAL = 0,

	HUMAN_INFANTRY = 1,
	HUMAN_ARCHER = 2,
	HUMAN_KNIGHT = 3,
	HUMAN_WING = 4,
	HUMAN_KEEP = 5,
	HUMAN_KEEP_1 = 5,
	HUMAN_KEEP_2 = 6,

	TRAIN_HUMAN_INFANTRY = 11,
	TRAIN_HUMAN_ARCHER = 12,
	TRAIN_HUMAN_KNIGHT = 13,
	TRAIN_HUMAN_WING = 14,
	VAMP_HUMAN_KEEP = 15,

	HUMAN_PAUSE = 16,
	HUMAN_PASS_TURN = 17,

	HUMAN_ALTAR = 21,
	HUMAN_FARM = 22,
	HUMAN_TOWER = 23,

	ORC_INFANTRY = -1,
	ORC_ARCHER = -2,
	ORC_KNIGHT = -3,
	ORC_WING = -4,
	ORC_KEEP = -5,
	ORC_KEEP_1 = -5,
	ORC_KEEP_2 = -6,

	TRAIN_ORC_INFANTRY = -11,
	TRAIN_ORC_ARCHER = -12,
	TRAIN_ORC_KNIGHT = -13,
	TRAIN_ORC_WING = -14,
	VAMP_ORC_KEEP = -15,

	ORC_PAUSE = -16,
	ORC_PASS_TURN = -17,

	ORC_ALTAR = -21,
	ORC_FARM = -22,
	ORC_TOWER = -23,

	MINE, LABORATORY
};

enum class Show
{
	NOTHING = 0,

	HUMAN_INFANTRY = 1,
	HUMAN_ARCHER = 2,
	HUMAN_KNIGHT = 3,
	HUMAN_WING = 4,

	ORC_INFANTRY = -1,
	ORC_ARCHER = -2,
	ORC_KNIGHT = -3,
	ORC_WING = -4,
};

enum class Sound
{
	TRAIN = 0,
	SELECT = 1,
	MOVE = 2,
	ATTACK = 3,

	HUMAN_MORE_GOLD = 11,
	HUMAN_DEFEAT = 12,

	ORC_MORE_GOLD = -11,
	ORC_DEFEAT = -12,

	CLICK = -1,
	ERROR = -2,
	RECEIVE_GOLD = -3,
	PAUSE = -5,

	VAMP = -4,
};

enum class Move
{
	STOP = 0,

	LEFT = 1,
	UP = 2,
	RIGHT = 3,
	DOWN = 4,

	ATTACK_LEFT = 5,
	ATTACK_UP = 6,
	ATTACK_RIGHT = 7,
	ATTACK_DOWN = 8,
};

enum Resolution
{
	SCALE = 32,
	ROW = 19,
	COLUMN = 25
};

enum // TEMPORARY
{
	HUMAN_FARM_X = 17,
	HUMAN_FARM_Y = 17,

	ORC_FARM_X = 1,
	ORC_FARM_Y = 7,
};
