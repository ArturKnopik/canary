/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (C) 2021 OpenTibiaBR <opentibiabr@outlook.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_CREATURES_PLAYERS_ACCOUNT_ACCOUNT_HPP_
#define SRC_CREATURES_PLAYERS_ACCOUNT_ACCOUNT_HPP_

#include <string>
#include <vector>
#include <limits.h>

#include "database/database.h"
#include "database/databasetasks.h"
#include "utils/definitions.h"

namespace account {

enum Errors : uint8_t {
	ERROR_NO = 0,
	ERROR_DB,
	ERROR_GET_COINS,
	ERROR_INVALID_ACCOUNT_EMAIL,
	ERROR_INVALID_ACC_PASSWORD,
	ERROR_INVALID_ACC_TYPE,
	ERROR_INVALID_ID,
	ERROR_INVALID_LAST_DAY,
	ERROR_LOADING_ACCOUNT_PLAYERS,
	ERROR_NOT_INITIALIZED,
	ERROR_NULLPTR,
	ERROR_VALUE_NOT_ENOUGH_COINS,
	ERROR_VALUE_OVERFLOW,
	ERROR_PLAYER_NOT_FOUND
};

enum AccountType : uint8_t {
	ACCOUNT_TYPE_NORMAL = 1,
	ACCOUNT_TYPE_TUTOR = 2,
	ACCOUNT_TYPE_SENIORTUTOR = 3,
	ACCOUNT_TYPE_GAMEMASTER = 4,
	ACCOUNT_TYPE_GOD = 5
};

enum GroupType : uint8_t {
	GROUP_TYPE_NORMAL = 1,
	GROUP_TYPE_TUTOR = 2,
	GROUP_TYPE_SENIORTUTOR = 3,
	GROUP_TYPE_GAMEMASTER = 4,
	GROUP_TYPE_COMMUNITYMANAGER = 5,
	GROUP_TYPE_GOD = 6
};

enum CoinTransactionType : uint8_t {
	COIN_ADD = 1,
	COIN_REMOVE = 2
};

enum CoinType : uint8_t {
	COIN = 1,
	TOURNAMENT = 2
};


typedef struct {
	std::string name;
	uint64_t deletion;
} Player;

/**
 * @brief Account class to handle account information
 *
 */
class Account {
 public:
	/**
		* @brief Construct a new Account object
		*
		*/
	Account();

	/**
		* @brief Construct a new Account object
		*
		* @param id Set Account ID to be used by LoadAccountDB
		*/
	explicit Account(uint32_t id);

	/**
		* @brief Construct a new Account object
		*
		* @param name Set Account Name to be used by LoadAccountDB
		*/
	explicit Account(const std::string &name);

	/***************************************************************************
		* Interfaces
		**************************************************************************/

	/**
		* @brief Set the Database Interface used to get and set information from
		* the database
		*
		* @param database Database Interface pointer to be used
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t SetDatabaseInterface(Database *database);

	/**
		* @brief Set the Database Tasks Interface used to schedule db update
		*
		* @param database Database Interface pointer to be used
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t SetDatabaseTasksInterface(DatabaseTasks *db_tasks);


	/***************************************************************************
		* Coins Methods
		**************************************************************************/

	/** Coins
		* @brief Get the amount of coins that the account has from database.
		*
		* @return uint32_t Number of coins
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	std::tuple<uint32_t, error_t> GetCoins();

	/**
		* @brief Add coins to the account and update database.
		*
		* @param amount Amount of coins to be added
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t AddCoins(const uint32_t &amount);

	/**
		* @brief Removes coins from the account and update database.
		*
		* @param amount Amount of coins to be removed
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t RemoveCoins(const uint32_t &amount);

	/** Tournament Coins
		* @brief Get the amount of tournament coins that the account has from database.
		*
		* @return uint32_t Number of tournament coins
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	std::tuple<uint32_t, error_t> GetTournamentCoins();

	/**
		* @brief Add coins to the account and update database.
		*
		* @param amount Amount of coins to be added
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t AddTournamentCoins(const uint32_t &amount);

	/**
		* @brief Removes tournament coins from the account and update database.
		*
		* @param amount Amount of coins to be removed
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t RemoveTournamentCoins(const uint32_t &amount);

	/***************************************************************************
		* Database
		**************************************************************************/

	/**
		* @brief Try to load account from DB using Account ID or Name if they were
		* initialized.
		*
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t LoadAccountDB();

	/**
		* @brief Try to load account from DB using Account Name
		*
		* @param name
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t LoadAccountDB(std::string name);

	/**
		* @brief Try to load account from DB using Account ID
		*
		* @param id Account ID
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t LoadAccountDB(uint32_t id);

	/**
		* @brief Save Account to DB
		*
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t SaveAccountDB();


	/***************************************************************************
		* Setters and Getters
		**************************************************************************/

	uint32_t GetID();

	error_t SetEmail(std::string name);
	std::string GetEmail();

	error_t SetPassword(std::string password);
	std::string GetPassword();

	error_t SetPremiumRemaningDays(uint32_t days);
	uint32_t GetPremiumRemaningDays();

	error_t SetPremiumLastDay(time_t last_day);
	time_t GetPremiumLastDay();

	error_t SetAccountType(AccountType account_type);
	AccountType GetAccountType();

	std::tuple<Player, error_t> GetAccountPlayer(const std::string& characterName);
	std::tuple<std::vector<Player>, error_t> GetAccountPlayers();

 private:
	error_t SetID(uint32_t id);
	error_t LoadAccountDB(const std::ostringstream &query);
	std::tuple<Player, error_t> LoadAccountPlayerDB(const std::string& characterName);
	std::tuple<std::vector<Player>, error_t> LoadAccountPlayersDB();

	/**
		* @brief Register account coins transactions in database.
		*
		* @param type Type of the transaction(Add/Remove).
		* @param coins Amount of coins
		* @param coin_type Type of the coin
		* @param description Description of the transaction
		*
		* @return error_t ERROR_NO(0) Success, otherwise Fail.
		*/
	error_t RegisterCoinsTransaction(CoinTransactionType type, uint32_t coins,
		CoinType coin_type, const std::string &description);

	Database *db_;
	DatabaseTasks *db_tasks_;

	uint32_t id_;
	std::string email_;
	std::string password_;
	uint32_t premium_remaining_days_;
	time_t premium_last_day_;
	uint32_t coin_balance_;
	uint32_t tournament_coin_balance_;
	AccountType account_type_;
};

}  // namespace account

#endif  // SRC_CREATURES_PLAYERS_ACCOUNT_ACCOUNT_HPP_
