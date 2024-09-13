#include <iostream>
#pragma warning (disable:4996)

class Secret
{
 char* password = nullptr;
 char* task = nullptr;
 mutable int failedLogIns = 0;

 public:
 Secret() = default;
 Secret(const char* pass, const char* task)
 {
	 size_t len = std::strlen(pass);
	 password = new char[len+1];
	 std::strcpy(password, pass);

	 len = std::strlen(task);
	 this-> task = new char[len+1];
	 std::strcpy(this->task, task);

	 failedLogIns = 0;
 }

 ~Secret()
 {
	 delete[] password;
	 delete[] task;
 }

 const char* getTask(const char* pwd) const
 {
	 if (!std::strcmp(password, pwd))
		 return task;
	 else
		 failedLogIns++;
	 return "Wrong password";
 }

 void setPassword(const char* newPassword, const char* oldPassword)
 {
	 if (!std::strcmp(password, oldPassword))
		 std::strcpy(password, newPassword);
	 else
		 failedLogIns++;
 }
 void setTask(const char* newTask, const char* passwd)
 {
	 if (!std::strcmp(password, passwd))
		 std::strcpy(task, newTask);
	 else
		 failedLogIns++;
 }

 int getLogInFails() const
 {
	 return failedLogIns;
 }

};