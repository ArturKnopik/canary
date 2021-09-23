--[[
Reserved player action storage key ranges (const.hpp)
	It is possible to place the storage in a quest door, so the player who has that storage will go through the door

	Reserved player action storage key ranges (const.hpp at the source)
	[10000000 - 20000000]
	[1000 - 1500]
	[2001 - 2011]
	[31000 - 31021] - level 3 imbuing storage
	Others reserved player action/storages
	[100] = unmoveable/untrade/unusable items
	[101] = use pick floor
	[102] = well down action
	[103-120] = others keys action
	[103] = key 0010
	[303] = key 0303
	[1000] = level door. Here 1 must be used followed by the level.
	Example: 1010 = level 10,
	1100 = level 100]

	Questline = Storage through the Quest
]]

Storage = {
	Quest = {
		Key = {
			ID1000 = 103
		},
		ExampleQuest = {
			Example = 9000,
			Door = 9001
		}
	},

	NpcExhaust = 30000,
	StoreExaust = 30001,
	DelayLargeSeaShell = 30002,
	Promotion = 30003,
	PetSummonEvent10 = 30004,
	PetSummonEvent60 = 30005,
	Imbuing = 
	{
		LichShroud = 31000,
		Reap = 31001,
		Vampirism = 31002,
		CloudFabric = 31003,
		Electrify = 31004,
		Swiftness = 31005,
		SnakeSkin = 31006,
		Venom = 31007,
		Slash = 31008,
		Chop = 31009,
		Bash = 31010,
		DragonHide = 31011,
		Scorch = 31012,
		Void = 31013,
		QuaraScale = 31014,
		Frost = 31015,
		Blockade = 31016,
		DemonPresence = 31017,
		Precision = 31018,
		Strike = 31019,
		Epiphany = 31020,
		Featherweight = 31021
	}
}

GlobalStorage = {
	ExampleQuest = {
		Example = 60000
	}
}

-- Values extraction function
local function extractValues(tab, ret)
	if type(tab) == "number" then
		table.insert(ret, tab)
	else
		for _, v in pairs(tab) do
			extractValues(v, ret)
		end
	end
end

local benchmark = os.clock()
local extraction = {}
extractValues(Storage, extraction) -- Call function
table.sort(extraction) -- Sort the table
-- The choice of sorting is due to the fact that sorting is very cheap O (n log2 (n))
-- And then we can simply compare one by one the elements finding duplicates in O(n)

-- Scroll through the extracted table for duplicates
if #extraction > 1 then
	for i = 1, #extraction - 1 do
		if extraction[i] == extraction[i+1] then
			Spdlog.warn(string.format("Duplicate storage value found: %d",
				extraction[i]))
			Spdlog.warn(string.format("Processed in %.4f(s)", os.clock() - benchmark))
		end
	end
end
