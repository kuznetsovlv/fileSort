#include <fstream>
#include <string>
#include "fileArray.h"
#include "exception.h"

FileArray::FileArray(const std::string &name, Mode mode, bool tmp):_name(name),_mode(mode),_tmp(tmp)
{
	switchMode(mode);
	reload();
}

FileArray::FileArray(const std::string &name, Mode mode):FileArray(name, mode, false)
{
}

FileArray::FileArray(const std::string &name, bool tmp):FileArray(name, CLOSE, tmp)
{
}

FileArray::FileArray(const std::string &name):FileArray(name, CLOSE, false)
{
}

FileArray::~FileArray()
{
	if(_fs.is_open())
	{
		_fs.close();
	}

	if(_tmp)
	{
		std::ifstream file(_name);
		if(file.good())
		{
			std::remove(_name.c_str());
		}
	}
}

void FileArray::reload()noexcept
{
	const Mode mode = _mode;

	_size = 0;

	if(switchMode(IN))
	{
		while(!_fs.eof())
		{
			int tmp;
			_fs >> tmp;
			++_size;
		}
	}
	switchMode(_mode);
}

bool FileArray::add(FileArray &that)
{
	that.switchMode(IN);

	while(!that.empty())
	{
		if(!push(that.next()))
		{
			return false;
		}
	}

	return true;
}

bool FileArray::empty()const noexcept
{
	return _mode == IN ? _fs.eof() : !_size;
}

Mode FileArray::mode()const noexcept
{
	return _mode;
}

const std::string &FileArray::name()const noexcept
{
	return _name;
}

int FileArray::next()
{
	switchMode(IN);

	if(empty())
	{
		EndOfFileException endOfFileException;
		throw endOfFileException;
	}

	int res;

	_fs >> res;

	return res;
}

bool FileArray::push(int value)
{
	if(_mode != TRUNC && !switchMode(OUT))
	{
		return false;
	}

	_fs << value << " ";

	return true;
}

size_t FileArray::size()const noexcept
{
	return _size;
}
bool FileArray::switchMode(Mode mode)noexcept
{
	if(mode == _mode)
	{
		return true;
	}

	if(_fs.is_open())
	{
		_fs.close();
	}

	try
	{
		switch(mode)
		{
			case IN:
				_fs.open(_name, std::ios::in);
				break;
			case OUT:
				_fs.open(_name, std::ios::out);
				break;
			case TRUNC:
				_fs.open(_name, std::ios::trunc);
				_size = 0;
		}
	}
	catch(...)
	{
		_mode = CLOSE;
		return false;
	}

	_mode = mode;
	return true;
}
