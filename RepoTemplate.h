#pragma once
#include <list>
#include <algorithm>
using namespace std;

template <class T>class RepoTemplate
{
protected:
	list<T> repo;
public:
	RepoTemplate<T>() {}
	void add(const T&);
	void removee(const T&);
	int findEl(const T&);
	int size();
	void update(const T& s, const T nou);
	list<T> getAll();
	~RepoTemplate();
};

template<class T>
void RepoTemplate<T>::add(const T& e)
{
	repo.push_back(e);
}

template<class T>
void RepoTemplate<T>::removee(const T& e)
{
	typename list<T>::iterator it;
	it = find(repo.begin(), repo.end(), e);
	if (it != repo.end())
		repo.erase(it);
}

template<class T>
int RepoTemplate<T>::findEl(const T& e)
{
	int index = 0;
	for (T crt : repo) {
		index++;
		if (crt == e) return index;
	}
	return -1;
}

template<class T>
int RepoTemplate<T>::size()
{
	return repo.size();
	return 0;
}


//template <class T>
//int RepoTemplate<T>::findCar(T e)
//{
//	list <Car>::iterator it;
//	it = find(repo.begin(), repo.end(), e);
//	if (it != repo.end())
//		return distance(repo.begin(), it);
//	return -1;
//}

template<class T>
void RepoTemplate<T>::update(const T& vechi, const T nou)
{
	replace(repo.begin(), repo.end(), vechi, nou);

}

template<class T>
list<T> RepoTemplate<T>::getAll()
{
	return repo;
	return list<T>();
}

template <class T> RepoTemplate<T>::~RepoTemplate()
{
}
