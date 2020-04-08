#pragma once
#include "Repository.h"

class RepoFile :
	public Repository
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	~RepoFile();
};

