#pragma once

#include <string>
#include <vector>
#include <set>

class KeyMappingFile
{
public:
	static KeyMappingFile load(const std::string& fileName);
	static KeyMappingFile fromP2k(const std::string& fileName);

	static bool checkTriggerExists(const std::string& target);
	static bool checkTargetExists(const std::string& target);

	static std::string getTriggerFromP2k(const std::string& target);
	static std::string getTargetFromP2k(const std::string& target);

	bool updateMapping(int player, const std::string& trigger, const std::set<std::string>& targets);

	bool isValid();
	void save(const std::string& fileName = "");
	void deleteFile();

	struct KeyMapping
	{
		bool triggerEquals(const std::string& names);
		std::string toTargetString();

		std::set<std::string> triggers;
		std::string			  type;
		std::string			  mode;
		std::set<std::string> targets;		
	};

	struct PlayerMapping
	{
		std::vector<KeyMapping> mappings;
	};

	std::vector<PlayerMapping> players;
	std::string path;


	class KeyName
	{
	public:
		KeyName(const std::string& k, const std::string& p2k = "", const std::string& p2kAlt = "");

		std::string key;
		std::string p2kname;
		std::string p2knameAlt;
	};

	static std::vector<KeyName> keyMap;
	static std::vector<KeyName> triggerNames;
	static std::string joinStrings(const std::set<std::string>& items);
};

class IKeyboardMapContainer
{
public:
	virtual bool hasKeyboardMapping() = 0;
	virtual KeyMappingFile getKeyboardMapping() = 0;
};
