local imbuement = Action()

function imbuement.onUse(player, item, fromPosition, target, toPosition, isHotkey)
	player:sendImbuementPanel(target, true)
	return true
end

imbuement:id(25060, 25061, 25101, 25102, 25103, 25104)
imbuement:register()
