local config = {
	boss = {
		name = "Lord Azaram",
		position = Position(33424, 31473, 13)
	},
	requiredLevel = 250,
	timeToFightAgain = 20 * 60 * 60,
	timeToDefeatBoss = 20 * 60,
	playerPositions = {
		{pos = Position(33422, 31493, 13), teleport = Position(33423, 31465, 13), effect = CONST_ME_TELEPORT},
		{pos = Position(33423, 31493, 13), teleport = Position(33423, 31465, 13), effect = CONST_ME_TELEPORT},
		{pos = Position(33424, 31493, 13), teleport = Position(33423, 31465, 13), effect = CONST_ME_TELEPORT},
		{pos = Position(33425, 31493, 13), teleport = Position(33423, 31465, 13), effect = CONST_ME_TELEPORT},
		{pos = Position(33426, 31493, 13), teleport = Position(33423, 31465, 13), effect = CONST_ME_TELEPORT}
	},
	specPos = {
		from = Position(33416, 31463, 13),
		to = Position(33432, 31481, 13)
	},
	exit = Position(32192, 31819, 8),
	storage = Storage.Quest.U12_20.GraveDanger.Bosses.LordAzaramTimer
}

local lordAzaramLever = Action()
function lordAzaramLever.onUse(player, item, fromPosition, target, toPosition, isHotkey)
	return CreateDefaultLeverBoss(player, config)
end

lordAzaramLever:position({x = 33421, y = 31493, z = 13})
lordAzaramLever:register()