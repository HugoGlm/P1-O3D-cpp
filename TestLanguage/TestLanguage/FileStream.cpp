#include "FileStream.h"
#include "FileReader.h"
#include "FileWriter.h"

#pragma region constructor
FileStream::FileStream(const string& _path)
{
	writer = new FileWriter(_path);
	reader = new FileReader(_path);
}

FileStream::FileStream(const FileStream& _copy)
{
	writer = _copy.writer;
	reader = _copy.reader;
}
void FileStream::Close() const
{
	writer->Close();
	reader->Close();
}
FileWriter* FileStream::Writer() const
{
	return writer;
}
FileReader* FileStream::Reader() const
{
	return reader;
}
bool FileStream::IsValid() const
{
	return writer->IsOpen() && reader->IsOpen();
}
#pragma endregion