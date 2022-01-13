# Heap-of-Battle
2D turn-based strategy local PvP video game written in C++ using SDL.
# Objective
The objective is simple: conquer the opponent's base before they do. However each scenario offers different side objectives that serve as win conditions. The maps are symmetrical so that each player has equal chances. 
# e
The only allowed number of players is 2 (1 vs 1) with 2 factions to choose from (human and orc). It is worth mentioning that this game is inspired by the warcraft lore (borrowing Warcraft 2 sprites and Warcraft 3 sounds). The currency system is basic: each turn the player receives the amount of yield that he currently has. The means of combat are 4 types of units: infantry(5 gold), archer/axethrower(10 gold), knight/death knight(20 gold), griffin rider/dragon(30 gold). The infantry can move 2 times each turn, the archer 3, the knight and dragon 4. The knight is 10 gold cheaper than the dragon even though they can move the same amount because of attack restrictions. The infantry can't attack dragons, the archers can't attack knights, the knights can't attack infantry and dragons, the dragons can't attack archers. An attack is like a capturing a piece in chess, there is no health bar involved.
![Gameplay](https://user-images.githubusercontent.com/94221810/149328804-7c59962a-c91f-43e2-a9da-e3ad5b71a10c.PNG)
