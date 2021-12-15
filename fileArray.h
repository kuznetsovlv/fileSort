#pragma once
#include <fstream>
#include<string>

enum Mode {CLOSE, IN, OUT, TRUNC };

class FileArray final
{
	private:
	const std::fstream _fs;
	const std::string _name;
	Mode _mode;
	bool _tmp;
	size_t _size;

	void reload();

	public:
	FileArray(const std::string&, Mode, bool);
	FileArray(const std::string&, Mode);
	FileArray(const std::string&, bool);
	FileArray(const std::string&);
	FileArray(const FileArray&) = delete;
	FileArray(const FileArray&&) = delete;

	~FileArray();

	bool add(FileArray&);
	bool empty()const;
	Mode mode()const;
	const std::string &name()const;
	int next()const;
	bool push(int)const;
	size_t size()const;
	bool switchMode(Mode);

	FileArray &operator=(FileArray&) = delete;
	FileArray &&operator=(FileArray&&) = delete;
};
