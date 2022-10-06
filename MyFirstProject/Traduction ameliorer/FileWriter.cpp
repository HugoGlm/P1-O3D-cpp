#include "FileWriter.h"

#pragma region constructor
FileWriter::FileWriter(const string& _path)
{
	path = _path;
	stream = ofstream(_path, ofstream::out | ofstream::app);
}
FileWriter::FileWriter(const FileWriter& _copy)
{
	path = _copy.path;
	stream = ofstream(_copy.path, ofstream::out | ofstream::app);
}
#pragma endregion
#pragma region methods
bool FileWriter::IsOpen() const
{
	return stream.is_open();
}
void FileWriter::Write(const string& _value)
{
	if (!IsOpen())
		return;
	stream << _value;
	stream << endl;
}
void FileWriter::Clear()
{
	Close();
	ofstream of = ofstream(path, ofstream::out | ofstream::trunc);
	of.close();
}
void FileWriter::Close()
{
	if (!IsOpen())
		return;
	stream.close();
}
#pragma endregion