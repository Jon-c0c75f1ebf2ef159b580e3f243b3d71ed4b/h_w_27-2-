#pragma once
#include <vector>
#include<memory>
#include <exception>
#include "Message.h"
#include "info_system.h"
#include "Hashing.h"
#include <mutex>
#include <shared_mutex>
#include "logging.h"

static shared_mutex shared_mutex_log;

using namespace std;

struct UserLoginEx : public exception
{
	const char* what() const noexcept override { return "Error: user login is busy"; }
};

class Chat
{
public:
	void startChat();
	void showLoginMenu();
	void showUserMenu();
	bool work() const { return work_; }
	shared_ptr <User> getcurrentUser() const { return currentUser_; }
	//shared_mutex _shared_mutex_log;

private:
	vector <User> userArr_;
	vector <Message> messageArr_;
	shared_ptr <User> currentUser_ = nullptr;
	bool work_ = false;

	void userLogin();
	void userRegistration();
	void showChat() const;
	void showAllUsers() const;
	void addMessage();
	void saveUsers();
	void saveMessages();
	void loadUsers();
	void loadMessages();
	static void log_entry(string sender, string to, string message);

	vector <User>& getAlluser() { return userArr_; }
	vector <Message>& getAllmessage() { return messageArr_; }
	shared_ptr <User> getUserLog(const string& login) const;
	shared_ptr <User> getUserName(const string& name) const;

	void test_contetnt();
};
