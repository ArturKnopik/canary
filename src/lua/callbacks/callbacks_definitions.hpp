/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#pragma once

/**
 * @enum EventCallback_t
 * @brief Defines the types of events that can trigger callbacks.
 *
 * @details This enumeration represents different types of game events that can be associated
 * with specific callbacks.
 * @note The events are categorized by the type of game entity they relate to.
 */
enum class EventCallback_t : uint16_t {
	none,
	// Creature
	creatureOnChangeOutfit,
	creatureOnAreaCombat,
	creatureOnTargetCombat,
	creatureOnHear,
	creatureOnDrainHealth,
	// Party
	partyOnJoin,
	partyOnLeave,
	partyOnDisband,
	partyOnShareExperience,
	// Player
	playerOnBrowseField,
	playerOnLook,
	playerOnLookInBattleList,
	playerOnLookInTrade,
	playerOnLookInShop,
	playerOnMoveItem,
	playerOnItemMoved,
	playerOnChangeZone,
	playerOnChangeHazard,
	playerOnMoveCreature,
	playerOnReportRuleViolation,
	playerOnReportBug,
	playerOnTurn,
	playerOnTradeRequest,
	playerOnTradeAccept,
	playerOnGainExperience,
	playerOnLoseExperience,
	playerOnGainSkillTries,
	playerOnRequestQuestLog,
	playerOnRequestQuestLine,
	playerOnStorageUpdate,
	playerOnRemoveCount,
	playerOnCombat,
	playerOnInventoryUpdate,
	playerOnRotateItem,
	// Monster
	monsterOnDropLoot,
	monsterPostDropLoot,
	monsterOnSpawn,
	// Npc
	npcOnSpawn,
	// Zone
	zoneOnCreatureEnter,
	zoneOnCreatureLeave,
};
