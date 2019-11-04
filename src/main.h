#pragma once
/***
Developed by Michael T. Meikle

Description:
This plugin aims to aid TeamSpeak server admins in tracking what transpires on their server further than the typical logs allow. This plugin is designed
to operate on a bot client, which will log relevant events associated with a TeamSpeak UID and store the events in a database that can be queried at a 
later date by server admins. Initially will function of a local database with plugin commands, later intended to be used via a web interface and cloud db.
***/

#include <string>
#include "teamspeak.h"
class Main
{
public:
	const std::string kPluginName = "Client Tracker";
	const std::string kPluginAuthor = "Michael Meikle";
	const std::string kPluginDescription = "Plugin to log client events to a database for later review via command or API";
	const std::string kPluginVersion = "0.0.1";

	int Initialize();
	void Shutdown();
	void ServerConnectionEvent();
	void DisplayNameChangeEvent(uint64 server_handle, anyID client_id, const char* display_name, const char* client_uid);
	void ChangeChannelEvent(uint64 server_handle, anyID client_id, uint64 old_ch_id, uint64 new_ch_id, int visibility, const char* move_message);
	void ChangeChannelEvent(uint64 server_handle, anyID client_id, uint64 old_ch_id, uint64 new_ch_id, int visibility, anyID mover_id, const char* mover_name, const char* mover_uid, const char* move_message);

	/*** Getters ***/

	/*** Setters ***/

private:

};